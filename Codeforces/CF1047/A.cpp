#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll k, x;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> k >> x;
        for(int i = 1; i <= k; i++){
            x *= 2;
        }
        cout << x << endl;
    }

	return 0;
}
