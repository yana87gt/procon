#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define rep1(i,n) for(int i=1;i<=int(n);++i)

bool solve(){
    int Y,X,H,V;
    cin>>Y>>X>>H>>V;
    vector<string> s(Y);
    vector<int> sumY(Y),sumX(X);
    rep(y,Y){
        cin>>s[y];
    }
    rep(y,Y)rep(x,X){
        if(s[y][x] == '@'){
            sumY[y]++;
            sumX[x]++;
        }
    }
    rep(y,Y-1){
        sumY[y+1] += sumY[y];
    }
    rep(x,X-1){
        sumX[x+1] += sumX[x];
    }
    if(sumY.back()%(H+1) || sumX.back()%(V+1)) return false;

    vector<int> posY={0},posX={0};
    rep1(h,H){
        int multi = (sumY.back()/(H+1))*h;
        bool ok = false;
        rep(y,Y){
            if(sumY[y] == multi){
                posY.push_back(y+1);
                ok = true;
                break;
            }
        }
        if(!ok) return false;
    }

    rep1(v,V){
        int multi = (sumX.back()/(V+1))*v;
        bool ok = false;
        rep(x,X){
            if(sumX[x] == multi){
                posX.push_back(x+1);
                ok = true;
                break;
            }
        }
        if(!ok) return false;
    }

    int block_sum = sumY.back()/((H+1)*(V+1));
    rep(h,H){
        rep(v,V){
            int cnt = 0;
            for(int x = posX[h]; x < posX[h+1]; x++){
                for(int y = posY[v]; y < posY[v+1]; y++){
                    if(s[y][x] == '@'){
                        cnt++;
                    }
                }
            }
            if(block_sum != cnt) return false;
        }
    }


    return true;
}

int main(void){
    int T;
    cin>>T;
    rep(_,T){
        printf("Case #%d: ",_+1);
        cout<<((solve()) ? "POSSIBLE" : "IMPOSSIBLE")<<endl;
    }
    return 0;
}
