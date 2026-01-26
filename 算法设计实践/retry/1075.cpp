#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
vector<int> p(maxn);
int t;
int n, m;
ll k;

bool check(int st, int mid){
    vector<ll> tmp;
    tmp.push_back(0);
    for(int i = st; i <= mid; i++) tmp.push_back(p[i]);
    sort(tmp.begin() + 1, tmp.end());
    ll cnt = 0;
    int sz = tmp.size() - 1;
    for(int i = 1; i <= sz/2 && i <= m; i++){
        ll diff = tmp[i] - tmp[sz - i + 1];
        cnt += diff * diff;
    }

    return (cnt <= k);
}
// 这里不能用二分是因为此题常数卡的比较死
// 二分是从大到小取区间，造成每次排序开销巨大
// 而这里的倍增方法从小往大取，在有极多短小段答案的情况下可以少对大长段做排序

int work(int st){
    /*int l = st, r = n;
    int ans = l;
    while(l <= r){
        int mid = (l + r) >> 1;
        vector<ll> tmp;
        tmp.push_back(0);
        for(int i = st; i <= mid; i++) tmp.push_back(p[i]);
       // cout << "check : " << st << " " << mid << " ";
        if(check(tmp)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }*/

    int step = 1;
    int r = st;
    while(step > 0){
        int ed = r + step;
        if(ed <= n && check(st, ed)){
            r = ed;
            step <<= 1;
        }
        else step >>= 1;
    }

    return r;
}

int main(){
   // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        int ans = 0;
        for(int i = 1; i <= n; i++) cin >> p[i];
        for(int l = 1; l <= n; l++){
            int r = work(l);
            //cout << "test " << l << " " << r << endl;
            ans++;
            l = r;
        }
        cout << ans << endl;
    }

	return 0;
}