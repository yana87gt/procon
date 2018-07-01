var main = function(input) {
    input = input.split('\n');
    var N = parseInt(input.shift());
    var x = 0, y = 0, t = 0;
    for(var line of input){
        var a = line.split(' ').map(x => parseInt(x));
        var nt = a[0], nx = a[1], ny = a[2];
        var d = Math.abs(x-nx) + Math.abs(y-ny);
        if(d > nt-t || (d%2 !== (nt-t)%2)){
            console.log("No");
            return;
        }
        x = nx, y = ny, t = nt;
    }
    console.log("Yes");
}
 
main(require("fs").readFileSync("/dev/stdin", "utf8").trim());