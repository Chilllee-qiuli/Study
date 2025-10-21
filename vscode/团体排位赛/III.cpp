#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
struct cnm{
    int bit;
    ll contri;
};

bool cmp(cnm a, cnm b) {
    return a.contri == b.contri ? a.bit < b.bit : a.contri > b.contri;
}

int main(){
   // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n, m, k ;
    cin >> n >> m >> k;
    vector<int> cnt(m);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int p = 0;
        while(x){
            cnt[p++] += (x & 1);
            x >>= 1;
        }
    }
    
    vector<cnm> contri(m);

    for(int i = 0; i < m; i++){
        if(cnt[i] >= (n + 1) / 2) continue;
        contri[i].contri = 1LL * (n - 2 * cnt[i]) * (1LL << i);
        contri[i].bit = i;
    }
    sort(contri.begin(),contri.end(), cmp);

    ll x = 0;
    for(int i = 0; i < k && contri[i].contri > 0; i++){
        x += (1ll << contri[i].bit);
    }


    
    cout << x << endl;


    return 0;
}