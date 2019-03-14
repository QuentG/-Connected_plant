import React, { Component } from 'react'
import './App.css'
import {
  LineChart, Line, XAxis, YAxis, Tooltip, Legend,
} from 'recharts'
import mqtt from 'mqtt'
import axios from 'axios'
const username = 'AxelParis'
const key      = 'dd1d5b64bc9e45cc8a6180296adf57cb'
const url      = `mqtts://${username}:${key}@io.adafruit.com`


let client  = mqtt.connect(url)

const checkConnection = () => {
  console.log(client)
  if(!client.connected){
    client = mqtt.connect(url)
  }
}

client.on('message', function (topic, message) {
  // message is Buffer
  console.log(message.toString())
  client.end()
})
client.on('connect', function () {
  client.subscribe(`${username}/feeds/onoff`)
})

class App extends Component {

  state = {
    data: [
      {
        name: 'Page A', pv: 2400, amt: 2400,
      },
      {
        name: 'Page B', pv: 1398, amt: 2210,
      },
      {
        name: 'Page C', pv: 9800, amt: 2290,
      },
      {
        name: 'Page D', pv: 3908, amt: 2000,
      },
      {
        name: 'Page E', pv: 4800, amt: 2181,
      },
      {
        name: 'Page F', pv: 3800, amt: 2500,
      },
      {
        name: 'Page G', pv: 4300, amt: 2100,
      },
    ]
  }
  constructor(){
    super()
    this.toggleOnOff = this.toggleOnOff.bind(this)
  }
  componentWillMount(){
    this.getLastOnOffValue()
  }

  getLastOnOffValue(){
    const self = this
    var options = {
      method: 'get',
      url: 'https://io.adafruit.com/api/v2/AxelParis/feeds',
      headers: {
        'X-AIO-Key': 'dd1d5b64bc9e45cc8a6180296adf57cb',
        'Content-Type': 'application/json'
      }
    }

    axios(options).then(data => {
      const feeds = data.data

      feeds.forEach(function (feed) {
        if(feed.name === "onoff"){
          const lastValue = feed.last_value
          const on = lastValue === "ON" ? true : false
          self.setState({on: on})
        }
      })
    })
  }

  toggleOnOff(){
    let data
    if(this.state.on === true){
      this.setState({on: false})
      data = {
        "value": "OFF", 
        "lat": 0,
        "lon": 0, 
        "ele": 0
      }
    }else{
      this.setState({on: true})
      data = {
        "value": "ON", 
        "lat": 0,
        "lon": 0, 
        "ele": 0
      }
    }
    
    
    checkConnection()
    client.publish(`${username}/feeds/onoff`, JSON.stringify(data))
  }
  render() {
    return (
      <div>
        <div className="chart">
          <h1>Évolution de la température</h1>
          <div className="switch-container">
                <label>
                    <input ref="switch" checked={ this.state.on } onChange={ this.toggleOnOff } className="switch" type="checkbox" />
                    <div>
                      <div></div>
                    </div>
                </label>
            </div>
          <LineChart
            width={800}
            height={300}
            data={this.state.data}
            margin={{
              top: 5, right: 30, left: 20, bottom: 5,
            }}
          >
            <XAxis dataKey="name" />
            <YAxis />
            <Tooltip />
            <Legend />
            <Line type="monotone" dataKey="pv" stroke="#00C9AA" activeDot={{ r: 8 }} />
          </LineChart>
        </div>
        <footer>Created with ❤️ by Justin Sella, Arnaud Dauguen, Quentin Gans, Axel Paris</footer>
      </div>
    );
  }
}



export default App
