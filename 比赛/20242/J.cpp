#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n;

struct node {
    ll w;
    ll v;
    ll c;
}a[maxn];
bool operator < (node x, node y){
    return x.w * y.c < x.c * y.w;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i].w >> a[i].v >> a[i].c;
    sort(a + 1, a + 1 + n);
    ll tmpw = 0;
    ll ans  = 0;
    for(int i = n; i >= 1; i--){
        ans += a[i].v - a[i].c * tmpw;
        tmpw += a[i].w;
    }

    cout << ans << endl;


	return 0;
}