#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define fi first
#define se second
string repstr(string s,int n){
    string res;
    rep(i,n)res+=s;
    return res;
}

string solve(){
    int N,R,O,Y,G,B,V;
    cin>>N>>R>>O>>Y>>G>>B>>V;
    string YV=repstr("YV",V);
    string RG=repstr("RG",G);
    string BO=repstr("BO",O);
    if(V==Y && V+Y==N)return YV;
    if(G==R && G+R==N)return RG;
    if(O==B && O+B==N)return BO;
    Y-=V, R-=G, B-=O;
    if((Y<=0&&V) || (R<=0&&G) || (B<=0&&O) || Y>R+B || R>B+Y || B>Y+R)
        return "IMPOSSIBLE";
    pair<int,string> yrb[]={{Y,"Y"},{R,"R"},{B,"B"}};
    sort(yrb,yrb+3);
    pair<int,string> s=yrb[0],m=yrb[1],l=yrb[2];
    int sm_l=s.fi+m.fi-l.fi;
    string res=repstr(s.se+m.se,sm_l/2);
    s.fi-=sm_l/2; m.fi-=sm_l/2; l.fi-=s.fi;
    res+=repstr(s.se+l.se,s.fi);
    res+=repstr(m.se+l.se,l.fi);
    if(sm_l&1)res+=m.se;
    if(V)res.replace((int)res.find("Y"),0,YV);
    if(G)res.replace((int)res.find("R"),0,RG);
    if(O)res.replace((int)res.find("B"),0,BO);
    return res;
}

int main(){
    int T;
    cin>>T;
    rep(t,T) {
        printf("Case #%d: ",t+1);
        cout<<solve()<<endl;
    }
    return 0;
}
