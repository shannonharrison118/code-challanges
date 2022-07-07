#include <iostream>
#include <vector>
using namespace std;

long long int sum(int index, long long int fenwick[]){
    long long int ans = 0;
    while(index > 0){
        ans += fenwick[index];
        index -= (index & -index);
    }
    return ans;
}

void update(int index, long long int value, long long int fenwick[], int n){
    while(index < n){
        fenwick[index] += value;
        index += (index & -index);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    std::cin >> n >> q;

    long long int arr[n+1] = {0};
    long long int fen[n+1] = {0};

    for(int i = 0; i < q; i++){
        char c;
        std::cin >> c;
        if(c == '+'){
            int index = 0;
            long long int op;
            std::cin >> index >> op;
            update(index+1, arr[index+1] + op, fen, n+1);
        }
        else{
            int index = 0;
            std::cin >> index;

            long long ans = sum(index, fen);
            std::cout << ans << '\n';
        }
    }
    return 0;
}