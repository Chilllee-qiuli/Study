#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
vector<int> num(maxn);
struct cnm{
    int bit;
    ll contri;
};
bool cmp_cnm(cnm a, cnm b) {
    return a.contri == b.contri ? a.bit < b.bit : a.contri > b.contri;
}
struct an{
    int x;
    ll sum;
};
bool cmp_an(an x, an y){
    return x.sum == y.sum ? x.x < y.x : x.sum > y.sum;
}
ll sum(int x, int n){
    ll tmp = 0;
    for(int i = 1; i <= n; i++) tmp += max(num[i], num[i] ^ x);
    return tmp;
}

int work(ll x, int n, int m, int k, vector<int> a){
    vector<int> cnt(m + 1, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cnt[j] += (a[i] & (1 << j));
        }
    }
    cnm add[35];

    for(int i = 0; i < m; i++){
        if(cnt[i] >= (n + 1) / 2) continue;
        add[i].contri = (1ll << i) * (n - 2 * cnt[i]);
        add[i].bit = i;
    }

    sort(add + 0, add + m, cmp_cnm);

    return x + (1ll << add[0].bit);
}

int main(){
   // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m, k ;
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++)  
        cin >> num[i];

    

    int x = work(0, n, m, k, num);
    //cout <<"test: " << x << endl;
    int i = m - 1;
    for(; i >= 0; i--)if(x &(i << i)) break;
    for(; i >= 0 && k ; i--){
        vector<int> tmp;
        for(int j = 1; j <= n; j++) if(!(num[j] & x)) tmp.push_back(num[j]);
        int ans = work(0, tmp.size(), i, k - 1, tmp);
        if(ans > 0){
            k--;
            x += ans;
        }
    }
    cout << x << endl;

    return 0;
}