#include <iostream>

int main() {
    int n;
    int ans;
    int a[200005];
    int dp[200005][2];

    std::cin >> n;
    for(int i = 1; i <= n; i++){
        std::cin >> a[i];
        dp[i][0] = dp[i][1] = 1;
    }
    for(int i = 1; i <= n; i++){
        if(a[i] > a[i-1]){
            dp[i][0] = dp[i-1][0]+1;
            dp[i][1] = dp[i-1][1]+1;
        }
        if(a[i] > a[i-2])
            dp[i][1] = std::max(dp[i][1], dp[i-2][0]+1);
    }
    for(int i = 1; i <= n; i++){
        ans = std::max(ans, dp[i][1]);
    }
    std::cout << ans;

    return 0;
}
