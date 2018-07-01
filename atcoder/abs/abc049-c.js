var input = require("fs").readFileSync('/dev/stdin','utf8');
var word_list = ["eraser", "erase", "dreamer", "dream"];
for(var word of word_list){
    input = input.split(word).join(' ');
}
console.log((input.trim() == "") ? "YES" : "NO");