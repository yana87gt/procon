#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    long long x;
    cin>>n>>x;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    long long res = 0;
    if(a[0] > x){
        res = a[0]-x;
        a[0] = x;
    }

    for(int i = 1; i < n; i++){
        if(a[i-1] + a[i] > x){
            res += a[i-1] + a[i] - x;
            a[i] = x-a[i-1];
        }
    }

    cout<<res<<endl;
    return 0;
}
