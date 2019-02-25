module.exports = {
    services: [
        {
            name: "Weather",
            widgets: [
                {
                    name: "Temperature",
                    description: "Affichage de la temperature pour une ville",
                    params: [
                        {
                            name: "city",
                            type: "string"
                        }
                    ]
                },
                {
                    name: "Humidity",
                    description: "Affichage de l'humidité pour une ville",
                    params: [
                        {
                            name: "city",
                            type: "string"
                        }
                    ]
                },
                {
                    name: "Wind",
                    description: "Affichage des informations sur les vents pour une ville",
                    params: [
                        {
                            name: "city",
                            type: "string"
                        }
                    ]
                }
            ]
        },
        {
            name: "Youtube",
            widgets: [
                {
                    name: "Views",
                    description: "Affichage des vues sur une vidéo",
                    params: [
                        {
                            name: "key",
                            type: "string"
                        }
                    ]
                },
                {
                    name: "LikeDislike",
                    description: "Affichage des likes et dislikes sur une vidéo",
                    params: [
                        {
                            name: "key",
                            type: "string"
                        }
                    ]
                }
            ]
        },
        {
            name: "League of Legends",
            widgets: [
                {
                    name: "Summoner",
                    description: "Affichage des infos sur un invocateur",
                    params: [
                        {
                            name: "username",
                            type: "string"
                        }
                    ]
                }
            ]
        }
    ]
};
