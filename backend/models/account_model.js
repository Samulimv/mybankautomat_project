const db=require('../database');

const account={
    getAllAccount(callback){
        return db.query("SELECT * FROM account", callback);

    }

}

module.exports=account;