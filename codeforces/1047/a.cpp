#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin>>n;
    int a = n-2, b = 1;
    if(a % 3 == 0){
        a--;
        b = 2;
    }
    printf("%d %d 1\n",a,b);
    return 0;
}
