#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 10;
int vis[maxn];
int t;
ll n, k;

int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        memset(vis, 0, sizeof(vis));
       // cout << "-------------" << endl;
        cin >> n >> k;
        if(n == 0) cout << k - 1 << endl;
        else if(n == 1) cout << k << endl;
        vector<int> vc;
        vc.push_back(0);
        ll x = 1;
        
        for(int i = 1, tmp = 0, fltmp = 0; i <= 31; i++){
            //if(n < x) break;
            if(n & x) tmp++;
            else {
                if(tmp) {
                    vc.push_back(tmp);
                    fltmp = 1;
                    tmp = 0;
                    //vc.push_back(0);
                }
                else if(fltmp)vc.push_back(0);
            }
            x <<= 1;
        }

        //for(int i = 1; i <= 100; i++) vc.push_back(0);

        /*for(int i = vc.size() - 1 ; i; i--)
        cout << vc[i];
        cout << endl;*/

        int maxx = 0;

        if(k == 1){
            for(int i = 1; i < vc.size(); i++)
            if(vc[i] > vc[maxx]) maxx = i;

            cout << vc[maxx] << endl;
            continue;
        }

        ll ans = 0;
        do{
            int cnt_1 = 0;
            for(int i = 1; i < vc.size(); i++){
                //if(i == 1) cout << "i = " << i << " " << vc[i] << endl;
                if(vc[i] == 1) cnt_1++;
                if(vc[i] > vc[maxx]) maxx = i;
            }
            //cout << "maxx = " << maxx << endl;
            if(cnt_1 == 1 && vc[maxx] == 1)break;
            k--;
            ans += vc[maxx];
            vc[maxx] = 0;
            vis[maxx] = 1;
            if(maxx == vc.size() - 1)
                vc.push_back(0);
            vc[maxx + 1] ++;
            if(vis[maxx + 1]) {
                ans++;
                vis[maxx + 1] = 0;
            }
        }while(k);
        ans += k;
        cout << ans << endl;
        
    }

	return 0;
}
