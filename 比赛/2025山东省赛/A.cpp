#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int T;
int n;
int dp = 0;


struct per{
    int a, b, id;
    friend bool operator < (per x, per y){
        return x.a == y.a ? x.b > y.b : x.a > y.a; 
    }
}p[maxn];
vector<per>ans;

void solve_one();
void work(vector<per> vc);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T;
    while(T--) solve_one();

	return 0;
}

void work(vector<per> vc){
    int cnt = 0;
    int tmp_dp = dp;
    int delta = 0;
    for(auto it : vc){
        cnt++;
        int comp = min(tmp_dp, it.b) + cnt;
        if(comp > dp){
            dp = comp;
            while(ans.size() > it.b) ans.pop_back();
            delta = cnt;
        }
    }

    for(auto it : vc){
        if(!delta) break;
        ans.push_back(it);
        delta--;
    }

}

void solve_one(){
    cin >> n;
    dp = 0;
    for(int i = 1; i <= n; i++){
        cin >> p[i].a >> p[i].b;
        p[i].id = i;
    }
    sort(p + 1, p + 1 + n);
    p[n + 1].a = 0;

    vector<per> vc;
    vector<per> ().swap(ans);
    for(int i = 1; i <= n; i++){
        vc.push_back(p[i]);
        if(p[i].a != p[i + 1].a) {
            work(vc);
            vector<per> ().swap(vc);
            //cout << "a = " << p[i].a << " dp = " << dp << endl;
        }
    }

    cout << dp << endl;

    for(auto it : ans){
        cout << it.id << " ";
    }
    cout << "\n";

    
}