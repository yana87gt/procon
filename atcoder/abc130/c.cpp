#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long w,h,x,y;
    cin >> w >> h >> x >> y;
    printf("%.1f %d\n", w*h/2.0, ((w == x*2 && h == y*2) ? 1 : 0));
    return 0;
}
