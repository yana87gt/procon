var input = require("fs").readFileSync('/dev/stdin','utf8').split(' ');
var N = input[0];
var A = input[1];
var B = input[2];
var sum = 0;
for(var i = 1; i <= N; i++){
    var str = i.toString();
    var digit_sum = 0;
    for(var c of str){
        digit_sum += parseInt(c);
    }
    if(A<=digit_sum && digit_sum<=B){
        sum += i;
    }
}
console.log(sum);