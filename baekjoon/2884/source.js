const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split(' ');
const h = parseInt(input[0]);
const m = parseInt(input[1]);
const d = new Date(1999, 2, 2, h, m-45);
console.log(d.getHours(), d.getMinutes())