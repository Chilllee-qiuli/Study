#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;

void solve_one(){
    int n;
    int maxx = 0;
    int ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(x > maxx){
            maxx = x;
            ans = 1;
        }
        else if(x == maxx) ans++;
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--) solve_one();


	return 0;
}
