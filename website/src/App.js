import React, { Component } from 'react'
import './App.css'
import {
  LineChart, Line, XAxis, YAxis, CartesianGrid, Tooltip, Legend,
} from 'recharts'
var request = require('request')


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
  componentWillMount(){

    var options = {
      url: 'https://io.adafruit.com/api/v2/AxelParis/feeds',
      headers: {
        'X-AIO-Key': 'dd1d5b64bc9e45cc8a6180296adf57cb',
        'Content-Type': 'application/json'
      }
    };

    function callback(error, response, body) {
      if (!error && response.statusCode === 200) {
        var feeds = JSON.parse(body);
        console.log(feeds.length + " FEEDS AVAILABLE")

        feeds.forEach(function (feed) {
          console.log(feed.name, feed.key)
        })
      }
    }

    request(options, callback)
  }
  render() {
    return (
      <div>
        <div className="chart">
          <h1>Évolution de la température</h1>
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
