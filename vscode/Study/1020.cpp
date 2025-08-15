#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
int n, low[100086], a[100086], lis = 0, pre[100086];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> n;
    low[0] = inf;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        if(a[i] < low[lis])
        {
            low[++lis] = a[i];
            pre[lis] = a[i];
        }
        else
        {
            int x = a[i];
            int p = lower_bound(low + 1, low + 1 + lis, x, std::greater<int>()) - low;
            low[p] = x;
            pre[p] = a[i]; // ! 
        }
    }
    cout << lis << endl;
    for(int i = 1; i <= lis; ++i)
        cout << pre[i] << " ";
    return 0;
}