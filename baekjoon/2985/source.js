const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split(' ');
const a = input[0];
const b = input[1];
const c = input[2];
const op = ['+','-','/','*'];
let ans;
op.map(cur => {
  const func = new Function('return '+a+cur+b);
  if(func() == parseInt(c)) ans = a+cur+b+'='+c;
  const fun2 = new Function('return '+b+cur+c);
  if(fun2() == parseInt(a)) ans = a+'='+b+cur+c;
});
console.log(ans);
