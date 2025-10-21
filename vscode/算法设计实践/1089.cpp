#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[10100];
int b[10100];
int ans[10100];

int find(int x){
    int tmp = 0;
    for(int i = 1; i <= n; i++){
    if(!b[i] && tmp == x) return i;
        if(!b[i]) tmp++;
    }
    return -1;
}

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = n; i >= 1; i--){
        int x = find(a[i]);
        b[x] = 1;
        ans[i] = x;
    }
    for(int i = 1; i <= n; i++) 
        cout << ans[i] << " \n"[i == n];
    

	return 0;
}