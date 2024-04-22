const db = require('../database');
const bcrypt = require('bcryptjs');


const card = {
  getAllCards(callback) {
    return db.query('SELECT * FROM card', callback);
  },

  addCard(newCard, callback) {
    bcrypt.hash(newCard.pin, 10, (err, hashedPin) => {
      if (err) {
        return callback(err);
      }
      
      return db.query(
        'INSERT INTO card (pin, cardNumber) VALUES (?, ?)',
        [hashedPin, newCard.cardNumber], 
        callback
      );
    });
  },
  getByCardNumber(cardNumber, callback) {
    
    db.query('SELECT id_card FROM card WHERE cardNumber = ?', [cardNumber], (error, results) => {
      if (error) {
        return callback(error, null);
      }
      if (results && results.length > 0) {
        const id = results[0].id_card;
        return callback(null, id);
      } else {
        return callback(null, null);
      }
    });
  },

  getOneCard(id_card, callback) {
    return db.query('SELECT * FROM card WHERE id_card = ?', [id_card], callback);
  },

  deleteCard(id_card, callback) {
    return db.query('DELETE FROM card WHERE id_card = ?', [id_card], callback);
  },

  login(id_card, callback) {
    return db.query('SELECT pin FROM card WHERE id_card = ?', [id_card], callback);
  },

  cardTransactions(id_card, callback) {
    return db.query(
      'SELECT transaction_date, amount FROM transactions WHERE card_id = ?',
      [id_card],
      callback
    );
  }
};

module.exports = card;
