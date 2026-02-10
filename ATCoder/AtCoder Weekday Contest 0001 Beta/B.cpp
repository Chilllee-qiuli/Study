#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, l, r;
    cin >> n >> l >> r;
    int ans = -1, ans_p = -1;
    for(int i = 1; i <= n; i++){
        int p;
        cin >> p;
        if(l <= p && p <= r && p > ans_p){
            ans = i;
            ans_p = p;
        }
    }

    cout << ans << endl;

	return 0;
}
