#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mk make_pair
#define pr pair<int, int>
#define fi first 
#define se second
const int maxn = 6e5 + 120;
int n, k;
vector<pr> vc;

struct Cmp {
    bool operator()(const pr& x, const pr& y) const {
        return x.se > y.se;
    }
};
priority_queue<pr, vector<pr>, Cmp> qu;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    vc.push_back({0, 0});
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        int l, r;
        cin >> l >> r;
        vc.push_back({l, r});
    }
    sort(vc.begin() + 1, vc.end());

    int ans = 0;
    for(int i = 1; i <= n; i++){
        qu.push(vc[i]);
        while(qu.size() > k) qu.pop();
        if(qu.size() == k)
            ans = max(ans, qu.top().se - vc[i].fi);
    }

    cout << ans << endl;

    






	return 0;
}
