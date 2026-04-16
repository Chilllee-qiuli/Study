#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
int t;
int n, a[maxn];
ll k;

multiset<ll> qul, qur;
ll suml, sumr;

void maintain(){
    while(qul.size() < qur.size()){
        auto it = qur.begin();
        ll x = *it;
        qur.erase(it);
        sumr -= x;
        qul.insert(x);
        suml += x;
    }
    while(qul.size() > qur.size() + 1){
        auto it = prev(qul.end());
        ll x = *it;
        qul.erase(it);
        suml -= x;
        qur.insert(x);
        sumr += x;
    }
}

void insert_val(ll x){
    if(qul.empty() || x <= *prev(qul.end())){
        qul.insert(x);
        suml += x;
    }
    else{
        qur.insert(x);
        sumr += x;
    }
    maintain();
}

void erase_val(ll x){
    auto it = qul.find(x);
    if(it != qul.end()){
        qul.erase(it);
        suml -= x;
    }
    else{
        it = qur.find(x);
        qur.erase(it);
        sumr -= x;
    }
    maintain();
}

ll get_cost(){
    ll med = *prev(qul.end());
    ll res = med * (ll)qul.size() - suml;
    res += sumr - med * (ll)qur.size();
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++) cin >> a[i];

        qul.clear();
        qur.clear();
        suml = sumr = 0;

        int l = 1, ans = 1;
        for(int r = 1; r <= n; r++){
            insert_val(1ll * a[r] - r);

            while(l <= r && get_cost() > k){
                erase_val(1ll * a[l] - l);
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        cout << ans << '\n';
    }

    return 0;
}
