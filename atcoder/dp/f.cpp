#include <bits/stdc++.h>
using namespace std;

template<typename T>
T lcs(T &a, T &b) {
    if (b.size() > a.size()) swap(a,b);
    int I = a.size();
    int J = b.size();
    vector<vector<int>> dp(I+1, vector<int>(J+1));
    for (int i = 1; i <= I; i++) {
        for (int j = 1; j <= J; j++) {
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    int cost = dp[I][J];
    T result;
    for (int i = I; i >= 1; i--) {
        for (int j = J; j >= 1; j--) {
            if(dp[i-1][j-1] == cost-1 && a[i-1] == b[j-1]) {
                result.push_back(a[i-1]);
                cost--;
                break;
            }
        }
    }
    reverse(result.begin(), result.end());
    return result;
}


int main(void){
    string a,b;
    cin >> a >> b;
    cout << lcs(a,b) << endl;
    return 0;
}
