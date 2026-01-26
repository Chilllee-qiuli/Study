#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t;
int n, a[maxn];
int b[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int ans = 0;
        set<int> vals;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            vals.insert(a[i]);
        }
        vector<int> l(n + 2), r(n + 2);

        for(int med : vals){ // 只枚举出现过的数
            b[0] = 0 ;
            for(int i = 1; i <= n; i++)
                if(a[i] >= med) b[i] = 1;
                else if(a[i] < med) b[i] = -1;
                else b[i] = 0;
            l[0] = 0;
            r[n+1] = 0;
            for(int i = 1; i <= n; i++) b[i] += b[i - 1];

            for(int i = 1; i <= n; i++) l[i] = min(l[i - 1], b[i]);
            for(int i = n; i; i--) r[i] = max(r[i + 1], b[i]);

            for(int i = 1; i <= n; i++)
                if(r[i] > l[i - 1]) ans = max(ans, med - a[i]);
        }

        cout << ans << endl;
    }

    return 0;
}