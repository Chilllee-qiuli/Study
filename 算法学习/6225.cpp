#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int n, q;
int a[maxn];

struct BIT{
    int b[maxn];
    void change(int x, int y, int z){
        for(; x < maxn; x += x & (-x)) b[x] ^= y ^ z;
    }
    int query(int x){
        int res = 0;
        for(; x; x -= x & (-x)){
            res ^= b[x];
        }
        return res;
    }
}tree[2];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        tree[i & 1].b[i] ^= a[i];
        // 线性初始化树状数组
        if(i + (i & -i) <= n) {
            tree[0].b[i + (i & -i)] ^= tree[0].b[i];
            tree[1].b[i + (i & -i)] ^= tree[1].b[i];
        }
    }
    

    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int x, y;
            cin >> x >> y;
            tree[x & 1].change(x, y, a[x]);
            a[x] = y; 
        }
        else {
            int l, r;
            cin >> l >> r;  
            if((r - l + 1) & 1)
                cout << (tree[l & 1].query(r) ^ tree[l & 1].query(l - 1)) << endl;
            
            else cout << 0 << endl;
        }
    }

	return 0;
}
