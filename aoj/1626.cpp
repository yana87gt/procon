#include <bits/stdc++.h>
using namespace std;

int main(){
    int b;
    while(cin>>b, b){
        for(int n = sqrt(b*2); n>=1; n--){
            int a = (b*2/n - n + 1)/2;
            if(a>0 && b*2==(a + a+n-1)*n){
                cout<<a<<" "<<n<<endl;
                break;
            }
        }
    }
}