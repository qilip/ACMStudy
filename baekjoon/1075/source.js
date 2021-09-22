const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');
const a = parseInt(input[0]);
const b = parseInt(input[1]);
const arr = Array.from({length: 100}, (_, i) => Math.floor(a/100)*100+i);
const ans = arr.reduce((acc, cur) => {
  if(acc !== -1) return acc;
  if(cur%b === 0) return cur%100;
  return acc;
}, -1);
console.log(String(ans).padStart(2, '0'));
