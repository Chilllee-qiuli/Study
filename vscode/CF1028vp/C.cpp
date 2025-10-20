#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e3 + 10;
bool vis[maxn];
int prime[maxn], tot;
int t;
int n;
int a[maxn];

void pre(){
    for(int i = 2; i <= maxn; i++){
        if(!vis[i]) prime[++tot] = i;
        for(int j = 1; j <= tot && i * prime[j] <= maxn; j++){
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}

bitset<100> bit[maxn];
void divv(int x, int id){
    for(int i = 1; i <= tot && x > 1; i++){
        while(x % prime[i] == 0){
            x /= prime[i];
            bit[id].set(i, 1);
        }
    }
}

int main(){
    freopen("1.in", "r", stdin);
    freopen("c.out", "w", stdout);
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
    pre();
    //for(int i = 1; i <= tot; i++) cout << prime[i] << " ";
    cout << "test1" << endl;
    cin >> t;
    while(t--){
        cin >> n;
        cout << "tets2" << endl;
        ll ans = 0;
        int gcd_all = 1;
        for(int i = 1; i <= n; i++){
            bit[i].reset();
            cin >> a[i];
            if(i == 1) gcd_all = a[i];
            else gcd_all = __gcd(gcd_all, a[i]);
        }
        for(int i = 1; i <= n; i++){
            a[i] /= gcd_all;
            if(a[i] == 1) ans++;
        }
        if(ans){
            cout << n - ans << endl;
            continue;
        }

        for(int i = 1; i <= n; i++){
            divv(a[i], i);
            printf("bit[%d].count() = %d\n", i, bit[i].count());
        }

        int flag = 0x3f3f3f3f, fid = 0;
        bitset<100> tmp;
        for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++){
            int num = (bit[i] & bit[j]).count();
            if(num < flag) {flag = num; tmp = bit[i] & bit[j]; fid = i;}
        }


        while(tmp.count() > 0){
            bitset<100> ff = tmp;
             bool changed = false;
            for(int i = 1; i <= n; i++){
                if(i == fid) continue;
                if(ff.count() < (tmp & bit[i]).count()) {ff = tmp & bit[i]; changed = true;}
            }
            if(!changed) break;
            tmp = ff;
            ans++;
        }
        cout << ans + n - 1 << endl;
    }


	return 0;
}
