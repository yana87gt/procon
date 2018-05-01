#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)
#define all(a) a.begin(),a.end()
#define lb(s,x) lower_bound(all(s),x)-s.begin()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;
int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

bool Julian_leap(int y){
    return (y%4 == 0);
}

bool Gregorian_leap(int y){
    return (y%400 == 0)||((y%4 == 0) && (y%100!=0));
}


// julian diff
int get_diff(int Y, int M, int D){
    int y = 1582, m = 10, d = 4;
    int diff = 0;
    while(!(Y==y && M==m && D==d)){
        if(m==1 && d==1 && y < Y){
            diff += Julian_leap(y) ? 366 : 365;
            y++;
            continue;
        }
        days[2] = Julian_leap(y) ? 29 : 28;
        d++;
        if(d > days[m]){
            m++;
            d = 1;
        }
        if(m > 12){
            y++;
            m = 1;
        }
        diff++;
    }
    return diff;
}

void add_diff(int diff){
    int y = 1582, m = 10, d = 15;
    while(diff>0){
        if(m==1 && d==1 && diff > 370){
            diff -= Gregorian_leap(y) ? 366 : 365;
            y++;
            continue;
        }
        days[2] = Gregorian_leap(y) ? 29 : 28;        
        d++;
        if(d > days[m]){
            m++;
            d = 1;
        }
        if(m > 12){
            y++;
            m = 1;
        }
        diff--;
    }
    printf("%d-%02d-%02d\n",y,m,d);
}

void solve(string s){
    int year = stoi(s.substr(0,4));
    int month = stoi(s.substr(5,2));
    int date = stoi(s.substr(8,2));
    int diff = get_diff(year, month, date);
    add_diff(diff);
}


int main(void){
    string s;
    while(cin>>s) solve(s);
    return 0;
}
