#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int max = 2000005;
    std::vector<int> dp(max, INT_MAX);
    std::vector<int> greedy(max, INT_MAX);
    int n;

    std::cin >> n;
    std::vector<int> coins(n);
    for(int i = 0; i < n; i++){
        std::cin >> coins[i];
    }
    std::sort(coins.begin(), coins.end());

    dp[0]=0;
    greedy[0]=0;

    //int count = 0;
    bool canon = true;

    for(int i = 1; i < coins[n-1]*2; i++){
        for(int j = 0; j < n; j++){
            if(i-coins[j] >= 0) {
                dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
                greedy[i] = greedy[i - coins[j]] + 1;
            }
        }
        if(greedy[i] != dp[i]){
            canon=false;
            break;
        }
    }

    if(canon)
        std::cout << "canonical" << "\n";
    else
        std::cout << "non-canonical" << "\n";

    return 0;
}
