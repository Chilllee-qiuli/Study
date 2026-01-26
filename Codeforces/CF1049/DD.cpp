#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 2e5;

int t;
int n;

struct node{
    ll l, r;
}a[maxn], b[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        ll ans = 0;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i].l >> a[i].r;
            ans += a[i].r - a[i].l ;
            b[i].l = a[i].l;
            b[i].r = a[i].l + a[i].r;
        }
        sort(b + 1, b + n + 1, [](node x, node y){
            return x.r > y.r;
        });

         if(n % 2 == 0){
            for(int i = 1; i <= n / 2; i++){
                ans += b[i].r - b[i].l;
            }
        }
    }





    return 0;
}


