#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]){
    int n,i,v = 0,ans=0,d[100001];
    string s;
    cin >> s;
    for(i=s.size()-1,n=0;i>=0;i--){
        if(s[i] == 'M'){
            d[n++]=v;
        }else if(s[i] == '+') v++;
        else v--;
    }
    sort(d,d+n);
    n--;
    for(i=0;i<=n/2;i++)ans += d[n-i] - d[i];
    cout << ans << endl;
    return 0;
}
