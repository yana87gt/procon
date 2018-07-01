#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define INF 1e9
typedef long long ll;

ll make_rand(){
    std::random_device rnd;     // 非決定的な乱数生成器でシード生成機を生成
    std::mt19937 mt(rnd()); //  メルセンヌツイスターの32ビット版、引数は初期シード
    // std::uniform_real_distribution<> rand100(0, 99);     // [0, 99] 範囲の一様乱数
    std::uniform_int_distribution<> rand100(0, 1000);
    return rand100(mt);
}

void binary(){
    int N = 300;
    ll W = 1<<29;
    cout<<N<<" "<<W<<endl;
    rep(i,N){
        W *= 9.3/10.0;
        cout<<W<<" "<<W<<endl;
    }
}

int main(void){
    binary();
    // int N,W = INF;
    // cin>>N;
    // cout<<N<<" "<<W<<endl;
    // rep(i,N){
    //     cout<<make_rand()<<" "<<make_rand()<<endl;
    // }

    return 0;
}
