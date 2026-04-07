#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;

int a[maxn];
int n, c;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> c;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);

    int l = 1, r = 1;
    ll ans = 0;

    for(int i = 2; i <= n; i++){
        while(a[r] <= a[i] - c && r <= i) r++;
        while(a[l] < a[i] - c && l <= r) l++;
        //printf("i = %d, l = %d, r = %d\n", i, l, r);
        ans += r - l;
    }

    cout << ans << endl;

    

    return 0;
}