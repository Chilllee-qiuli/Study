#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxl = 1e6 + 10;
const int mod = 19930726;
ll cnt[maxl];
string s;
ll n, k;

string trans(string str){
    string tmp;
    for(auto ch : str){
        tmp += '#';
        tmp += ch;
    }
    return tmp + "#";
}

void solve(string s){
    int n = s.length();
    vector<int> d(n);
    for(int i = 0, l = 0, r = -1; i < n; i++){
        int k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);
        while(i - k >= 0 && i + k < n && s[i - k] == s[i + k]){k++;}
        d[i] = k--;
        if(i + k > r){
            l = i - k;
            r = i + k;
        }
        if(i % 2 == 1)
        cnt[k]++;
    }
}

ll qpow(ll x, ll y){
    if(y == 0) return 1;
    if(y == 1) return x;
    ll tmp = qpow(x, y >> 1) % mod;
    if(y & 1) return tmp * tmp % mod * x % mod;
    return tmp * tmp % mod;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    cin >> s;
    s = trans(s);
    solve(s);

    ll ans = 1;
    for(int i = n; i ; i--){
        cnt[i] += cnt[i + 2];
        if(k <= cnt[i]){
            ans = ans * qpow(i, k) % mod;
            k = 0;
            break;
        }
        else {
            k -= cnt[i];
            ans = ans * qpow(i, cnt[i]) % mod;
        }
    }

    if(k) cout << -1 << endl;
    else cout << ans << endl;



	return 0;
}
