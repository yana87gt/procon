var main = function(input) {
    input = input.split(' ').map(x => parseInt(x));
    var N = input[0];
    var Y = input[1];
    for(var x = 0; x <= N; x++){
        for(var y = 0; y <= N-x; y++){
            var z = N - x - y;
            if(10000*x + 5000*y + 1000*z === Y){
                console.log(x+' '+y+' '+z);
                return;
            }
        }
    }
    console.log('-1 -1 -1');
}
 
main(require("fs").readFileSync("/dev/stdin", "utf8").trim());