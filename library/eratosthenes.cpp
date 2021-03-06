///
/// for vscode snippet
/// prefix: lib-eratosthenes
///

#define SIZE 1000010
vector<bool> prime(SIZE,true);
void init(){
    prime[0] = prime[1] = false;
    rep(i,SIZE){
        if(!prime[i])continue;
        for(int j=i*2;j<SIZE;j+=i){
            prime[j] = false;
        }
    }
}

