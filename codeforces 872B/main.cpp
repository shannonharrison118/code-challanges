#include <iostream>
#include <algorithm>


int main() {
    int n, k;

    std::cin >> n >> k;
    int a[n];

    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    if(k==1)
        std::cout << *std::min_element(a, a+n);
    else if (k == 2)
        std::cout << std::max(a[0], a[n-1]);
    else
        std::cout << *std::max_element(a, a+n);
    return 0;
}
