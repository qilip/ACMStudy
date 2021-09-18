const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split(' ');
const a = parseInt(input[0].split("").reverse().join(""));
const b = parseInt(input[1].split("").reverse().join(""));
console.log( a > b ? a : b );
