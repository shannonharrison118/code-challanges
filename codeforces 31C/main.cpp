#include <iostream>
#include <vector>

int main() {
    int n;
    long long int start, end;
    long long int num=0;
    long long int sum[5005];
    std::vector<int> rooms;

    //number of groups with lessons
    std::cin >> n;
    long long int l[n];
    long long int r[n];
    //read in start and end times
    for(int i  = 0; i < n; i++){
        std::cin >> start >> end;
        l[i] = start;
        r[i] = end;
        sum[i]=0;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(l[i] < r[j] && l[j] < r[i]){
                sum[i]++;
                sum[j]++;
                num++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(sum[i] == num)
            rooms.push_back(i+1);
    }
    std::cout << rooms.size() << "\n";
    for(int i = 0; i < rooms.size(); i++) {
        std::cout << rooms[i] << " ";
    }
    return 0;
}
