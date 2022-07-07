#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main() {
    int n, m , k;
    std::vector<double> plot;
    std::vector<double> rad;
    int x;
    int count= 0;
    std::cin >> n >> m >> k;

    for(int i = 0; i < n; i++){
        std::cin >> x;
        plot.push_back(x);
    }
    for(int i = 0; i < m; i++){
        std::cin >>x;
        rad.push_back(x);
    }
    for(int i = 0; i < k; i++){
        std::cin >> x;
        double r = (double)sqrt((double)2*pow((double)x / 2, 2));
        rad.push_back(r);
    }
    sort(plot.begin(), plot.end());
    sort(rad.begin(), rad.end());

    for(int i = 0; i < m+k; i++){
        for(int j = 0; j < n; j++){
            if(rad[i] < plot[j]){
                plot[j]=-1;
                count++;
                break;
            }
        }
    }

    std::cout << count << "\n";
    return 0;
}
