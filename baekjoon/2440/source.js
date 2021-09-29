const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');
const n = parseInt(input[0]);
const arr = Array.from({length: n}, (_, i) => '*'.repeat(n-i));
arr.map(cur => console.log(cur));
