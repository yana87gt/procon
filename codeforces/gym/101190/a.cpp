#include <bits/stdc++.h>
using namespace std;
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define _repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define _rep(i,n) _repl(i,0,n)
#define rep(...) GET_MACRO(__VA_ARGS__, _repl, _rep)(__VA_ARGS__)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
void _dbg(string){cout<<endl;}
template<class H,class... T> void _dbg(string s,H h,T... t){int l=s.find(',');cout<<s.substr(0,l)<<" = "<<h<<", ";_dbg(s.substr(l+1),t...);}
template<class T,class U> ostream& operator<<(ostream &o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream &o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define INF 1120000000
#define long long long // for codeforces

vector<string> split(const string &str){
  vector<string> v;
  stringstream ss(str);
  string buf;
  while(getline(ss, buf, ' ')) v.pb(buf);
  return v;
}

bool isCap(string &s){
  if(s.size()<2) return false;
  if(s[0]<'A' || s[0]>'Z') return false;
  rep(i,1,s.size()) if(s[i]<'a' || s[i]>'z') return false;
  return true;
}

void sol(ostream &ofs, string &s, int l, int r){
  auto v = split(s.substr(l,r-l));
  int n = v.size();
  rep(i, n){
    int d = 0;
    while(i+d < n && isCap(v[i+d])) d++;
    if(d<=1) ofs << v[i];
    else {
      rep(k,d) ofs << v[i+k][0];
      ofs << " (";
      rep(k,d) ofs << v[i+k] << " )"[k==d-1];
      i += d-1;
    }
    if(i<n-1)ofs << " ";
  }
}

void solve(istream &ifs, ostream &ofs){
  string s;
  while(getline(ifs, s)){
    int p = 0;
    int n = s.size();
    rep(i,n){
      if(s[i]=='.' || s[i]==','){
        sol(ofs, s, p, i);
        p = i+1;
        ofs << s[i];
      }
      else if(i+1 < n && s[i]==' ' && s[i+1]==' '){
        sol(ofs, s, p, i);
        p = i+1;
        ofs << s[i];
      }
    }
    if(p != s.size()-1) sol(ofs, s, p, n);
    ofs << '\n';
  }
}

int main(int args, char* argv[]){
  if(args>1){
    solve(cin, cout);
  } else {
    ifstream ifs = ifstream("abbreviation.in");
    ofstream ofs = ofstream("abbreviation.out");
    solve(ifs, ofs);
  }
  return 0;
}