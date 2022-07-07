#include <iostream>
#include <vector>
#include <queue>
#include<bits/stdc++.h>

int main() {
    int n,m;
    std::cin >> n >> m;
    std::vector<int> edges[10086];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ch;
            std::cin>>ch;
            if(ch=='#')
            {
                edges[i].push_back(j+n);
                edges[j+n].push_back(i);
            }
        }
    }
    int d[n+m];
    memset(d,-1,sizeof(d));
    std::queue<int> q;
    q.push(0);

    d[0]=0;
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        for(auto &i : edges[v])
        {
            if(d[i]==-1)
            {
                d[i]=d[v]+1;
                q.push(i);
            }
        }
    }
    std::cout << d[n-1];
    return 0;
}
