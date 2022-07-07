#include <iostream>
#include <vector>

std::vector<int> v[200000];
int color[200000];
bool f[200000];
int a[200000],b[200000];
void dfs(int n)
{
    f[n] = 1;
    int a = 1-color[n];
    for(int i=0; i < v[n].size(); i++){
        if(f[v[n][i]] && color[v[n][i]] != a){
            std::cout<<"NO";
            exit(0);
        }
        color[v[n][i]]=a;
        if(!f[v[n][i]])
            dfs(v[n][i]);
    }
}
int main(){
    int n,m;

    std::cin >> n >> m;
    for(int i=0;i<m;i++){
        std::cin >> a[i] >> b[i];
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
    }
    dfs(1);

    std::cout<<"YES\n";

    for(int i=0;i<m;i++)
        std::cout << !color[a[i]];

    return 0;
}