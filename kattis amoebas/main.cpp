#include <iostream>

int n, m;
char a[105][105];
int x[] = {-1,-1,0,1,1,1,0,-1};
int y[] = {0,1,1,1,0,-1,-1,-1};

void dfs(int i, int j){
    if(i<0 || j<0 || i>m-1 || j>n-1 || a[i][j] != '#')
        return;

    a[i][j] = '.';
    for(int k = 0; k < 8; k++){
        dfs(i+x[k], j+y[k]);
    }

}
int main() {
    std::string s;
    int ans = 0;

    std::cin >> m >> n;
    for(int i = 0; i < m; i++){
        std::cin >> s;
        for(int j = 0; j < n; j++){
            a[i][j] = (s[j]);
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == '#'){
                ans++;
                dfs(i,j);
            }
        }
    }

    std::cout << ans << "\n";
    return 0;
}
