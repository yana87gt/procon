#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define all(s) s.begin(),s.end()
#define first x
#define first y
typedef long long ll;

struct Point{
    int x,y,id,linkx,linky;
};
vector<Point> p;
bool compx(Point a,Point b) {return (a.x==b.x ? a.y<b.y : a.x<b.x);}
bool compy(Point a,Point b) {return (a.y==b.y ? a.x<b.x : a.y<b.y);}
bool compid(Point a,Point b) {return a.id<b.id;}


enum state{ LEFT,RIGHT,BOTTOM,TOP };
typedef pair< pair<int,int>,state > EP;//EndPoint

bool intersection(){


}


ll solve(int n){
    if(n%2==1)return -1;
    vector<EP> ep;
    sort(all(p),compx);
    rep(i,n){
        if(p[i].x!=p[i+1].x)return -1;
        p[i].linkx=p[i+1].id;
        p[i+1].linkx=p[i].id;
        ep.push_back(EP(p[i].x,p[i].y, p[i].y<?: ));
        i++;
    }

    sort(all(p),compy);
    rep(i,n){
        if(p[i].y!=p[i+1].y)return -1;
        p[i].linky=p[i+1].id;
        p[i+1].linky=p[i].id;
        i++;
    }



    sort(all(p),compid);
    ll res=0;
    int src=0,dst;
    rep(i,n){
        if(i%2==0){
            dst=p[src].linkx;
            res+=abs(p[src].y-p[dst].y);
        }else{
            dst=p[src].linky;
            res+=abs(p[src].x-p[dst].x);
        }
        src=dst;
        if(i<n-1 && 0==start)return -1;
    }
    return res;
}


int main(void){
    int D,n;
    cin>>D;
    rep(_,D){
        cin>>n;
        p.resize(n);        
        rep(i,n){
            scanf("%d%d",&p[i].x,&p[i].y);
            p[i].id=i;
        }
        cout<<solve(n)<<endl;
        p.clear();
    }

    return 0;
}
