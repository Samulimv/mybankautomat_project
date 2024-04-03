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

  updateCard(id_card, updateData, callback) {
    bcrypt.hash(updateData.pin, 10, (err, hashedPin) => {
      if (err) {
        return callback(err);
      }
      return db.query(
        'UPDATE card SET pin = ?, cardNumber = ? WHERE id_card = ?',
        [hashedPin, updateData.cardNumber, id_card], 
        callback
      );
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
