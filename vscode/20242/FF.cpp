#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n;
ll c[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    ll tmp = 1500;

    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i <= n; i++){
        tmp += c[i];
        if(tmp >= 4000){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;

	return 0;
}