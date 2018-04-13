#include <bits/stdc++.h>
using namespace std;

string words[] = {"dream", "dreamer", "erase", "eraser"};

bool dfs(string &s, int index){
    if((int)s.size() == index) return true;
    for(string word : words){
        int k = word.size();
        if(s.substr(index, k) == word){
            if(dfs(s, index+k)){
                return true;
            }
        }
    }
    return false;
}

int main(void){
    string s;
    cin>>s;
    cout<<((dfs(s,0)) ? "YES" : "NO")<<endl;
    return 0;
}
