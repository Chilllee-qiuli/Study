#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 110;
int t;
int tag1[maxn];
int tag2[maxn];
int ans[maxn];
int used[maxn];
int n, k, q;
vector< pair<int, int> > vc;
bool cmp(pair<int, int> x, pair<int, int> y){
    return x.first == y.first ? x.second < y.second : x.first < y.first;
}


int main(){
    //freopen("1.in", "r", stdin);
    //ios::sync_with_stdio(0);
    //cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        memset(tag1, 0, sizeof(tag1));
        memset(tag2, 0, sizeof(tag2));
        //vc.clear();
        //cout << "---------------" << endl;
        cin >> n >> k >> q;
        for(int i = 1; i <= n; i++) ans[i] = -1;
        while(q--){
            int c, l, r;
            cin >> c >> l >> r;
            if(c == 1) for(int i = l; i <= r; i++) tag1[i] = 1;
            else {
                for(int i = l; i <= r; i++) tag2[i]++;
                //vc.push_back(make_pair(l, r));
            }
        }
        //sort(vc.begin(), vc.end(), cmp);
            
        
            for(int i = 1; i <= n; i++) {
                if(!tag1[i]) continue;
                if(tag2[i]) ans[i] = k + 1;
                else ans[i] = k;
            }

        for(int i = 1; i <= n; i++){
            if(ans[i] != -1) cout << ans[i] << " ";
            else cout << i % k << " ";
        }
        cout << endl;
        
    }

	return 0;
}
