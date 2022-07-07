#include <iostream>
#include <set>

int a[300005];

int main(){

    std::set<int> s;
    int n, m;
    std::cin >> n >> m;

    for(int i = 1; i <= n; i++)
        s.insert(i);

    for(int i = 0; i < m; i++){
        int l, r, x;
        std::cin >> l >> r >> x;
        auto ss = s.lower_bound(l);
        while(ss != s.end()){
            int val = *ss;
            ss++;
            if(val > r) break;
            if(val != x)
                a[val] = x, s.erase(val);
        }
    }

    for(int i = 1; i <= n; i++)
        std::cout << a[i] << " ";

    return 0;
}
