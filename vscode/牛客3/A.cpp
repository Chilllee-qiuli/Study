#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1500;
int t;
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1, x; i <= n; i++){
            cin >> x;
            
            for(int tmp = 0; tmp < x; tmp++) cout << tmp << " ";
            for(int j = x + 1; j <= n; j++) cout << 0 << " ";
            cout << endl;
        }
    }

	return 0;
}