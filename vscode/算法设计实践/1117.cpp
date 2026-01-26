#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
int n, k;
int a[maxn];
int tmp[maxn];

int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];

    int l = 0, r = 0;
    for(int i = 1; i <= n; i++){
        while(l <= r && tmp[l] < i - k + 1) l++;
        while(l <= r && a[i] > a[tmp[r]]) r--;
        tmp[++r] = i;
        if(i >= k) cout << a[tmp[l]] << endl;
    }

	return 0;
}