const express = require('express');
const router = express.Router();
const debit =require('../models/debit_transfer_model');


router.post('/', 
function(request, response) {
  debit.debit(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});

module.exports=router;