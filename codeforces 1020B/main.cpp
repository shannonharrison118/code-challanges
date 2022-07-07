#include <iostream>

int main() {
    int n;

    std::cin >> n;
    int p[n];
    for(int i=0; i < n; i++)
    {
        std::cin >> p[i];
    }

    for(int i=0;i<n;i++)
    {
        int g[n]={};
        int j=i;
        while(!g[j])
        {
            g[j]=1;
            j=p[j]-1;
        }
        std::cout<<j+1<<" ";
    }
    return 0;
}
