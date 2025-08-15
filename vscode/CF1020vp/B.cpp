#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n, x;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> x;
        if(x == 0){
            for(int i = 1; i < n; i++) cout << i << " ";
            cout << 0 << endl;
        }
        else {
            for(int i = 0; i < x; i++) cout << i << " ";
            for(int i = x + 1; i < n; i++) cout << i << " ";
            if(x != n) cout << x << endl;
            else cout << endl;
        }
    }

	return 0;
}
