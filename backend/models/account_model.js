const db=require('../database');

const account={
    getAll(callback){
        return db.query('SELECT * FROM account', callback);
 
    },
    getById: function(id, callback){
        return db.query('SELECT * FROM account WHERE id_account=?', [id], callback);
   
    },
    add: function(account, callback){
        return db.query('INSERT INTO account (accountNumber,balance) values(?,?)', [account.accountNumber,account.balance], callback);

    },
    delete: function(id, callback){
        return db.query('DELETE FROM account WHERE id_account=?', [id], callback);
        
    },
    update: function(id, account, callback){
        return db.query('UPDATE account SET accountNumber=?,balance=? WHERE id_account=?', [account.accountNumber, account.balance, id], callback);

    }

};

module.exports=account;

