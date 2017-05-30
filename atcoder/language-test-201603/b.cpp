#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    char c;
    int cnt[4]={};
    cin>>N;
    while(N--)
    {
        cin >> c;
        cnt[c-'1']++;
    }
    sort(cnt,cnt+4);
    cout<<cnt[3]<<" "<<cnt[0]<<endl;
    return 0;
}

