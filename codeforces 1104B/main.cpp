#include <iostream>

int main() {
    std::string input;
    int count = 0;

    std::cin >> input;

    for (int i = 1; i < input.length(); i++) {
        if (input[i] == input[i - 1] && input.size()) {
            count++;
            input.erase(i-1, 2);
            i -= 2;
        }
    }

    if (count % 2 == 0)
        std::cout << "No";
    else
        std::cout << "Yes";

    return 0;
}
