import React, { Component } from 'react'
import './App.css'
import {
  LineChart, Line, XAxis, YAxis, Tooltip, Legend,
} from 'recharts'
import moment from 'moment'
import mqtt from 'mqtt'
import axios from 'axios'
const username = 'AxelParis'
const key      = 'dd1d5b64bc9e45cc8a6180296adf57cb'
const url      = `mqtts://${username}:${key}@io.adafruit.com`


let client  = mqtt.connect(url)

const checkConnection = () => {
  if(!client.connected){
    client = mqtt.connect(url)
  }
}

client.on('message', function (topic, message) {
  // message is Buffer
  client.end()
})
client.on('connect', function () {
  client.subscribe(`${username}/feeds/onoff`)
})

class App extends Component {

  state = {
    data: []
  }
  constructor(){
    super()
    this.toggleOnOff = this.toggleOnOff.bind(this)
  }
  componentWillMount(){
    this.getLastOnOffValue()
    this.getTemp()
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


  getTemp(){
    const self = this
    var options = {
      method: 'get',
      url: 'https://io.adafruit.com/api/v2/AxelParis/feeds/temperature/data',
      headers: {
        'X-AIO-Key': 'dd1d5b64bc9e45cc8a6180296adf57cb',
        'Content-Type': 'application/json'
      }
    }

    axios(options).then(data => {
      const values = data.data.reverse()

      let finalData = []
      let n = 0

      values.forEach(value => {
        n++
        finalData.push({name: moment(value.created_at).format('hh:mm:ss'), value: value.value, date: moment(value.created_at).format('MMM Do YY h:mm:ss') })
      })

      
      this.setState({data: finalData})
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
            data={this.state.data.slice()}
            margin={{
              top: 5, right: 30, left: 20, bottom: 5,
            }}
          >
            <XAxis dataKey="name" />
            <YAxis />
            <Tooltip />
            <Legend />
            <Line type="monotone" dataKey="value" name="Température (C°)" stroke="#00C9AA" activeDot={{ r: 8 }} />
          </LineChart>
        </div>
        <footer>Created with ❤️ by Justin Sella, Arnaud Dauguen, Quentin Gans, Axel Paris</footer>
      </div>
    );
  }
}



export default App
