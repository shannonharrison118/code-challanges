#include <iostream>
#include <vector>
#include <bits/stdc++.h>

std::vector<int> nei[500005];
int dep[500005];
bool cyc = false;

void dfs(int node, int par, int depth){
    if(dep[node]){
        if(depth - dep[node] & 1)
            cyc = true;
        return;
    }
    dep[node] = depth;
    for(int i: nei[node]){
        if(i != par)
            dfs(i, node, depth+1);
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    int ans = 0;

    std::cin >> n >> m;
    for(int i = 0; i < m; i++){
        int u,v;
        std::cin >> u >> v;
        nei[u].push_back(v);
        nei[v].push_back(u);
    }
    for(int i = 1; i <=n; i++){
        if(!dep[i]){
            dfs(i, -1, 1);
            ans++;
        }
    }

    std::cout << ans-1 + !cyc << "\n";
    return 0;
}
