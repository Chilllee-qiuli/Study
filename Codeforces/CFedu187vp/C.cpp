#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll S, M;

vector<ll> turn(ll x){
    vector<ll> tmp;
    while(x){
        if(x & 1) tmp.push_back(1);
        else tmp.push_back(0);
        x /= 2;
    }
    return tmp;
}

vector<ll> s, m;

bool check(ll x, vector<ll> tmp){
    int maxx = 0;
    for(int i = tmp.size() - 1; i; i--){
        if(!m[i]) {
            tmp[i - 1] += tmp[i] * 2;
            tmp[i] = 0;
        }
        else if (tmp[i] > x){
            tmp[i - 1] += (tmp[i] - x) * 2;
            tmp[i] = x;
        }
    }
    if(tmp[0] && !m[0]) return 0;
    return tmp[0] <= x;
}


ll solve_one(){
    cin >> S >> M;
    // 转化为二进制并对齐长度
    s = turn(S), m = turn(M);
    while(s.size() < m.size()) s.push_back(0);
    while(m.size() < s.size()) m.push_back(0);

    for(int i = s.size() - 1; i; i--){
        if(!m[i]){ // 如果这一位的 m 不为1
            // 往低位推找人凑
            s[i - 1] += s[i] * 2;
            s[i] = 0;
        }
        // 否则，这一位的 1 就可以用来拼凑 s 了
    }

    if(s[0] && !m[0]) return -1;

    ll l = 1, r = S, ans = S + 1;
    while(l <= r){
        ll mid = (l + r) >> 1;
        if(check(mid, s)) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    if(ans == S + 1) return -1;
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0); 
    
    int T;
    cin >> T;
    while(T--) cout << solve_one() << "\n";



	return 0;
}
