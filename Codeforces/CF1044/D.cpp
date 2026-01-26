#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t;
int n;
int h[maxn];


int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int maxh = 0, maxid = 0;
        ll total = 0;
        for(int i = 1; i <= n; i++) {
            cin >> h[i];
            total += h[i];
        }

        cout << total - n + 1 << endl;



    }

	return 0;
}