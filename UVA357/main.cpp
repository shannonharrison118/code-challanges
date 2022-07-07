#include <iostream>

int main() {
    long long int combos [30001] = {0};
    int coins[] = {1,5,10,25,50};

    combos[0] = 1;
    for(int i = 0; i < 5; ++i){
        for(int k = coins[i]; k < 30001; ++k){
            combos[k] += combos[k-coins[i]];
        }
    }
    int change;
    while(std::cin >> change){
        if(combos[change] == 1)
            std::cout << "There is only 1 way to produce " << change << " cents change.\n";
        else
            std::cout << "There are " << combos[change] << " ways to produce " << change << " cents change.\n";
    }
    return 0;
}
