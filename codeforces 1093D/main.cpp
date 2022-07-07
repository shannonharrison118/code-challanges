#include <iostream>
#include <vector>
using namespace std;

const int N=3e5+5;
const int M=998244353;
vector<int> g[N];
int t,n,m,a,b,v[N],p[N]{1};

bool dfs(int x){
    if(v[x]==1) {
        a++;
        b++;
    }
    for(int c:g[x]){
        if(v[c]==v[x]) return false;
        if(!v[c]){
            v[c]=-v[x];
            if(!dfs(c)) return false;
        }
    }
    return true;
}

int main(){
    for(int i=1;i<N;i++)
        p[i]=p[i-1]*2%M;

    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            g[i].clear();
            v[i]=0;
        }
        while(m--){
            scanf("%d%d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }

        long long ans=1;
        for(int i=1;i<=n;i++){
            if(!v[i]){
                a=b=0;
                v[i]=1;
                ans = ans*dfs(i)*(p[a]+p[b-a])%M;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}