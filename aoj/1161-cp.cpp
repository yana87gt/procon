#include <bits/stdc++.h>
using namespace std;
#define rep2(i,m,n) for(int i=m;i<n;i++)
#define rep(i,n) rep2(i,0,n)
#define each(it,c) for(auto it=c.begin();it!=c.end();++it)
int N,l;
bool used[10];
bool MSdigit[26];
vector<pair<int,bool>> v;
int pow10(int n){
    return n ? pow10(n-1)*10 : 1;
}
 
bool islarger(pair<int,int> a,pair<int,int> b){
    return abs(a.first)>abs(b.first);
}
 
int f(int n,int s){
    if(n==l)return !s;
    int res=0;
    rep(i,10)if(!used[i]&&(i||!v[n].second)){
        int x=s+v[n].first*i;
        if(x>0){
            rep2(j,n+1,l)if(v[j].first<0)x+=v[j].first*9;
            if(x>0)continue;
        }else if(x<0){
            rep2(j,n+1,l)if(v[j].first>0)x+=v[j].first*9;
            if(x<0)continue;
        }
        used[i]=true;
        res+=f(n+1,s+v[n].first*i);
        used[i]=false;
    }
    return res;
}
 
int main(){
    while(cin>>N | N){
        map<char,int> M;
        rep1(y,N){
            string s;
            cin>>s;
            if((int)s.size()>1)MSdigit[s[0]-'A']=true;
            reverse(s.begin(), s.end());
            rep(x,(int)s.size()) M[s[x]] += pow(10,x)*(y==N ? -1 :1);
        }
        v.clear();
        each(it,M) v.push_back(pair<int,bool>((*it).second,MSdigit[(*it).first]));
        sort(v.begin(),v.end(),islarger);
        l=v.size();
        fill(used,used+10,false);
        cout<<f(0,0)<<endl;
    }

    return 0;
}