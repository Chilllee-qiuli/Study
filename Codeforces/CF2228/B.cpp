#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        int n, x, y, k;
        cin >> n >> x >> y >> k;
        if (n <= 3) 
            cout << 1 << '\n';
        else {
            int d = abs(x - y);
            d = min(d, n - d);
            cout << d + k << '\n';
        }
    }

	return 0;
}
