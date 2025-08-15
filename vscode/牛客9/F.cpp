#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e17 + 10;
int t;

ll work(ll sx1, ll sy1, ll sx2, ll sy2, ll tx1, ll ty1, ll tx2, ll ty2)
{
    ll dis = 0;
    if (sx1 == sx2 && tx1 == tx2)
    {
        dis = max(abs(tx2 - sx1), abs(max(ty1, ty2) - max(sy1, sy2)));
        return dis * 2;
    }
    else if (sy1 == sy2 && ty1 == ty2)
    {
        dis = max(abs(ty1 - sy1), abs(max(tx1, tx2) - max(sx1, sx2)));
        return dis * 2;
    }
    return -1;
}   

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        ll sx1, sy1, sx2, sy2, tx1, ty1, tx2, ty2;
        cin >> sx1 >> sy1 >> sx2 >> sy2 >> tx1 >> ty1 >> tx2 >> ty2;
        ll dis = 0 ;
        if(sx1 == sx2 && tx1 == tx2)
            cout << work(sx1, sy1, sx2, sy2, tx1, ty1, tx2, ty2) << endl;
        else if(sy1 == sy2 && ty1 == ty2)
            cout << work(sx1, sy1, sx2, sy2, tx1, ty1, tx2, ty2) << endl;
        else if(sx1 == sx2 && ty1 == ty2){

            ll ans = inf;
            ans = min(ans, work(sx1, sy1, sx2, sy2, tx1, ty1, tx1, ty1 + 1));
            ans = min(ans, work(sx1, sy1, sx2, sy2, tx1, ty1, tx1, ty1 - 1));
            ans = min(ans, work(sx1, sy1, sx2, sy2, tx2, ty2 + 1, tx2, ty2));
            ans = min(ans, work(sx1, sy1, sx2, sy2, tx2, ty2 - 1, tx2, ty2));

            ans++;
            cout << (ans == inf ? -1 : ans) << endl;
        } 
        else if(sy1 == sy2 && tx1 == tx2){

            ll ans = inf;
            if(ty1 > ty2) {swap(tx1, tx2); swap(ty1, ty2);}
            ans = min(ans, work(sx1, sy1, sx2, sy2, tx1, ty1, tx1 + 1, ty1));
            ans = min(ans, work(sx1, sy1, sx2, sy2, tx1, ty1, tx1 - 1, ty1));
            ans = min(ans, work(sx1, sy1, sx2, sy2, tx2 + 1, ty2, tx2, ty2));
            ans = min(ans, work(sx1, sy1, sx2, sy2, tx2 - 1, ty2, tx2, ty2));
            ans++;
            cout << (ans == inf ? -1 : ans) << endl;
        } else {
            cout << -1 << endl;
        }
    }

	return 0;
}