#include <bits/stdc++.h>
using namespace std;

int main(void){
    int L,X,Y,S,D;
    cin>>L>>X>>Y>>S>>D;
    double right=(S<=D ? D-S : L+D-S);
    double left=(S>=D ? S-D : L+S-D);
    if(X>=Y)printf("%.10f\n",right/(Y+X));
    else printf("%.10f\n",min(right/(Y+X),left/(Y-X)));

    return 0;
}
