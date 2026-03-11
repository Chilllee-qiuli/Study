// 本模板代码参照洛谷进阶篇版本
// change改为李煜东的insert写法
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

struct seg{
    int val, ls, rs;
};

int root[maxn], cnt;
struct Tree{  // 主席树
    seg tree[maxn << 5];
    int query(int u1, int u2, int l, int r, int q){
        if(l == r) return l;
        int mid = l + r >> 1;
        int tmp = tree[tree[u2].ls].val - tree[tree[u1].ls].val; // 差分前缀左子树，得到区间左子树值
        if(tmp >= q) return query(tree[u1].ls, tree[u2].ls, l, mid, q); // 在左边
        else return query(tree[u1].rs, tree[u2].rs, mid + 1, r, q - tmp);
    }
    void pushup(int u){
        tree[u].val = tree[tree[u].ls].val + tree[tree[u].rs].val;
    }
    int insert(int now, int l, int r, int x, int val) {
        int p = ++cnt;
        tree[p] = tree[now];
        if (l == r) {
            tree[p].val += val;
            return p;
        }
        int mid = (l + r) >> 1;
        if (x <= mid) tree[p].ls = insert(tree[now].ls, l, mid, x, val);
        else tree[p].rs = insert(tree[now].rs, mid + 1, r, x, val);
        pushup(p);
        return p;
    }
}tr;

void pre();

int n, m, raw[maxn];
vector<int> lsh;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    pre();

    for(int i = 1; i <= n; i++){
        raw[i] = lower_bound(lsh.begin(), lsh.end(), raw[i]) - lsh.begin() + 1;
        root[i] = tr.insert(root[i - 1], 1, lsh.size(), raw[i], 1);
    }

    for(int i = 1; i <= m; i++){
        int l, r, q;
        cin >> l >> r >> q;
        cout << lsh[tr.query(root[l - 1], root[r], 1, lsh.size(), q) - 1] << "\n";
    }
	return 0;
}

void pre(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> raw[i];
        lsh.push_back(raw[i]);
    }

    sort(lsh.begin(), lsh.end());
    lsh.erase(unique(lsh.begin(), lsh.end()), lsh.end());

}


