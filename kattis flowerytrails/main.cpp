#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
    int p, t;
    long long int ans = 0;
    long long int MAX = 9223372036854775807;

    std::cin >> p >> t;

    std::vector<std::vector<std::pair<int, int>>> graph(p);
    std::vector<std::vector<std::pair<int, int>>> parent(p);
    std::vector<long long int> dist(p, MAX);
    std::vector<int> trl(t);
    std::queue<int> q;
    std::vector<bool> visited(t, false);
    std::queue<std::pair<int, int>> qq;

    for(int i = 0; i < t; i++){
        int x,y,w;
        std::cin >> x >> y >> w;
        graph[x].push_back(std::make_pair(y,i));
        graph[y].push_back(std::make_pair(x,i));
        trl[i]=w;
    }
    q.push(0);
    dist[0]=0;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(auto& i : graph[temp]){
            if(dist[i.first] > dist[temp]+trl[i.second]){
                dist[i.first] = dist[temp]+trl[i.second];
                q.push(i.first);
                parent[i.first].clear();
                parent[i.first].push_back(std::make_pair(i.second, temp));
            }
            else if (dist[i.first] == dist[temp]+trl[i.second]){
                parent[i.first].push_back(std::make_pair(i.second, temp));
            }
        }
    }

    for(auto& i : parent[p-1]){
        if(!visited[i.first]){
            qq.push(i);
            visited[i.first] = true;
        }
    }
    while(!qq.empty()){
        ans += trl[qq.front().first];
        for(auto& i : parent[qq.front().second]){
            if(!visited[i.first]){
                qq.push(i);
                visited[i.first] = true;
            }
        }
        qq.pop();
    }

    std::cout << ans*2 << "\n";
    return 0;
}
