#include <iostream>
#include <queue>
#include <map>

int main() {
    int tasks;
    int e, g = 0;
    std::string job;
    std::map<int, std::priority_queue<int>> quests;
    std::cin >> tasks;

    while(tasks--){
        std::cin >> job;
        if(job == "add"){
            std::cin >> e >> g;
            if(quests.find(e) == quests.end()){
                quests[e] = std::priority_queue<int>();
            }
            quests[e].push(g);
        }
        else if (job == "query"){
            long long int sum = 0;
            std::cin >> e;
            while(e>0 && !quests.empty()){
                auto it = quests.upper_bound(e);
                if(it == quests.begin())
                    break;
                it--;

                e -= it->first;
                sum += it->second.top();
                it->second.pop();

                if(it->second.empty())
                    quests.erase(it);
            }
            std::cout << sum << "\n";
        }
    }
    return 0;
}
