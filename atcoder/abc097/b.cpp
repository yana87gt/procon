#include <bits/stdc++.h>
using namespace std;

bool ok[1010] = {};

void init(){
    ok[1] = true;
    for(int b = 2; b <= 40; b++){
        int x = b;
        while(true){
            x *= b;
            if(x>1000) break;
            ok[x] = true;
        }
    }
}

int main(void){
    int x;
    cin>>x;
    init();
    for(int i = x; i >= 1; i--){
        if(ok[i]){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}
