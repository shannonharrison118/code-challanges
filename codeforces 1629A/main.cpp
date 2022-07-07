#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int cases;
    int n;
    int ram;
    std::vector<int> a(n);
    std::vector<int> b(n);
    std::cin >> cases;

    while(cases--) {
        std::cin >> n >> ram;
        /*std::vector<int> a(n);
        std::vector<int> b(n);*/
        for (int i = 0; i < n; i++)
            std::cin >> a[i];
        for (int i = 0; i < n; i++)
            std::cin >> b[i];

        std::vector<std::pair<int, int>> total;
        for (int i = 0; i < n; i++) {
            total.push_back(std::make_pair(a[i], b[i]));
        }
        sort(total.begin(), total.end());
        for (int i = 0; i < total.size(); i++) {
            if (total[i].first <= ram)
                ram += total[i].second;
            else
                break;
        }
        std::cout << ram << "\n";
    }
    return 0;
}
