#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n, k;
ll f[maxn], E[maxn];
ll sum[maxn];

int qu[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> E[i];
        sum[i] = sum[i-1] + E[i];
    }
    memset(f, 0x3f, sizeof(f));
    int l = 0, r = 0;
    qu[r++] = 0;
    f[0] = 0;
    for(int i = 1; i <= n + 1; i++){
        while(qu[l] < i - k - 1 && l < r) l++;
        f[i] = f[qu[l]] + E[i];
        while(l < r && f[i] <= f[qu[r - 1]]) r--;
        qu[r++] = i;

    }

    cout << sum[n] - f[n+1] << endl;


	return 0;
}
