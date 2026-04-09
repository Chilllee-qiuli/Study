#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e6 + 10;
int a[maxn];
int tmp[maxn], tot;
int ans[maxn];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++){
        while(tot && a[i] > a[tmp[tot]]) {
            ans[tmp[tot]] = i;
            --tot;
        }
        tmp[++tot] = i;
    }

    while(tot){
        ans[tmp[tot--]] = 0;
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
    



    return 0;
}