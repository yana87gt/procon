#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
double EPS = 1e-15;

int main(void){
    int N,i,j,j90,j180;
    ll cnt1=0,cnt2=0,cnt3=0;//鋭角・直角・鈍角
    cin>>N;
    int *x = new int[N];
    int *y = new int[N];
    double *t = new double[2*N];
    for(i=0;i<N;i++)cin>>x[i]>>y[i];
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(i==j) t[j] = -4; //-pi以下(sortしたときにt[0]にくる)
            else t[j] = atan2(y[j]-y[i],x[j]-x[i]);
        }
        sort(t,t+N);

        /*2周分用意*/
        for(j=1;j<N;j++){
            t[j+N-1] = t[j]+2.0*M_PI;
        }

        /*しゃくとり法*/
        for(j=j90=j180=1;j<N;j++){
            while(t[j90]<t[j]+M_PI_2-EPS)j90++;
            if(fabs(t[j90]-t[j]-M_PI_2)<EPS){
                cnt2++;
                j90++;
            }
            while(t[j180]<t[j]+M_PI)j180++;
            cnt3 += j180-j90;
        }
    }
    cnt1 = (ll)N*(N-1)*(N-2)/6 - cnt2 - cnt3;
    cout<<cnt1<<' '<<cnt2<<' '<<cnt3<<endl;

    return 0;
}
