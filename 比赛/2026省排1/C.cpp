#include<bits/stdc++.h>
using namespace std;
#define pr pair<int, int>
typedef long long ll;

const int maxn = 2e5 + 10;
int a[maxn];
int n;
vector<int > qu;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
       cin >> n;
       int ans = 0;
       for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if(i > 1) {
                if(abs(a[i] - a[i - 1]) >= 2) ans = i - 1;
            } 
       }

       if(ans){
            cout << "YES\n";
            cout << ans << " " << ans + 1 << "\n"; 
       }
       else cout << "NO\n" ;
    }



    return 0;
}