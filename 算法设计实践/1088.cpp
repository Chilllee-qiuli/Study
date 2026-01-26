#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxn = 1e4 + 10;
int a[maxn], f[maxn];

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        f[i] = 1;
        cin >> a[i];
        for(int j = 1; j < i; j++){
            if(a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
        }
        ans = max(ans, f[i]);
    }
    cout << ans << endl;

	return 0;
}