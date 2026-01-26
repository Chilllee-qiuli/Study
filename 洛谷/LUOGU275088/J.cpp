#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t;
int n, m, k;
int f[maxn];
map<int, int> sig;
map<pair<int, int>, int> dou;

int main(){
    freopen("1.in"  , "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        int ans = 0;
        cin >> n >> m >> k;
        sig.clear();
        dou.clear();
        memset(f, 0, sizeof(f));
        for(int i = 1; i <= n; i++) {
            int x; cin >> x;
            f[x] = 1;
        }

        for(int i = 1; i <= m; i++){
            int a, b;
            cin >> a >> b;
            if(f[a] && f[b]) ans++;
            else if(a == b) sig[a]++;
            else if(f[a] || f[b]){
                if(f[a]) sig[b]++;
                else sig[a]++;
            }
            else{
                if(a > b) swap(a, b);
                dou[{a, b}]++;
            }
        }

        int tmp = 0;
        for(auto it : dou)
            tmp = max(tmp, it.second + sig[it.first.first] + sig[it.first.second]);
        
        
            int max1 = 0, max2 = 0;
        for(auto it : sig){
            if(it.second > sig[max1]){
                max2 = max1;
                max1 = it.first;
            }
            else if(it.second > sig[max2]){
                max2 = it.first;
            }
        }
        if(max1 > max2)swap(max1, max2);
        tmp = max(tmp, sig[max1] + sig[max2] + dou[{max1, max2}]);

        cout << ans + tmp << endl;

    }

	return 0;
}