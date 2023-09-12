#include <bits/stdc++.h>

int main(void) {
    int R;
    std::cin >> R;
    std::cout << (R < 1200 ? "ABC" : R < 2800 ? "ARC" : "AGC") << std::endl;
    return 0;
}
