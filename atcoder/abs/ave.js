var input = require('fs').readFileSync('/dev/stdin', 'utf8').split("\n");
var N = parseInt(input[0]);
input.shift(); // 先頭削除
var scores = [];
for(var i = 0; i < N; i++){
    scores.push(input[i].split(",").map(x => parseInt(x)));
}

var M = scores[0].length; // M = 3
var sum = Array(M); // 各教科ごとの合計
sum.fill(0);
for(var i = 0; i < N; i++){
    for(var j = 0; j < M; j++){
        sum[j] += scores[i][j];
    }
}
var ave = sum.map(x => (x/N).toFixed(5));
console.log(ave.join(" "));