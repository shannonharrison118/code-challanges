#include <iostream>
#include <map>

int main() {
    std::map<int,int> val;
    int n;
    int ans = 0;
    int max;
    std::cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
        val[arr[i]] = val[arr[i]-1]+1;
        if(val[arr[i]] > ans){
            max = i;
        }
        ans = std::max(ans, val[arr[i]]);
    }
    std::cout << ans << "\n";
    int j = 1;
    for(int i = 0; i <= max; i++){
        if(arr[i]+ans-j == arr[max]){
            std::cout << i+1 << " ";
            j++;
        }
    }
    return 0;
}
