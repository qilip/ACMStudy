const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split(' ');
const a = parseInt(input[0]);
const b = parseInt(input[1]);
const c = parseInt(input[2]);
const arr = Array.from({length: c}, (_, i) => 1+i);
const brr = arr.reduce((acc, cur) => {
  acc.push(a*cur + b*Math.floor(cur/7));
  return acc;
}, []);
const ans = brr.some((cur, idx) => {
  if(cur >= c){
    console.log(idx+1);
  }
  return cur >= c;
});
