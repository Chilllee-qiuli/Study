#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 110;
const int inf = 0x3f3f3f3f;
int t;
int n;
int a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int maxx = -inf, minn = inf;
        for(int i = 1; i <=n; i++){
            cin >> a[i];
            maxx = max(maxx, a[i]);
            minn = min(minn, a[i]);
        }
        cout << maxx - minn << endl;
    }

	return 0;
}
