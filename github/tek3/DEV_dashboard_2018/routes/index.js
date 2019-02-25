const express = require("express");
const router = express.Router();
const widgets = require("./about");
var widgetArray = require("./widgets");
var User = require("./users");
var WidgetSchema = require("../models/widget");
var services = require("./services");
var userId;

router.get("/", ensureAuthenticated, function(req, res) {
  WidgetSchema.find({ userId: userId }, async function(err, data) {
    var result = [];
    var idInstance = [];
    for (var i = 0; i < data.length; i++) {
      result.push(widgetArray[data[i].widgetType](data[i].params));
      idInstance.push(data[i]._id);
    }
    try {
      idInstance = await Promise.all(idInstance);
      result = await Promise.all(result);
    } catch (err) {
      throw err;
    }
    res.render("index", {
      widgets: widgets,
      widgetsResult: result,
      idInstance: idInstance
    });
  });
});

router.get("/addWidgets", function(req, res) {
  res.redirect("/");
});

router.post("/addWidgets", function(req, res) {
  var params = {};
  for (var i = 1; i < Object.keys(req.body).length; i++) {
    var key = Object.keys(req.body)[i];
    params[key] = req.body[key];
  }
  var Widget = new WidgetSchema({
    userId: userId,
    widgetType: req.body.widgetType,
    params: params
  });
  Widget.save(function(err) {
    if (err) throw err;
  });
  res.redirect("/");
});

router.get("/deleteWidgets", function(req, res) {});

router.post("/deleteWidgets", function(req, res) {
  let idInstance = req.body.idInstance;
  WidgetSchema.remove({ _id: idInstance }, function(err) {
    if (err) throw err;
  });
  res.redirect("/");
});

router.get("/modifyWidgets", function(req, res) {});

router.post("/modifyWidgets", function(req, res) {
    let idInstance = req.body.idInstance2;
    console.log(req.body);
    WidgetSchema.findOne({ _id: idInstance}, function(err, data) {
        console.log(data);
        for (let param in data.params)
            data.params[param] = req.body.newParameter;
        WidgetSchema.update({_id: idInstance}, {$set:{params:data.params}}, function(err, data) {
            if(err) throw err;
        });
        console.log(data);
    });
    res.redirect("/");
});

router.get("/about.json", function(req, res) {
  services.client.host = req.connection.remoteAddress;
  services.server.current_time = Date.now() / 1000;
  res.json(services);
});

router.post("/about.json", function(req, res) {
  console.log(req.body);
});

function ensureAuthenticated(req, res, next) {
  if (req.isAuthenticated()) {
    userId = req.session.userId = req.user._id;
    return next();
  } else {
    req.flash("error_msg", "You are not logged in");
    res.redirect("/users/login");
  }
}

module.exports = router;
