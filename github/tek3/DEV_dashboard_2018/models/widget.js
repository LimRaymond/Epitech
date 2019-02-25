var mongoose = require('mongoose');

mongoose.connect('mongodb://mongodb/mydb', {
    useMongoClient: true
});

var Widget = module.exports = mongoose.model('Widgets', {
    userId: String,
    widgetType: String,
    params: {},
    versionKey: false
});