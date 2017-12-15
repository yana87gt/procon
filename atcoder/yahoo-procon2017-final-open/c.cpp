#include <bits/stdc++.h>
using namespace std;
#define R 320
// 平方分割
int N,M,Q;
int a[R*R],block[R],cnt[R][R*R];

int countM(int l,int r,int d){
    int sum = 0;
    for(int i=l;i<r;++i){
        cnt[i/R][a[i]]--;
        a[i] = (a[i]+d)%M;
        cnt[i/R][a[i]]++;
        if((a[i]+block[i/R])%M==0) sum++;
    }
    return sum;
}

int main(void){
    cin>>N>>M>>Q;
    for(int i=0;i<N;++i){
        cin>>a[i];
        a[i] %= M;
        cnt[i/R][a[i]]++;
    }
    while(Q--){
        int l,r,d,sum = 0;
        cin>>l>>r>>d;
        --l;
        if(l/R == r/R){
            sum = countM(l,r,d);
        }else{
            sum += countM(l,l-l%R+R,d);
            for(int j=l/R+1;j<r/R;++j){
                block[j] = (block[j]+d)%M;
                sum += cnt[j][(M-block[j])%M];
            }
            sum += countM(r-r%R,r,d); 
        }
        cout<<sum<<endl;
    }
}
