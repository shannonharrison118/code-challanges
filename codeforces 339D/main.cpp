#include <iostream>

struct Tree{
    int left, right;
    int value;
};
Tree tree[1 << 19];

void makeTree(int l, int r, int node){
    tree[node].left = l;
    tree[node].right = r;
    tree[node].value = 0;

    if(l == r)
        return;
    int mid = (l+r) >> 1;
    makeTree(l, mid, 2*node);
    makeTree(mid+1, r, 2*node+1);
}

void insertTree(int l, int r, int node, int x, int cur){
    if (l == tree[node].left && r == tree[node].right){
        tree[node].value = x;
        return;
    }
    int mid = (tree[node].left + tree[node].right) >> 1;
    if (r <= mid){
        insertTree(l, r, 2*node, x, cur-1);
    }
    else{
        insertTree(l, r, 2*node+1, x, cur-1);
    }

    if(cur%2 == 0){
        tree[node].value = tree[2*node].value | tree[2*node+1].value;
    }
    else{
        tree[node].value = tree[2*node].value ^ tree[2*node+1].value;
    }
}

int query(){
    return tree[1].value;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    int num = 1 << n;
    makeTree(1, num, 1);

    for(int i = 1; i <= num; i++){
        int x;
        std::cin >> x;
        insertTree(i, i, 1, x, n+1);
    }

    while(m--){
        int a, b;
        std::cin >> a >> b;
        insertTree(a, a, 1, b, n+1);
        std::cout << query() << '\n';
    }

    return 0;
}
