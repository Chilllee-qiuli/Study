#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int maxw = 0, maxh = 0;
        for(int i = 1, w, h; i <= n; i++){
            cin >> w >> h;
            maxw = max(maxw, w);
            maxh = max(maxh, h);
        }
        cout << maxw * 2 + maxh * 2 << endl;
    }

	return 0;
}
