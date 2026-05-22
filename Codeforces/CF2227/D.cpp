#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int a[maxn];
int vis[maxn];
int t;
int n;

int wk1(int l, int r){
    int flag = 1;
    int ans = 1;
    // cout << l << " " << r << endl; 
    for(int i = l, j = r; i <= j; i++, j--){
        if(a[i] != a[j]){flag = 0; break;}
        vis[a[i]] = 1;
    }
    // cout << flag << endl;
    if(!flag) return 1;
    
    while(l > 1 && r < 2 * n){
        if(a[l - 1] == a[r + 1]){
            l--; r++;
            vis[a[l]] = 1;
        }
        else break;
    }
     

    for(int i = 1; i <= n; i++)
        if(vis[i]) ans++;
        else break;
    
    return ans;
}
void pre(){
    for(int i = 1; i <= 2 * n; i++) vis[i] = 0;
}

int wk2(int x){
    int l = x, r = x;
    while(l > 1 && r < 2 * n){
        if(a[l - 1] != a[r + 1]) break;
        l--; r++;
        vis[a[l]] = 1;
    }
    int ans = 1;
    for(int i = 1; i <= n; i++)
        if(vis[i]) ans++;
        else break;
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        int l = 0, r = 0;
        for(int i = 1; i <= n * 2; i++) {
            cin >> a[i];
            if(!a[i]){
                if(!l) l = i;
                else r = i;
            }
            vis[i] = 0;
        }
        pre();
        int ans1 = wk1(l, r);
        pre();
        int ans2 = wk2(l);
        pre();
        int ans3 = wk2(r);
        cout << max({ans1, ans2, ans3}) << endl;
    }

	return 0;
}
