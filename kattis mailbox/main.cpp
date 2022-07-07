#include <iostream>
#include <algorithm>

int main() {
    int n, p;
    int port[500001];
    int dp[500001];
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> port[i];
        dp[i] = 50001;
    }
    for (int i = 0; i < n; i++) {
        *std::lower_bound(dp, dp + n, port[i]) = port[i];
    }
    std::cout << std::lower_bound(dp, dp + n, 50001) - dp << "\n";

    return 0;
}
