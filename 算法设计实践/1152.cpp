#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 10;
int n;
int a[maxn];
vector<int> tmp;
priority_queue<ll, vector<ll>, greater<ll> > pr;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        pr.push(x);
    }
    ll ans = 0;

    while(pr.size() > 1){
        ll x = pr.top(); pr.pop();
        ll y = pr.top(); pr.pop();
        tmp.push_back(x + y);
        pr.push(x + y);
        ans += x + y;
    }
    cout << ans << "\n";


   


	return 0;
}