#include <iostream>

int main() {
    int n;
    int k, m = 0;
    int p[2005] = {};

    std::cin >> n;
    for(int i = 1; i <= n; i++){
        std::cin >> p[i];
    }

    for(int i = 1; i <= n; i++){
        k = 0;
        for(int j = i; j != -1; j=p[j])
            k++;
        if(k > m)
            m=k;
    }

    std::cout << m;
    return 0;
}
