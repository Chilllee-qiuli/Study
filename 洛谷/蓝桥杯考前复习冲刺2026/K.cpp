#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 100;
int a[maxn];
int ans[maxn];
int n, k;

void print(){
    for(int i = 1; i <= k; i++)
    cout << ans[i] << " ";
    cout << endl;
}

void dfs(int tot){
    if(tot > k){
        print(); 
        return;
    }

    for(int i = 1; i <= n; i++){
        if(a[i]) continue;
        a[i] = 1;
        ans[tot] = i;
        dfs(tot + 1);
        a[i] = 0;
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    dfs(1);
    return 0;
}