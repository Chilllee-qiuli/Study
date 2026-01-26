#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 10;
int n, k;

struct tme{
    int l, r;
    bool operator < (tme y){
        return r < y.r;
    }
}t[maxn];
priority_queue<tme> qu;

bool cmp(tme x, tme y){
    return x.l < y.l;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;

    for(int i = 1; i <= n; i++)
        cin >> t[i].l >> t[i].r;
    
    sort(t + 1, t + 1 + n, cmp);
    
    int ans = 0;
    if(k >  0){
        for(int i = 1; i <= n; i++)
        ans = max(ans, t[i].r - t[i].l);
        cout << ans << endl;
    }


	return 0;
}
