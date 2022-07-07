#include <iostream>

int main() {
    int n, m;
    int t, u;
    int ans;
    int a[105], b[105] = {};
    int x[105][105] = {};

    std::cin >> n >> m;
    for(int i = 1; i <= m; i++){
        std::cin >> t >> u;
        a[t]++;
        a[u]++;
        x[t][u]=1;
        x[u][t]=1;
        b[t]=a[t];
        b[u]=a[u];
    }
    for(int i=1; i <= n; i++){
        int k=0;
        for(int j=1; j <= n; j++)
            if (a[j]==1){
                k=1;
                b[j]=0;
                for(int l=1; l <= n; l++)
                    if(x[j][l]==1)
                        b[l]=b[l]-1;
            }
        if(k==1)
            ans=ans+1;
        for(int l=1; l <= n; l++)
            a[l]=b[l];
    }
    std::cout << ans << "\n";
    return 0;
}
