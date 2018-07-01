var input = "++-++--++";
var count = 0;
for (var c of input){
    if(c === '+') count++;
    else count--;
}
console.log(count);