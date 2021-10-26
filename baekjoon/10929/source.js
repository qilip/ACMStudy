const fs = require('fs');
const c = require('crypto');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');
const n = input[0];
const cr = c.createHash('sha224').update(n).digest('hex');
console.log(cr);