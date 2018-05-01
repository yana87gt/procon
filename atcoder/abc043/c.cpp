#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    int res = 1e9;
    for(int k = -100; k<=100; k++){
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += (a[i]-k)*(a[i]-k);
        }
        res = min(res, sum);
    }
    cout<<res<<endl;
    return 0;
}
