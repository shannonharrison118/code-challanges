#include <iostream>
#include <map>

int main() {
    long long int sum=0;
    long long int clients;
    long long int num;
    std::map<int, int> pair;

    std::cin >> clients;
    for(int i = 0; i < clients; i++){
        std::cin >> num;
        sum += pair[-num];
        pair[num]++;
    }
    std::cout << sum;
    return 0;
}
