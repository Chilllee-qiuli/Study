#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5+10;
int T, n;
ll a[maxn];
int f[20];

bool cmp(ll x, ll y){return x > y;}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        memset(f, 0, sizeof(f));
        bool flag = 1;
        for(int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + 1 + n, cmp);
        for(int i = 1; i <= n; i++) {
            int tmp = 0;
            while(a[i]){
                ++tmp;
                if(a[i] & 1) f[tmp]++;
                a[i] >>= 1;
            }
            if(f[tmp] > 1) flag = 0;
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;

    }

    return 0;
}