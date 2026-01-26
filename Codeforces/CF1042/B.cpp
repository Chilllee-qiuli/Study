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
        if(n == 2){
            cout << -1 << " " << 2 << endl;
            continue;
        }
        for(int i = 1; i <= n; i++){
            if(i & 1) cout << -1 << " ";
            else if(i != n) cout << 3 << " ";
            else cout << 2 << " ";
        }
        cout << endl;
    }

	return 0;
}
