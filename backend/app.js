var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const jwt = require('jsonwebtoken');


var userRouter = require('./routes/user');
var accountRouter = require('./routes/account');
var card_accountRouter = require('./routes/card_account');
var cardRouter = require('./routes/card');
var transactionRouter = require('./routes/transactions');
var loginRouter = require('./routes/login')
var creditRouter = require('./routes/credit_transfer');
var debitRouter = require('./routes/debit_transfer');
var app = express();

function authenticateToken(req, res, next) {
    const authHeader = req.headers['authorization']
    const token = authHeader && authHeader.split(' ')[1]
  
    console.log("token = "+token);
    if (token == null) return res.sendStatus(401)
  
    jwt.verify(token, process.env.MY_TOKEN, function(err, user) {
  
      if (err) return res.sendStatus(403)

      req.user = user
  
      next()
    })
  }

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/login', loginRouter);

app.use('/user', userRouter);
app.use('/transactions',transactionRouter);
app.use('/account', accountRouter);
app.use('/card_account', card_accountRouter);
app.use('/card', cardRouter);
app.use('/credit',creditRouter);
app.use('/debit', debitRouter);

module.exports = app;
