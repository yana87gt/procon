#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()

struct Line{
    int start,end,pos;
    bool operator<(const Line& b) const{
        return pos < b.pos;
    }
};

int main(){
    vector<Line> vx,vy;
    int n,cnt=0;
    cin>>n;
    rep(i,n){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if(x1!=x2)vx.push_back({min(x1,x2),max(x1,x2),y1}); 
        else      vy.push_back({min(y1,y2),max(y1,y2),x1});      
    }
    sort(all(vy));
    for(auto _:vx){
        Line s = {0,0,_.start};
        Line e = {0,0,_.end+1};
        int l = lb(vy,s);
        int r = lb(vy,e);
        for(int i=l;i<r;++i){
            if(vy[i].start<=_.pos && _.pos<=vy[i].end)cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}