#include <iostream>

int main() {
    int building, rooms;
    long long num = 0;
    long long prev = 0;
    long long letter = 0;
    long long bcount = 0;

    std::cin >> building >> rooms;
    long long size[building];

    for (int i = 0; i < building; i++) {
        std::cin >> num;
        size[i] = num;
    }
    num = size[bcount];
    for (int j = 0; j < rooms; j++) {
        std::cin >> letter;

        while(letter>num){
            prev=num;
            num+=size[++bcount];
        }
        std::cout << bcount+1 << " " << letter-prev << "\n";
    }
    return 0;
}
