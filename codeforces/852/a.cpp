#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int digit_sum(int x){
    int res = 0;
    while(x>0){
        res += x%10;
        x /= 10;
    }
    return res;
}

void print(string &s, const vector<bool> plus){
    int n = s.size();
    rep(i,n){
        cout<<s[i]<<(plus[i]&&(i<n-1) ? "+" : "");
    }
    cout<<endl;
}

int main(void){
    int n;
    string s;
    cin>>n>>s;

    int first = 0;
    for(char c : s) first += c-'0';

    vector<bool> plus(n,true);
    rep(i,n-1){
        if(digit_sum(digit_sum(first)) <= 9) break;
        if(s[i]-'0' > 0){
            first += (s[i]-'0')*9;
            plus[i] = false;
            i++;
        }
    }
    assert(digit_sum(digit_sum(first)) <= 9);
    print(s,plus);

    s = to_string(first);
    print(s,vector<bool>(s.size(),true));

    s = to_string(digit_sum(first));
    print(s,vector<bool>(s.size(),true));

    return 0;
}
