/*
 * Copyright (c) 2017, CATIE, All Rights Reserved
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "mbed.h"

namespace {
#define PERIOD_MS 500
}

static DigitalOut led1(LED1);
static AnalogIn an(ADC_IN1);
static I2C i2c(I2C1_SDA, I2C1_SCL);

char cmmmd[2];

uint8_t lm75_adress = 0x48 << 1;

#include "mbed.h"
#include "zest-radio-atzbrf233.h"
#include "MQTTNetwork.h"
#include "MQTTmbed.h"
#include "MQTTClient.h"

/* Printf the message received and its configuration */
void messageArrived(MQTT::MessageData& md)
{
    MQTT::Message &message = md.message;
    printf("Message arrived: qos %d, retained %d, dup %d, packetid %d\r\n", message.qos, message.retained, message.dup, message.id);
    printf("Payload %.*s\r\n", message.payloadlen, (char*)message.payload);
}

// main() runs in its own thread in the OS
// (note the calls to Thread::wait below for delays)
int main()
{
	// Network interface
	NetworkInterface *net;

	int result;

	// Add the border router DNS to the DNS table
	nsapi_addr_t new_dns = {
		NSAPI_IPv6,
		{ 0xfd, 0x9f, 0x59, 0x0a, 0xb1, 0x58, 0, 0, 0, 0, 0, 0, 0, 0, 0x00, 0x01 }
	};
	nsapi_dns_add_server(new_dns);

	printf("Starting MQTT demo\n");

	// Get default Network interface (6LowPAN)
	net = NetworkInterface::get_default_instance();
	if (!net) {
		printf("Error! No network inteface found.\n");
		return 0;
	}

	// Connect 6LowPAN interface
	result = net->connect();
	if (result != 0) {
		printf("Error! net->connect() returned: %d\n", result);
		return result;
	}

	// Build the socket that will be used for MQTT
	MQTTNetwork mqttNetwork(net);

	// Declare a MQTT Client
	MQTT::Client<MQTTNetwork, Countdown> client(mqttNetwork);

	// Connect the socket to the MQTT Broker
	const char* username = 'AxelParis';
	const char* key = 'temperature';
	const char* hostname = "mqtts://" + username + ":" + key +"@io.adafruit.com";
	const char* topic_temperature = "AxelParis/feeds/temperature";
	const char* hostnameipv6 = "fd9f:590a:b158:ffff:ffff::c0a8:0103";
	uint16_t port = 1883;
	printf("Connecting to %s:%d\r\n", hostname, port);
	int rc = mqttNetwork.connect(hostname, port);
	if (rc != 0)
		printf("rc from TCP connect is %d\r\n", rc);

	// Connect the MQTT Client
	MQTTPacket_connectData data = MQTTPacket_connectData_initializer;
	data.MQTTVersion = 3;
	data.clientID.cstring = "mbed-sample";
	//data.username.cstring = "testuser";
	//data.password.cstring = "testpassword";
	if ((rc = client.connect(data)) != 0)
		printf("rc from MQTT connect is %d\r\n", rc);

	// Subscribe to the same topic_temperature we will publish in
	if ((rc = client.subscribe(topic_temperature, MQTT::QOS2, messageArrived)) != 0)
		printf("rc from MQTT subscribe is %d\r\n", rc);

	// Send a message with QoS 0
	MQTT::Message message;

	// QoS 0
	char buf[10];

	message.qos = MQTT::QOS0;
	message.retained = false;
	message.dup = false;
	message.payload = (void*)buf;
	message.payloadlen = strlen(buf)+1;

    while (true)
    {
        cmmmd[0] = 0x00;
        i2c.write(lm75_adress, cmmmd, 1);
        i2c.read(lm75_adress, cmmmd, 2);

        float temperature = ((cmmmd[0] << 8 | cmmmd[1]) >> 7) * 0.5;
        printf("La temperature est de : %f \n", temperature);
        // Calcul % humidity
        float measure_percent = an.read()*100.0/1;
        printf("Percentage humidity: %f\n", measure_percent);
        sprintf(buf, (char*)(measure_percent));

        rc = client.publish(topic_temperature, message);

        wait_ms(PERIOD_MS);
    }

    // Disconnect client and socket
	client.disconnect();
	mqttNetwork.disconnect();

	// Bring down the 6LowPAN interface
	net->disconnect();
	printf("Done\n");
}
