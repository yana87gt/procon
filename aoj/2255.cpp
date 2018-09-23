#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define all(a) (a).begin(),(a).end()

bool is_op(char c){
    return c=='+' || c=='-' || c=='*' || c=='/';
}

int operate(int &e1,int &e2,char &op){
    if(op == '+') return e1+e2;
    if(op == '-') return e1-e2;
    if(op == '*') return e1*e2;
    if(op == '/') return e1/e2;
    assert(false);
}

set<int> calc(vector<set<int>> Es, vector<char> &ops, vector<int> &perm){
    int n = perm.size();
    if(n == 0){
        return Es[0];
    }
    vector<bool> done(n);
    rep(i,n){
        int p = perm[i];
        set<int> E;
        char op = ops[p];
        for(int e1 : Es[p]){
            for(int e2 : Es[p+1]){
                if(op == '/' && e2 == 0) continue;
                E.insert(operate(e1,e2,op));
            }
        }
        done[p] = true;
        Es[p] = E;
        Es[p+1] = E;
        int l = p-1, r = p+1;
        while(l>=0 && done[l]){
            Es[l] = E;
            l--;
        }
        while(r<n && done[r]){
            Es[r+1] = E;
            r++;
        }
    }
    return Es[0];
}

set<int> all_check(vector<set<int>> &Es, vector<char> &ops){
    int n = ops.size();
    vector<int> perm(n);
    rep(i,n){
        perm[i] = i;
    }

    set<int> res;
    do{
        set<int> tmp = calc(Es,ops,perm);
        for(int t : tmp){
            res.insert(t);
        }
    }while(next_permutation(all(perm)));
    return res;
}


set<int> eval(string &s, int &i){
    vector<set<int>> Es;
    vector<char> ops;
    while(1){
        if(isdigit(s[i])){
            set<int> res;
            int num = 0;
            while(isdigit(s[i])){
                num = num*10 + s[i]-'0';
                i++;
            }
            res.insert(num);
            Es.push_back(res);
        }else if(s[i] == '('){
            i++; // (
            Es.push_back(eval(s,i));
            i++; // )
        }

        if(i == (int)s.size()) break;
        if(is_op(s[i])){
            ops.push_back(s[i]);
            i++;
        }else{
            break;
        }
    }
    return all_check(Es,ops);
}

int main(){
    string s;
    while(cin>>s, s!="#"){
        int index = 0;
        cout<<eval(s, index).size()<<endl;
    }
    return 0;
}