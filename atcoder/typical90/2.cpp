    #include <bits/stdc++.h>
using namespace std;

struct IoSetup {
    IoSetup() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
} iosetup;

void dfs(string sub, int rem, int depth) {
    if (rem == 0) {
        cout << sub << endl;
        return;
    }
    if (rem > depth) dfs(sub + "(", rem-1, depth+1);
    if (depth > 0) dfs(sub + ")", rem-1, depth-1);
}

int main(void) {
    int N;
    cin >> N;
    if (N % 2 == 0) dfs("", N, 0);
    return 0;
}
