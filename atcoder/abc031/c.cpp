#include <iostream>
using namespace std;

/* 高橋直大さんが選んだところから左側に青木さんが丸を付けるときの最大値を返し、
    そのときの高橋さんの最大値も記録 */
int left_max(int a[],int i,int *amax_taka){
    int j,tmp,amax=-50,aoki=0,taka=a[i];

    for(j=i-1;j>=0;j--){
        tmp=taka; taka=aoki; aoki=tmp;
        taka += a[j];
        if(amax<=aoki){
            amax = aoki;
            *amax_taka = taka;
        }
    }
    return amax;
}

/* 高橋直大さんが選んだところから右側に青木さんが丸を付けるときの最大値があるか調べ、
    あればそのときの高橋さんの最大値を記録 */
void right_max(int a[],int i,int N,int amax,int *amax_taka){
    int j,aoki=0,taka=a[i];
    for(j=i+1;j<N;j++){
        if((j-i)%2==0)taka+=a[j];
        else aoki+=a[j];
        if(amax<aoki){
            amax=aoki;
            *amax_taka=taka;
        }
    }
}

int main(void){
    int N,i,a[51],tmp,tmax=-50,amax_taka=-50;
    cin >> N;

    for(i=0;i<N;i++)cin >> a[i];
    //高橋さん選ぶ
    for(i=0;i<N;i++){
        amax_taka=-50;
        right_max(a,i,N,left_max(a,i,&amax_taka),&amax_taka);
        //高橋さん最大値更新
        if(tmax<amax_taka)tmax=amax_taka;
    }
    cout << tmax << endl;
    return 0;
}
