#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100;
int t;
int n;
int a[maxn], b[maxn];

int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
    
        for(int i = 1; i <= n; i++) cin >> b[i];
    
        int ans = 0;
        for(int i = 1; i <= n; i++)
            if(a[i] > b[i]) ans += a[i] - b[i];
        ans++;
        cout << ans << endl;
    
    }
	return 0;
}
