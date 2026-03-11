#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int a[maxn];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n, greater<int>());

    int sum = 0, l = n;
    for(int i = 1; i <= n; i++){
        if(a[i] > 0) sum += a[i];
        else {l = i - 1; break;}
    }
    if(sum & 1) cout << sum << endl;
    else {
        int tmp1 = sum, tmp2 = sum, flag = 0;
        int ans = -0x3f3f3f3f;
        for(int i = l; i; i--)
            if(a[i] & 1) {tmp1 -= a[i]; flag = 1; break;}
            
        if(flag) ans = max(tmp1, ans);
        flag = 0;
        
        for(int i = l + 1; i <= n; i++)
            if(abs(a[i]) % 2 == 1) {tmp2 += a[i]; flag = 1; break;}
    
        if(flag) ans = max(ans, tmp2);

        cout << ans << endl;
        }


	return 0;
}
