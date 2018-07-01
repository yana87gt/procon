var main = function(input) {
    st = new Set();
    var array = input.split('\n').slice(1);
    for(var x of array){
        st.add(parseInt(x));
    }
    console.log(st.size);
}
 
main(require("fs").readFileSync("/dev/stdin", "utf8").trim());