#include <iostream>
#include <vector>
#include <map>

int main() {
    int n;

    std::cin >> n;
    while(n--){
        int size;
        std::cin >> size;

        int sum = 0, count = 0;
        std::vector<int> seq(size);
        std::map<int, int> mp;

        for(int i = 0; i < size; i++){
            std::cin >> seq[i];
        }
        for(int i = 0; i < size; i++){
            sum+=seq[i];
            if(sum==47)
                count++;
            if(mp.find(sum-47) != mp.end())
                count += mp[sum-47];
            mp[sum]++;
        }
       std::cout << count << '\n';
    }
    return 0;
}
