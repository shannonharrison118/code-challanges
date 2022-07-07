#include <iostream>
using namespace std;

int main() {
    int t;
    string s;

    cin >> t;
    while (t--) {
        cin >> s;

        int ans = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                int x=i;
                int y=j;
                int sum = 0;
                for(auto k:s)
                    if(k-'0' == x){
                        sum++;
                        std::swap(x,y);
                    }
                if(x!= y && sum%2==1)
                    sum--;
                ans = std::max(ans, sum);
            }
        }

        std::cout << s.length()-ans << "\n";
    }
    return 0;
}