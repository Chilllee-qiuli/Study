#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 10;
int n, k;
int a[maxn];
ll sum[maxn];

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];
    

    while(k--){
        int b, e;
        cin >> b >> e;
        cout << sum[e] - sum[b - 1] << endl;
    }

	return 0;
}
