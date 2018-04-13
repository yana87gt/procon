#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int main(void){
    string s;
    cin>>s;
    int n = s.size();
    if (n == 26) {
        if(s == "zyxwvutsrqponmlkjihgfedcba"){
            cout<<-1<<endl;
            return 0;
        }
        
        for(int i = 24; i>=0; i--){
            string next = s;
            next_permutation(next.begin()+i, next.end());
            if(s[i] == next[i]){
                cout<<string(next.begin(), next.begin()+i+2)<<endl;
                return 0;
            }
        }
        cout<<char(s[0] + 1)<<endl;

    } else {
        rep(i,26){
            bool used = false;
            for(char c : s){
                if(c == 'a'+i){
                    used = true;
                }
            }
            if(!used){
                s.push_back(char('a'+i));
                cout<<s<<endl;
                return 0;
            }
        }
    }
    return 0;
}
