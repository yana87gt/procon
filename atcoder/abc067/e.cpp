#include <iostream>
using namespace std;

bool q(long n){
    cout<<"? "<<n<<endl;
    char a;
    cin>>a;
    return a=='Y';
}

int main(){
    int d=1e9;
    if(q(d)){
        while(d>1 && q(d-1)) d/=10;
        cout<<"! "<<d<<endl;
    }else{
        while(d/=10,!q(d));
        long l=d,r=d*10,m;
        while(l+1<r){
            m=(l+r)/2;
            if(q(m*10)) r=m;
            else l=m; 
        }
        cout<<"! "<<r<<endl;
    }
}
