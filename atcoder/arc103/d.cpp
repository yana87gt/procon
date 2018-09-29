#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

typedef complex<double> Point;

vector<Point> e = {{+1,0}, {0,+1}, {-1,0}, {0,-1}};
string dir[4] = {"R","U","L","D"};

string command(Point cur, Point goal,int arm){
    if(arm == 0){
        if(abs(cur - goal) < 1e-4) return "";
        else arm = 1;
    }

    double min_dist = 2e9;
    int d;
    Point min_nxt;
    rep(i,4){
        Point nxt = cur + e[i]*(double)arm;
        if (min_dist > abs(goal - nxt)){
            min_dist = abs(goal - nxt);
            min_nxt = nxt;
            d = i;
        }
    }
    return dir[d] + command(min_nxt, goal, arm/2);
}

int main(void){
    int n;
    cin>>n;
    vector<Point> ps(n);
    set<int> even_odd;
    rep(i,n){
        int x,y;
        cin>>x>>y;
        ps[i] = Point(x,y);
        even_odd.insert((abs(x+y))&1);
    }
    if(even_odd.size()!=1){
        cout<<-1<<endl;
        return 0;
    }

    vector<string> commands(n);
    rep(i,n){
        commands[i] = command(Point(0,0), ps[i], 1<<30);
    }
    int m = commands[0].size();
    cout<<m<<endl;
    int arm = 1<<30;
    rep(i,m){
        cout<<arm<<(i == m-1 ? "\n": " ");
        arm = arm==1 ? 1 : arm/2;
    }
    rep(i,n) cout<<commands[i]<<endl;

    return 0;
}
