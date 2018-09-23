#include <bits/stdc++.h>
using namespace std;

bool solve(int q){
    if(q==1) return false;
    int rq = sqrt(q);
    for(int p = 2; p <= rq; p++){
        if(q%p==0){
            while(q%p==0){
                q /= p;
            }
            return q==1;
        }
    }
    return true;
}

int main(void){
    int q;
    cin>>q;
    cout<<((solve(q)) ? "yes" : "no")<<endl;
    return 0;
}
