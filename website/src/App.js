import React, { Component } from 'react'
import './App.css'
var request = require('request')


class App extends Component {
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
      <div className="App">
      </div>
    );
  }
}

export default App
