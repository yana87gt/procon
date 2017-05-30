#include<iostream>
using namespace std;

int main(void){
    int N,K,x,i,j,k;
    long long fact[21]={1};
    bool used[21]={};

    cin >> N;
    cin >> K;

    /* 20以上は諦め */
    if(N>20){
        cout<<endl;
        return 0;
    }
    for(i=1;i<=N;i++){
        fact[i]=fact[i-1]*i;
    }
    x = fact[N]/K;

    for(i=N-1;x>0;i--){
        k = 1;
        j = x/fact[i];
        x = x%fact[i];
        if(x==0)j--;
        while(used[k])k++;
        while(j--)while(used[++k]);
        used[k] = true;
        cout<<k<<endl;
    }
    for(k=N;k>0;k--){
        if(!used[k])cout<<k<<endl;
    }

    return 0;
}
