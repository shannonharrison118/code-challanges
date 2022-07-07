#include <iostream>
#include<vector>

int main() {
    int laptops = 0;
    int price;
    int qual;
    bool verd = false;

    std::cin >> laptops;
    std::vector<std::vector<int>> all;

    while(laptops--){
        std::cin >> price >> qual;
        std::vector<int> specs;
        specs.push_back(price);
        specs.push_back(qual);
        all.push_back(specs);
    }
    for(int j = 0; j < all.size(); j++){
        if(all[j][0] < all[j][1])
            verd = true;
    }
    if (verd)
        std::cout << "Happy Alex";
    else
        std::cout << "Poor Alex";
    return 0;
}
