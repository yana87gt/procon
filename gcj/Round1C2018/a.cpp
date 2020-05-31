#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

int N,L;
set<string> st;
vector<map<char,bool>> used;

string dfs(int k, string sub){
    if(k == L){
        if(st.count(sub)){
            return "-";
        }else{
            return sub;
        }
    }
    for(auto itr : used[k]){
        char alpha = itr.first;
        string res = dfs(k+1, sub+alpha);
        if(res != "-"){
            return res;
        }
    }
    return "-";
}

string solve(){
    cin>>N>>L;
    vector<string> word(N);
    st.clear();
    used.clear();
    used.resize(L);
    rep(i,N){
        cin>>word[i];
        st.insert(word[i]);
        rep(j,L){
            used[j][word[i][j]] = true;
        }
    }
    return dfs(0,"");
}

int main(void){
    int T;
    cin>>T;
    rep(_,T){
        printf("Case #%d: ",_+1);
        cout<<solve()<<endl;
    }
    return 0;
}
