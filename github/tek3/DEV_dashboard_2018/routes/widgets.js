const OpenWeatherMapHelper = require("openweathermap-node");
const request = require('request');
const axios = require('axios');
var fetchVideoInfo = require('youtube-info');
var async = require('async');

const helper = new OpenWeatherMapHelper({
    APPID: "1bf8fafe66882bb705ce1b6efb3c0cae",
    units: "metric"
});

module.exports = {
    Temperature: function (params) {
        return new Promise((resolve, reject) => {
            helper.getCurrentWeatherByCityName(params.city, (err, currentWeather) => {
                if (err) {
                    let res = {title: "Error", content: "City not found"}
                    resolve(res);
                }
                else {
                    let string = JSON.stringify(currentWeather);
                    let objectValue = JSON.parse(string);
                    let temperature = objectValue['main'].temp;
                    let res = {
                        title: "Météo à " + params.city,
                        content: Math.round(temperature) + "°C"
                    };
                    resolve(res);
                }
            });
        });
    },
    Humidity: function(params) {
      return new Promise((resolve, reject) => {
          helper.getCurrentWeatherByCityName(params.city, (err, currentWeather) => {
              if (err) {
                  let res = {title: "Error", content: "City not found"}
                  resolve(res);
              }
              else {
                  let string = JSON.stringify(currentWeather);
                  let objectValue = JSON.parse(string);
                  let humidity = objectValue['main'].humidity;
                  let res = {
                      title: "Humidité à " + params.city,
                      content: Math.round(humidity) + "% d'humidité"
                  };
                  resolve(res);
              }
          });
      });
    },
    Wind: function(params) {
        return new Promise((resolve, reject) => {
            helper.getCurrentWeatherByCityName(params.city, (err, currentWeather) => {
                if (err) {
                    let res = {title: "Error", content: "City not found"}
                    resolve(res);
                }
                else {
                    let string = JSON.stringify(currentWeather);
                    let objectValue = JSON.parse(string);
                    let windSpeed = objectValue['wind'].speed;
                    let windDeg = objectValue['wind'].deg;
                    let res = {
                        title: "Vent à " + params.city,
                        content: "Speed : " + windSpeed + ", " + "Degree : " + windDeg
                    };
                    resolve(res);
                }
            });
        });
    },
    Views: function(params) {
        return new Promise((resolve, reject) => {
            fetchVideoInfo(params.key)
                .then(function (videoInfo) {
                let string = JSON.stringify(videoInfo);
                let objectValue = JSON.parse(string);
                let viewsCount = objectValue['views'];
                let videoTitle = objectValue['title'];
                let res = {
                    title: videoTitle,
                    content: viewsCount + " views"
                };
                resolve(res);
            });
        });
    },
    LikeDislike: function(params) {
        return new Promise((resolve, reject) => {
            fetchVideoInfo(params.key)
                .then(function (videoInfo) {
                    let string = JSON.stringify(videoInfo);
                    let objectValue = JSON.parse(string);
                    let dislikeCount = objectValue['dislikeCount'];
                    let likeCount = objectValue['likeCount'];
                    let videoTitle = objectValue['title'];
                    let res = {
                        title: videoTitle,
                        content: likeCount + " like & " + dislikeCount + " dislike"
                    };
                    resolve(res);
                });
        });
    },
    Summoner: function(params) {
        return new Promise((resolve, reject) => {
            var data = {};
            var api_key = 'RGAPI-3ed6a41a-46be-47a3-bcc6-2a92de20fde4';
            var summonerName = params.username;
            var URL = 'https://euw1.api.riotgames.com/lol/summoner/v3/summoners/by-name/' + summonerName + '?api_key=' + api_key;
            async.waterfall([
                function(callback) {
                    request(URL, function(err, response, body) {
                        if(!err && response.statusCode == 200) {
                            let objectValue = JSON.parse(body);
                            let idSummoner = objectValue['id'];
                            callback(null, data);
                            var URL2 = 'https://euw1.api.riotgames.com/lol/league/v3/positions/by-summoner/'
                                + idSummoner + '?api_key=' + api_key;
                            request(URL2, function(err, response, body) {
                                if (!err && response.statusCode == 200) {
                                    let objectValue2 = JSON.parse(body);
                                    let leagueName = objectValue2[0]['leagueName'];
                                    let tier = objectValue2[0]['tier'];
                                    let rank = objectValue2[0]['rank'];
                                    let leaguePoints = objectValue2[0]['leaguePoints'];
                                    let wins = objectValue2[0]['wins'];
                                    let losses = objectValue2[0]['losses'];
                                    let res = {
                                      title: "Ranked Solo/Duo : " + summonerName,
                                      content: leagueName + " " +
                                          tier + " " + rank + " " + "lp :" + " " + leaguePoints +
                                          " " + "wins :" + " " + wins + " " + "losses :" + " " + losses
                                    };
                                    resolve(res);
                                } else {
                                    let res = {title: "Error", content: "Summoner Id Not found"}
                                    resolve(res);
                                }
                            })
                        } else {
                            let res = {title: "Error", content: "Summoner name not found or specials characters not handled"}
                            resolve(res);
                        }
                    });

                }
            ])
        });
    }
};