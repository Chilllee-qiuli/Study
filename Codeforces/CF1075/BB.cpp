#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n;
ll x;

struct node{
    ll a, b, c;
}p[maxn];

ll s_o(){
    cin >> n >> x;
    ll sum_all = 0, sum_one = 0;
    ll ans = 0;
    int m = 0;
    for(int i = 1; i <= n; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        if(x > 0) x -= max(0, a * (b - 1));
        if(a * b - c < 0) continue;
        sum_all += a * (b - 1);
        sum_one += a - c;
        p[++m] = {a, b, c};
    }
    if(x <= 0) return 0;
    ll sum = sum_all + sum_one;
    if(sum <= 0) return -1;
    sort(p + 1,  p + 1 + m, [](const node& x, const node&y){
        return x.a - x.c > y.a - y.c;
    });
    ans += x / sum * m;
    x %= sum;
    if(x <= sum_all) return ans;
    else {
        x -= sum_all;
        for(int i = 1; i <= m; i++){
            x += p[i].a - p[i].c;
            ans++;
            if(x <= 0) return ans;
        }
    }
    return -1;


}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T) cout << s_o() << endl;


    return 0;
}