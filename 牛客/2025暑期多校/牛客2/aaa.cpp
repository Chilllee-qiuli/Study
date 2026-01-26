#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
const int mod =  998244353;
int a[maxn], T;
int n;
ll ans;
ll check(){
    ll cnt = 0;
    for(int i = 1; i <= n; i++){
        cout << a[i] << " ";
        if(a[i] == 1 && a[i-1] == 0) cnt++; 
    }
    cout << endl;
    return cnt;
}

void dfs(int depth, int start) {  
    if(depth <= 0){
        int x = check();
        cout << "nowx: " << x << endl;
        ans = (ans + x) % mod;
        return;
    }
    for(int i = start; i <= n; i++) {
        if(a[i] == -1) {
            a[i] = 1;
            dfs(depth - 1, i + 1);
            a[i] = 0;
            dfs(depth - 1, i + 1);
            a[i] = -1; 
            break;
        }
    }
}

int main(){
    //freopen("a.in", "r", stdin);
    //freopen("aaa.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        ans = 0;
        cin >> n;
        ll cnt = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if(a[i] == -1) cnt++;
        }
        dfs(cnt, 1);
        cout << ans << endl;
    }

	return 0;
}
