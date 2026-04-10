#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 10;

int n, t;
int a[maxn], b[maxn], c[maxn];

int cpt(int x, int y, int z){
    if(a[x] == b[y] && b[y] == c[z]) return 300;
    if(a[x] + 1 == b[y] && b[y] + 1 == c[z]) return 200;
    if(a[x] == b[y] || b[y] == c[z] || c[z] == a[x]) return 100;
    vector<int> vc;
    vc.push_back(a[x]);
    vc.push_back(b[y]);
    vc.push_back(c[z]);
    sort(vc.begin(), vc.end());
    if(vc[0] + 1 == vc[1] && vc[1] + 1 == vc[2]) return 100;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i - 1];
    for (int i = 1; i <= n; i++)
        cin >> b[i - 1];
    for (int i = 1; i <= n; i++)
        cin >> c[i - 1];

    cin >> t;
    int p, q, r;
    p = q = r = 0;
    ll ans = 0;
    while(t--){
        int x, y, z;
        cin >> x >> y >> z;
        p = (p + x) % n;
        q = (q + y) % n;
        r = (r + z) % n;
        ans += cpt(p, q, r);
    }
    cout << ans << endl;

    return 0;
}
