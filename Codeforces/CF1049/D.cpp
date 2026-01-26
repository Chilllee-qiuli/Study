#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5;
int t;

map< pair<ll, ll>, ll> cnt, tol;

struct nodel{
    ll l, r;
};
bool operator < (nodel x, nodel y){
    return x.l == y.l ? x.r > y.r : x.l > y.l; 
    // l小的在前面，l相等r的在前面
}
struct noder{
    ll l, r;
};
bool operator < (noder x, noder y){
    return x.r == y.r ? x.l < y.l : x.r < y.r;
    // r小的在前面，r相等l小的在前面
};


priority_queue< nodel> lf;
priority_queue<noder> rh;

ll ans;
int n;

void clear_two(){
    while(!lf.empty() && cnt[{lf.top().l, lf.top().r}] >= tol[{lf.top().l, lf.top().r}]){
        //cout << "clear left " << lf.top().l << " " << lf.top().r << endl;
        lf.pop();
    }
    
    while(!rh.empty() && cnt[{rh.top().l, rh.top().r}] >= tol[{rh.top().l, rh.top().r}]){
        //cout << "clear right " << rh.top().l << " " << rh.top().r << endl;
        rh.pop();
    }
            
}

int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        ans = 0;
        cin >> n;
        while(!lf.empty()) lf.pop();
        while(!rh.empty()) rh.pop();
        cnt.clear();
        tol.clear();
        for(int i = 1, l, r; i <= n; i++){
            cin >> l >> r;
            nodel tmpl = {l, r};
            noder tmpr = {l, r};
            lf.push(tmpl);
            rh.push(tmpr);
            tol[{l, r}]++;
        }

        ll ans = 0;
        while(!lf.empty() && !rh.empty()){            
            while(!lf.empty() && cnt[{lf.top().l, lf.top().r}] >= tol[{lf.top().l, lf.top().r}]){
                lf.pop();
            }   
            if(lf.empty() || rh.empty()) break;
            pair<ll, ll> tmpl = {-1, -1};
            if(!lf.empty()) {
                tmpl = {lf.top().l, lf.top().r};
                cnt[{lf.top().l, lf.top().r}]++;
            }

            while(!rh.empty() && cnt[{rh.top().l, rh.top().r}] >= tol[{rh.top().l, rh.top().r}]){
                rh.pop();
            }
            if(rh.empty()) {
                cnt[{lf.top().l, lf.top().r}]--;
                break;
            }
            
            pair<ll, ll> tmpr = {-1, -1};
            if(!rh.empty()) {
                tmpr = {rh.top().l, rh.top().r};
                cnt[{rh.top().l, rh.top().r}]++;
            }
            if(lf.empty() || rh.empty()) break;
            //cout << "test " << endl;
            //cout << tmpl.first << " " << tmpl.second << " " << tmpr.first << " " << tmpr.second << endl;

            ans += tmpl.second - tmpl.first + tmpr.second - tmpr.first + max(abs(tmpl.first - tmpr.second), abs(tmpl.second - tmpr.first));
            //cout <<"ans: " << ans << endl;
            lf.pop();
            rh.pop();
        }

        clear_two();

        if(!lf.empty()){
            ans += lf.top().r - lf.top().l;
            lf.pop();
        }
        if(!rh.empty()){
            ans += rh.top().r - rh.top().l;
            rh.pop();
        }
        cout << ans << endl;
    }

	return 0;
}
