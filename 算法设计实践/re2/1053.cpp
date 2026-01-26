#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 10010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll num[maxn];
int n, k;


int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> num[i];
    sort(num + 1, num + 1 + n);

    while(k--){
        int l = 1, r = n;
        ll ans_l = inf, ans_r = n + 1;
        ll s;
        cin >> s;
        while(l < r){
            r = lower_bound(num + l + 1, num + n, s - num[l]) - num;
            if(num[l] + num[r] == s) 
        }
        if(ans_l != inf) cout << ans_l << " " << ans_r << endl;
        else cout << 0 << endl;
    }


	return 0;
}