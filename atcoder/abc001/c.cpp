#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(),a.end()
#define ub(s,x) upper_bound(all(s),x)-s.begin()

int main(void){
    int deg,dis;
    cin>>deg>>dis;
    string dir[] = {
        "N","NNE","NE","ENE",
        "E","ESE","SE","SSE",
        "S","SSW","SW","WSW",
        "W","WNW","NW","NNW","N"
    };
    vector<int> speed = {
        25,155,335,545,
        795,1075,1385,1715,2075,
        2445,2845,3265
    };
    int power = ub(speed,dis*100/60);
    if(power == 0){
        cout<<"C 0"<<endl;
    }else{
        cout<<dir[(deg*10+1125)/2250]<<" "<<power<<endl;
    }
    return 0;
}
