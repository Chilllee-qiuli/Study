#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, low[10086], a[10086], lis = 0, pre[10086];//pre为前缀
ll ans[100086];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; i++)
        cin >> a[i];
    for(ll i = 1; i <= n; i++)
    {
        if(a[i] > low[lis])
        {
            low[++lis] = a[i];
//            pre[a[i]] = low[lis-1];
            pre[lis] = a[i];
        }
        else
        {
            int x = a[i];
            int p = lower_bound(low+1, low+1+lis, x) - low;
            low[p] = x;
            //pre[a[i]] = low[p-1];
            pre[p] = a[i];
        }
    }
    //cout << lis << endl;
//    for(ll i = 1; i <= lis; ++i)
//        ans[i] = pre[low[i]];
    for(ll i = 1; i <= lis; ++i)
//        cout << ans[i] << " ";
        cout << pre[i] << " ";
    return 0;
}