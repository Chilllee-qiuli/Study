#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 10;
int n, k, c;
int a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k >> c;
    for(int i = 1; i <= n; i++){
        cin >> a[i]; 
        a[i] -= (i - k) * c;
    }

    sort(a + 1, a + 1 + n);
    ll ans = 0;

    for(int i = n; i >= n - k + 1; i--){
        ans += a[i];
    }

    


	return 0;
}
