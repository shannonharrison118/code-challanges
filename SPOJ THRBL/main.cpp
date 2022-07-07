#include <iostream>
#include <vector>

int main() {
    int intv, balls;
    int l, r;

    std::cin >> intv >> balls;
    int cities[intv+2];

    for(int i = 0; i < intv; i++){
        std::cin >> cities[i];
    }

    int res = 0;
    for(int i = 0; i < balls; i++){
        std::cin >> l;
        l--;
        std::cin >> r;
        r--;

        int hills = cities[l];
        bool x = true;
        for(int j = l+1; j < r; j++){
            if(cities[j] > hills){
                x = false;
                break;
            }
        }
        if(x == true)
            res += 1;
        else
            res += 0;
    }
    std::cout << res  << '\n';

    return 0;
}
