#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int a[maxn];
int n, m;

bool work(int x){
    int tmp = 1, l = a[1];
    for(int i = 2; i <= n; i++){
        if(a[i] - l >= x) l = a[i], tmp++;
    }
    if(tmp >= m) return 1;
    else return 0;
}

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);


    int l = 1, r = 1e9 + 1;
    int ans = 1;
    while(l < r){
        int mid = (l + r)/2;
        if(work(mid)) ans = mid, l = mid + 1;
        else r = mid;
    }
    cout << ans << endl;
    //cout << work(8) << endl;


	return 0;
}