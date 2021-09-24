const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');
const n = parseInt(input[0]);
for(let i=1;i<=n;i++){
  const ans = input[i].split('').reduce((acc, cur) => {
    if(cur === 'O') acc.a += acc.b++;
    else acc.b = 1;
    return acc;
  }, {a:0, b:1});
  console.log(ans.a);
}
