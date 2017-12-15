#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define debug(x) cout<<#x<<": "<<x<<endl

const int L = -32768;
const int R = +32767;

map<int,int> imos;

int get_bound(string s,string ineq,int value){
    int pos = s.find(ineq);
    if (pos != -1) {
        int l = pos + 3;
        int r = s.find(" ",l);
        value = stoi(s.substr(l,r-l));
    }
    return value;
}

void solve(istream &ifs, ostream &ofs){
    string s;
    while(getline(ifs, s)){
        int l = get_bound(s,">=",L);
        int r = get_bound(s,"<=",R);
        if (l <= r){
            imos[l]++;
            imos[r+1]--;
        }
    }

    vector<pair<int,int>> seg;

    for(int l, i=L; i<=R; i++){
        imos[i+1] += imos[i];
        if(!imos[i-1] && imos[i]) l=i;
        if(imos[i] && !imos[i+1]) {
            seg.push_back({l,i});
        }
    }

    if(seg.size() == 0){
        ofs<<"false"<<endl;
        return;
    }

    if(seg[0].first == L && seg[0].second == R){
        ofs<<"true"<<endl;
        return;
    }

    int N = seg.size();
    vector<string> res(N);
    if(seg[0].first == L){
        res[0] = "x <= " + to_string(seg[0].second);
    }
    if(seg.back().second == R){
        res.back() = "x >= " + to_string(seg.back().first);
    }
    rep(i,N){
        if(res[i] != "") continue;
        res[i] = "x >= " + to_string(seg[i].first) + " && " + 
                 "x <= " + to_string(seg[i].second);
    }
    rep(i,N){
        ofs<<res[i];
        if(i<N-1)ofs<<" ||";
        ofs<<endl;
    }

}

int main(int args, char* argv[]){
    if(args>1){
        solve(cin, cout);
    } else {
        ifstream ifs = ifstream("hard.in");
        ofstream ofs = ofstream("hard.out");
        solve(ifs, ofs);
    }
    return 0;
}