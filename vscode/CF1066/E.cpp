#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 6e5 + 10;
int t;
int n, k;
int cnt[maxn];
int f[maxn];

int find(int x){
    if(x == f[x]) return x;
    else return f[x] = find(f[x]);
}

void merge(int x, int y){
    int fax = find(x), fay = find(y);
    if(fax == fay) return ;
    f[fax] = fay;
}

int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        ll ans = 0;
        cin >> n >> k;
        for(int i = 1; i <= n * 3 + 10; i++) {
            cnt[i] = 0;
            f[i] = i;
        }

        for(int i = 1, x; i <= n; i++){
            cin >> x;
            if(cnt[x] < k) cnt[x]++;
            else {
                int fa = find(x);
                cnt[fa]++;
                while(cnt[fa] >= k)
                    merge(fa, ++fa);
                
                ans += fa - x;
            }
        }

        cout << ans << endl;
    }

	return 0;
}
