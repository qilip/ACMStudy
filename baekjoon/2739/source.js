const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');
const a = parseInt(input[0]);
const arr = Array.from({length: 9}, (_, i) => 1+i);
arr.map((cur) => {
  const b = a * cur;
  console.log(`${a} * ${cur} = ${b}`);
});