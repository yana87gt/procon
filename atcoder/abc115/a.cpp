#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    int d;
    cin >> d;
    cout << "Christmas";
    rep(i,25-d){
        cout << " Eve";
    }
    return 0;
}
