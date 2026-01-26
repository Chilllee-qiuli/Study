#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 10;
const int mod =  998244353;
int a[maxn], T;
vector<int> unk;
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

void dfs(int now){
    if(now >= unk.size() - 1){
        ans += check();
        ans %= mod;
        return ; 
    }
    a[unk[now]] = 1;
    dfs(now+1);
    a[unk[now]] = 0;
    dfs(now+1);
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
            if(a[i] == -1) unk.push_back(i);
        }
        dfs(0);
        cout << ans << endl;


    }

	return 0;
}
