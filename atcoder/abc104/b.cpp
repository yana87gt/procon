#include <bits/stdc++.h>

bool check(std::string &s) {
    int N = s.size();
    int cnt = 0;
    if (s[0] != 'A') return false;
    for (int i = 1; i < N; i++) {
        if (i >= 2 && i < N - 1 && s[i] == 'C') {
            cnt++;
        } else if (!std::islower(s[i])) {
            return false;
        }
    }
    return cnt == 1;
}

int main(void) {
    std::string s;
    std::cin >> s;
    std::cout << (check(s) ? "AC" : "WA") << std::endl;
    return 0;
}