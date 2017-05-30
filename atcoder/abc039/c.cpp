#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
using namespace std;


int main(void){
    char before,now;
    string key[]={"Fa","Fa","Mi","Re","Re","Do","Do","Si","La","La","So","So","Fa","Fa","Mi"};
    int w1,w2,i=1;
    cin>>before;
    while(i++){
        cin>>now;
        if(now==before){
            w1=i;
            break;
        }
        before=now;
    }
    while(i++){
        cin>>now;
        if(now==before){
            w2=i;
            break;
        }
        before=now;
    }
    while(now=getchar(),now!='\n');
    if(w2-w1==5)w1+=5;

    cout<<key[w1%12]<<endl;

    return 0;
}
