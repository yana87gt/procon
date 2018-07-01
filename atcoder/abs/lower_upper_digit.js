function isLower(c){
    return 'a' <= c && c <= 'z';
}
function isUpper(c){
    return 'A' <= c && c <= 'Z';
}

function isDigit(c){
    return '0' <= c && c <= '9';
}

var input = "'Momoiro Clover' was formed in 2008.";
var lower_count = 0;
var upper_count = 0;
var digit_count = 0;
for(var c of input){
    if(isLower(c)) lower_count++;
    if(isUpper(c)) upper_count++;
    if(isDigit(c)) digit_count++;
}

console.log(lower_count);
console.log(upper_count);
console.log(digit_count);

/*

小文字の個数
大文字の個数
数字の個数
をそれぞれ１行ずつ出力せよ

入力例

'Momoiro Clover' was formed in 2008.

出力例

22
2
4

*/
