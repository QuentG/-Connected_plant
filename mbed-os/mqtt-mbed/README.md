# MQTT mbed

This library is based on the [Eclipse Paho](http://www.eclipse.org/paho/) project.

The file MQTTNetwork.h is used to wrap the Networks api of Mbed OS to the generic MQTT api defined by Eclipse.

Bellow is a quick example on how to instantiate a MQTT client on Mbed OS:

```c++
#include "easy-connect.h"
#include "MQTTNetwork.h"
#include "MQTTmbed.h"
#include "MQTTClient.h"

int main()
{
    NetworkInterface *net = NetworkInterface::get_default_instance();
    if (!net) {
        printf("Error! No network inteface found.\n");
        return 0;
    }

    MQTTNetwork mqttNetwork(net);

    MQTT::Client<MQTTNetwork, Countdown> client(mqttNetwork);
    
    const char* hostname = "m2m.eclipse.org";
    int port = 1883;
    printf("Connecting to %s:%d\r\n", hostname, port);
    int rc = mqttNetwork.connect(hostname, port);
    if (rc != 0)
        printf("Connection failed, rc from TCP connect is %d\r\n", rc);
```
