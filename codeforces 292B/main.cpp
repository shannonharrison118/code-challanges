#include <iostream>

int main() {
    int n,m;
    std::cin>>n>>m;

    int a[n+1] = {0};
    while(m--){
        int x,y;
        std::cin>>x>>y;
        a[x]++;
        a[y]++;
    }

    int cnt[n+1] = {0};

    for(int i=1;i<=n;i++)
        cnt[a[i]]++;

    if(cnt[n-1] == 1 && cnt[1] == n-1)
        std::cout<<"star topology";
    else if(cnt[1] ==2 && cnt[2] == n-2)
        std::cout<<"bus topology";
    else if(cnt[2] == n)
        std::cout<<"ring topology";
    else
        std::cout<<"unknown topology";
    return 0;
}
