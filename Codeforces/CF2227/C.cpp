#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int a[maxn];
int t;
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        vector<int> vc;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++){
            if(a[i] % 6 == 0) vc.push_back(a[i]);
        }
        for(int i = 1; i <= n; i++){
            if(a[i] % 6 == 0) continue;
            if(a[i] % 3 == 0) vc.push_back(a[i]);
        }
        for(int i = 1; i <= n; i++){
            if(a[i] % 6 == 0 || a[i] % 3 == 0) continue;
            if(a[i] % 2 != 0) vc.push_back(a[i]);
        }
        for(int i = 1; i <= n; i++){
            if(a[i] % 6 == 0 || a[i] % 3 == 0) continue;
            if(a[i] % 2 == 0) vc.push_back(a[i]);
        }
        for(auto it : vc) cout << it << " ";
        cout << endl;

    }

	return 0;
}
