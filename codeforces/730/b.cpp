#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)

string ask(int x,int y){
    cout<<"? "<<x+1<<" "<<y+1<<endl;
    string res;
    cin>>res;
    return res;
}

int main(void){
    int T;
    cin>>T;
    rep(_,T){
        int n;
        cin>>n;
        vector<int> maxs,mins;
        rep(i,n/2){
            int x = i*2, y = i*2+1;
            string res = ask(x,y);
            if(res == ">"){
                swap(x,y);
            }
            // a[x] < a[y]
            mins.push_back(x);
            maxs.push_back(y);
        }
        if(n&1){
            mins.push_back(n-1);
            maxs.push_back(n-1);
        }

        int a = mins.size(), min_pos = mins[a-1];
        rep(i,a-1){
            string res = ask(mins[i],min_pos);
            if(res == "<") min_pos = mins[i];
        }

        int b = maxs.size(), max_pos = maxs[b-1];
        rep(i,b-1){
            string res = ask(maxs[i],max_pos);
            if(res == ">") max_pos = maxs[i];
        }
        cout<<"! "<<min_pos+1<<" "<<max_pos+1<<endl;
    }
    return 0;
}
