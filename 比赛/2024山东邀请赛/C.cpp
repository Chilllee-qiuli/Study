#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
const int mod = 998244353;
ll ans = 1;
int t;
int n, k;
struct Seg{
    int l, r;
    friend bool operator < (Seg x, Seg y){
        return x.l < y.l;
    }
}seg[maxn];

unordered_map<int, int> mp;

int tr[2][maxn * 2];
int fd(int idx, int x){
    int tmp = 0;
    for(; x; x -= x & -x) tmp += tr[idx][x];
    return tmp;
}
void add(int idx, int x, int y){
    for(; x <= 2 * n; x += x & -x) tr[idx][x] += y;
}
void pre(){
    cin >> n >> k;
    ans = 1;
    vector<int> tmp;
    mp.clear();
    for(int i = 1; i <= 2 * n; i++) tr[0][i] = tr[1][i] = 0;
    
    for(int i = 1; i <= n; i++){
        int l, r;
        cin >> l >> r;
        seg[i].l = l; seg[i].r = r;
        tmp.push_back(l);
        tmp.push_back(r);
    }
    tmp.push_back(-1);
    
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for(int i = 1; i < tmp.size(); i++) mp[tmp[i]] = i;
    
    sort(seg + 1, seg + 1 + n);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        pre();

        for(int i = 1; i <= n; i++){
            int l = mp[seg[i].l], r = mp[seg[i].r];
            int num = fd(0, r) - fd(1, l - 1); // 化简自  i - 1 - fd(1, l - 1) - (i - 1 - fd(0, r));
            add(0, l, 1);
            add(1, r, 1);
            // cout << num << " ";
            ans = ans * max(0, k - num) % mod;
        }
        // cout << endl;

        cout << ans << endl;


    }

	return 0;
}
