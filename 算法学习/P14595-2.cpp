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
vector<int> lisan;
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
        lisan.push_back(l);
        lisan.push_back(r);
        vc.push_back({l, r});
    }
    lisan.push_back(-1);
    sort(lisan.begin(), lisan.end());

    for(int i = 1; i <= n; i++){
        vc[i].first = lower_bound(lisan.begin(), lisan.end(), vc[i].first) - lisan.begin();
        vc[i].se = lower_bound(lisan.begin(), lisan.end(), vc[i].se) - lisan.begin();
    }

    for(int i = 1; i <= n; i++){
        
    }

    






	return 0;
}
