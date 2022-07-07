#include <iostream>

int main() {
    int t;
    int a[200005];
    std::cin >> t;
    while(t--) {
        int ans = 0;
        int n;

        std::cin >> n;
        for(int i = 1; i <= n; i++){
            std::cin >> a[i];
        }
        for(int i = n; i > 0; i--){
            if(i+a[i] <= n)
                a[i] = a[i] + a[i+a[i]];
            if(ans < a[i])
                ans = a[i];
        }
        std::cout << ans << "\n";
    }
    return 0;
}
