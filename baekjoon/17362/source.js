const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');
const n = parseInt(input[0]);
console.log(n%8==0 ? 2 : n%8 > 5 ? 10-n%8 : n%8);
