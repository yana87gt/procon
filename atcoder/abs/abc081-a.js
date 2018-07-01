var input = require("fs").readFileSync('/dev/stdin','utf8');
var sum = 0;
for(var x of input){
    if(x == "1") sum++;
}
console.log(sum);