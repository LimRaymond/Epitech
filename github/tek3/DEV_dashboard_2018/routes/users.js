const express = require('express');
const router = express.Router();
const passport = require('passport');
var LocalStrategy = require('passport-local').Strategy;

var User = require('../models/user');

router.get('/register', function (req, res) {
    res.render('register');
});

router.get('/login', function (req, res) {
    res.render('login');
});

router.post('/register', function (req, res) {
    var name = req.body.name;
    var username = req.body.username;
    var password = req.body.password;
    var password2 = req.body.password2;

    req.checkBody('name', 'Name is required').notEmpty();
    req.checkBody('username', 'Username is required').notEmpty();
    req.checkBody('password', 'Password is required').notEmpty();
    req.checkBody('password2', 'Passwords do not match').equals(req.body.password);

    var errors = req.validationErrors();
    console.log("ici");
    if (errors) {
        console.log("error")
        res.render('register', {
            errors: errors
        });
    } else {
        console.log("la");
        var newUser = new User({
            name: name,
            username: username,
            password: password
        });

        User.getUserByUsername(username, function (err, user) {
           if (err)
               throw err;
           if (user) {
               req.flash('error_msg', 'Username already taken');
               res.redirect('/users/register');
               console.log('user already taken');
           } else {
               User.createUser(newUser, function (err, user) {
                   if (err)
                       throw err;
                   console.log(user);
               });
               req.flash('success_msg', 'You are registered and can now login');
               res.redirect('/users/login');
           }
        });
    }
});

passport.use(new LocalStrategy(
    function (username, password, done) {
        User.getUserByUsername(username, function (err, user) {
            if (err)
                throw err;
            if (!user) {
                return done(null, false, {message: 'Unknown User'});
            }
            User.comparePassword(password, user.password, function (err, isMatch) {
                if (err)
                    throw err;
                if (isMatch) {
                    return done(null, user);
                } else {
                    return done(null, false, {message: 'Invalid password'});
                }
            });
        });
    }));

passport.serializeUser(function (user, done) {
    done(null, user.id);
});

passport.deserializeUser(function (id, done) {
    User.findById(id, function (err, user) {
        done(err, user);
    });
});

router.post(
    '/login',
    passport.authenticate(
        'local',
        {
            successRedirect: '/',
            failureRedirect: '/users/login',
            failureFlash: true
        }),
    function (req, res) {
        res.redirect('/');
    });

router.get('/logout', function (req, res) {
    req.logout();
    req.flash('success_msg', 'You are logged out');
    res.redirect('/users/login');
});

module.exports = router;