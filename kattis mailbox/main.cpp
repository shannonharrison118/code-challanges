#include <iostream>

int main() {
    int n, k, m;
    int dp[15][105][105] = {0};

    for(int l=1;l<=10;l++)
        for(int j=1;j<=100;j++)
            for(int i= j;i>=1;i--)
            {
                if(i==j){
                    dp[l][i][j]=i;
                    continue;
                }
                if(l==1){
                    dp[l][i][j]=(i+j)*(j-i+1)/2;
                    continue;
                }
                int min=5050;
                int max;
                for(int t=i;t<j;t++)
                {
                    if(dp[l][t+1][j]>dp[l-1][i][t-1])
                        max=dp[l][t+1][j]+t;
                    else
                        max=dp[l-1][i][t-1]+t;
                    if(min > max)
                        min = max;
                }
                dp[l][i][j]=min;
            }

    std::cin >> n;
    while(n--){
        std::cin >> k >> m;
        std::cout << dp[k][1][m] << "\n";
    }
    return 0;
}
