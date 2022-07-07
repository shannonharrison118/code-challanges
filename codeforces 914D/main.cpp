#include <iostream>

int tree[4*500005];
int a[500005];

int gcd(int a,int b){
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

void build(int node,int l,int r){
    if(l==r)
    {
        tree[node]=a[l];
        return;
    }
    int m=(l+r)/2;
    build(node<<1,l,m);
    build(node<<1|1,m+1,r);
    tree[node]=gcd(tree[node<<1],tree[node<<1|1]);
}

void update(int pos, int val, int l, int r, int node) {
    if(l == r) {
        tree[node] = val;
        return ;
    }
    int m = (l + r) >> 1;

    if(pos<=m) {
        update(pos, val, l, m,node<<1);
    }
    else {
        update(pos, val, m + 1, r, node << 1 | 1);
    }

    tree[node]=gcd(tree[node<<1],tree[node<<1|1]);
}
int query(int L, int R, int val, int l, int r, int node) {
    if(L <= l && r <= R) {
        if(tree[node]%val==0) {
            return 0;
        }
    }
    if(l == r) {
        return (tree[node]% val!= 0);
    }
    int m = (l + r) >> 1;
    int ret = 0;
    if(L <= m) {
        ret += query(L, R, val, l, m, node << 1);
    }
    if(ret >= 2) {
        return ret;
    }
    if(R > m) {
        ret += query(L, R, val, m + 1, r, node << 1 | 1);
    }
    return ret;
}

int main(){
    int n,q,c,l,r,x;

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    build(1,1,n);

    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d",&c);
        if(c==1){
            scanf("%d %d %d",&l,&r,&x);
            int ans=query(l,r,x,1,n,1);
            if(ans<=1) printf("YES\n");
            else printf("NO\n");
        }
        else{
            scanf("%d %d",&l,&x);
            update(l,x,1,n,1);
        }
    }
    return 0;
}