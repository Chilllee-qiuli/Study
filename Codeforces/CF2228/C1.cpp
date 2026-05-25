#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pr pair<int, int>
#define mk make_pair
#define fi first 
#define se second
int t;
ll a;
int n;
int d[15];
int m;
int bit[20];

ll solve(int idx, int flag, ll ans){
    if(!idx) return ans;
    int x = d[0], y = d[1];
    int now = bit[idx];
    if(!flag){

        if(a == x) return solve(idx - 1, flag, ans * x);
        else if(a == y) return solve(idx - 1, flag, ans * y);    
        else if(a > y) return solve(idx - 1, -1, ans * y); // 偏小
        else if(a < x) return  solve(idx - 1, 1, ans * x); // 偏大
        else if(abs(y - a) > abs())
        
    }
    else {

    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> a >> n;
        for(int i = 1; i <= n; i++) cin >> d[i];
        m = 0;
        
        ll b = a;
        while(b){
            bit[++m] = b % 10;
            b /= 10;
            m++;
        }

        if(a == 0) cout << d[0] << "\n";
        else {
            solve(m, 0);
            cout << ans << endl;
        }


    }


	return 0;
}
