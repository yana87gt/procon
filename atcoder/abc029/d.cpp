#include<iostream>

using namespace std;
int D[11]={0,1,10,100,1000,10000,100000,
            1000000,10000000,100000000,1000000000};

int count1(int n){
    if(n==0) return 0;
    int k = n, digits = 0;
    while(digits++,k/=10);
    if(digits==1) return 1;
    int head = n/D[digits];
    int tail = n%D[digits];
    return (digits-1)*D[digits-1]*head
            + (head>1 ? D[digits] : tail+1)
            + count1(tail) ;
}

int main(void){
    int n;
    cin >> n;
    cout << count1(n) << endl;
    return 0;
}
