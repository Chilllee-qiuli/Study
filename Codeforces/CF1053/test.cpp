#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int a[maxn];
int t;
int n;
ll work(int x, int k){
    ll tmp = 0;
    for(; x + k * 2 <= n * 2; x += k * 2){
        for(int i = x; i < x + k; i++) tmp += a[i + k] - a[i];
    } 
    for(int i = x; i <= n; i+=2) tmp += a[i + 1] - a[i];
    return tmp;
}

int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1 ; i <= n * 2; i++) cin >> a[i];
        for(int k = 1; k <= n; k++){
            cout << "k: " << k << endl; 
            ll tmp = 0;
            
            for(int i = 0; i < k; i++){
                cout << tmp + work(i * 2 + 1, k) << " "; 
                tmp += a[i];
            }
        }
    }

	return 0;
}
