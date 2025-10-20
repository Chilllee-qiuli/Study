#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e9 + 10;
int t;
map<ll, ll> pc; // precost
ll n;
ll ans = 0;

void pre(){
    for(int i = 1; i <= 28; i++)
    pc[pow(3, i)] = pow(3, i + 1) + pow(3, i - 1) * i;
}

void dfs(ll x, ll d){
    ll y = x % 3;
    ans += y * pc[pow(3, d)];
    if(x <= 2) return ;
    dfs(x/3, d + 1);
}

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    pre();
    cin >> t;
    pc[1] = 3;
    while(t--){
        cin >> n;
        ans = 0;
        dfs(n, 0);
        cout << ans << endl;
    }


   
	return 0;
}
