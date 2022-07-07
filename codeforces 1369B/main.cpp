#include <iostream>
#include <string>

int main() {
    int cases;
    int n;
    std::string s = "";

    std::cin >> cases;
    while(cases--){
        std::cin >> n;
        std::cin >> s;

        //everything between first 1 and last 0 can be optimally removed
        int first = s.find_first_of('1');
        int last = s.find_last_of('0');

        if(first != std::string::npos && last != std::string::npos) {
            if (last > first)
                s.erase(first, last - first);
        }

        std::cout << s << "\n";
    }
    return 0;
}
