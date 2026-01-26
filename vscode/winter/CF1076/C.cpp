#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int n, q;
int t;
int a[maxn], b[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> q;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++) cin >> b[i];
        a[n + 1] = 0;

        for(int i = n; i >= 1; i--){
            a[i] = max({a[i + 1], b[i], a[i]});
        }

        for(int i = 1; i <= n; i++) a[i] += a[i - 1];   

        while(q--){
            int l, r;
            cin >> l >> r;
            cout << a[r] - a[l - 1] << " ";
        }
        cout << endl;
    }

	return 0;
}