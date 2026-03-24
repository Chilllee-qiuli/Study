#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n, d;

struct node{
    ll money, fr;
    friend bool operator < (node x, node y){
        return x.money < y.money;
    }
}f[maxn];

queue<int> qu;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> d;
    for(int i = 1; i <= n; i++){
        cin >> f[i].money >> f[i].fr;
    }
    sort(f + 1, f + 1 + n);
    ll ans = 0, now = 0;

    for(int i = 1; i <= n; i++){
        while(!qu.empty() && f[qu.front()].money + d <= f[i].money) {
            now -= f[qu.front()].fr;
            qu.pop();
        }
        qu.push(i);
        now += f[i].fr;
        ans = max(ans, now);
    }

    cout << ans << endl;


    return 0;
}