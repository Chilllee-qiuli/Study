#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const int inf = 0x3f3f3f3f;
int t;
int n, k;
int a[maxn], b[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        int mina = inf, maxa = -inf;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            mina = min(mina, a[i]);
            maxa = max(maxa, a[i]);
        }
        int flag = -1, cnt = 0;
        for(int i = 1; i <= n; i++) {
            cin >> b[i];
            if(flag == -2) continue;
            else if(b[i] == -1) cnt++;
            else if(flag == -1) flag = a[i] + b[i];
            else if(a[i] + b[i] != flag) flag = -2;
        }
        if(flag == -2) cout << 0 << endl;
        else if(cnt != n && (mina + k < flag || maxa > flag)) cout << 0 << endl;
        else if(cnt != n) cout << 1 << endl;
        else {
            cout << mina + k - maxa + 1 << endl;
        }

    }

	return 0;
}