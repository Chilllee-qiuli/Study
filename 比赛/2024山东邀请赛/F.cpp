#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pr pair<ll, int>
#define mk make_pair
#define fi first 
#define se second
const int maxn = 5e5 + 10;
int a[maxn];
int n; 


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        ll sum = 0;
        vector<pr> vc;
        for(int i = n; i >= 2; i--){
            sum += a[i];
            vc.push_back(mk(sum, i));
        }
        sum += a[1];
        sort(vc.rbegin(), vc.rend());
        cout << sum << " ";
        for(int i = 0; i < n - 1; i++){
            sum += vc[i].fi;
            // cout << vc[i].se << " " << vc[i].fi << endl;
            cout << sum << " ";
        }
        cout << endl;
    }

	return 0;
}
 