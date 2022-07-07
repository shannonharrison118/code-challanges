#include <iostream>
#include <algorithm>

int main() {
    int t;
    long long int n, x;

    std::cin >> t;
    while(t--){
        int count=0;
        long long int sum=0;
        std::cin >> n >> x;
        double arr[n];

        for(int i = 0; i < n; i++){
            std::cin >> arr[i];
        }
        std::sort(arr, arr+n, std::greater<int> ());
        for(int i = 0; i < n; i++){
            sum+=arr[i];
            if(sum < (i+1)*x)
                break;
            else
                count++;
        }
        std::cout << count << "\n";
    }
    return 0;
}
