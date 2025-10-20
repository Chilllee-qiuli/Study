#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 220;
int a[maxn];
int t;
int n, m;

int main(){
   // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> m;
        int flag = 0;
        for(int i = 1; i <= m; i++){
            cin >> a[i];
            if(i > 1 && a[i] != a[i - 1] + 1) flag = 1;
        }
        if(flag) cout << 1 << endl;
        else cout << n - a[m] + 1 << endl;
    }

	return 0;
}
