const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');
const n = parseInt(input[0]);
if(n>89) console.log('A');
else if(n>79) console.log('B');
else if(n>69) console.log('C');
else if(n>59) console.log('D');
else console.log('F');
