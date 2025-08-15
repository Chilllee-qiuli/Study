#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int t;
int n, k, a[maxn];

bool perish(int id){
    for(int i = id + 1; i <= n; i++){
        if(a[i] - a[i-1] > a[id]) return 0;
    }
    return 1; 
}

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++) cin >> a[i];
        int now = a[k];
        sort(a + 1, a + 1 + n);
        now = lower_bound(a + 1, a + 1 + n, now) - a;
        if(perish(now)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

	return 0;
}
