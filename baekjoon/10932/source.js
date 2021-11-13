const n = require('fs').readFileSync('/dev/stdin').toString().split('\n')[0];
const cr = require('crypto').createHash('sha512').update(n).digest('hex');
console.log(cr);