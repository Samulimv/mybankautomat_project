const express=require('express');
const router=express.Router();
const card=require('../models/card_model');
const bcrypt=require('bcryptjs');

router.post('/',function(request, response){
    if(request.body.cardNumber && request.body.pin){
        card.login(request.body.cardNumber, function(err,result){
            if(err){
                console.log(err.errno);
                response.json(err.errno);
            }
            else{
                if(result.length >0){
                    bcrypt.compare(request.body.pin, result[0].pin, function(err, compareResult){
                        if(compareResult){
                            console.log('Kirjautuminen ok');
                        }
                        else {
                            console.log("Väärä salasana");
                            response.send(false);
                        }
                    })
                }
                else {
                    console.log("tunnusta ei ole");
                    response.send(false);
                }

            }
        });
    }
    else {
        console.log("Tunnus tai salasana puuttuu")
        response.send(false);
    }



module.exports=router;
