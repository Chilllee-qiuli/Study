#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
int h[maxn], w[maxn];
int n;
ll ans[maxn];

vector<int> qu;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> h[i] >> w[i];
    
    for(int i = 1; i <= n; i++){
        while(!qu.empty() && h[i] > h[qu.back()]){
            int x = qu.back();
            qu.pop_back();
            // x 的右边最近更高是 i
            ans[i] += w[x];
            // x 的左边最近更高是弹出后的栈顶
            if(!qu.empty()) ans[qu.back()] += w[x];
        }
        qu.push_back(i);
    }

    ll maxx = 0;
    for(int i = 1; i <= n; i++) 
        maxx = max(maxx, ans[i]);
    
    cout << maxx << endl;

	return 0;
}
