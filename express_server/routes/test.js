var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/test', function(req, res) {
  res.end({
    title: 'HI!',
    message: 'Hello World!!!',
  });
});

module.exports = router;