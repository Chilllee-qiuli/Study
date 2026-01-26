#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 10;
int n, low[maxn], a[maxn], lis, head[maxn], idx[maxn];

void dfs(int id){
    if(id == 0) return ;
    dfs(head[id]);
    cout << a[id] << " ";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    low[0] = - inf;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        if(a[i] > low[lis]){
            low[++lis] = a[i];
            head[i] = idx[lis-1];
            idx[lis] = i;
        }
        else
        {
            int p = lower_bound(low+1, low+1+lis, a[i]) - low;
            low[p] = a[i];
            idx[p] = i;
            head[i] = idx[p-1];
        }
    }
    cout << lis << endl;
    dfs(idx[lis]);
    return 0;
}