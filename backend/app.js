var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');


var userRouter = require('./routes/user');
var accountRouter = require('./routes/account');
var card_accountRouter = require('./routes/card_account');
var cardRouter = require('./routes/card');

var app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));


app.use('/user', userRouter);

app.use('/account', accountRouter);
app.use('/card_account', card_accountRouter);
app.use('/card', cardRouter);

module.exports = app;
