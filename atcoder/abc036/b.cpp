#include <bits/stdc++.h>
using namespace std;

int main(void){
    char S[51][51];
    int N;

    cin>> N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin >> S[i][j];
        }
    }

    for(int i=0;i<N;i++)
    {
        for(int j=N-1;j>=0;j--)
        {
            cout << S[j][i];
            if(j==0)cout << endl;
        }
    }

    return 0;
}
