#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n, k;
ll a[maxn];
map<ll, int> mp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!mp[a[i]]){
            ans++;
            mp[a[i] * k] = 1;  
        }
    }
    cout << ans << endl;

	return 0;
}
