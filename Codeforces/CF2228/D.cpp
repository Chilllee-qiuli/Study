#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pr pair<int, int>
#define mk make_pair
#define fi first 
#define se second
int t;
int n;
const int maxn = 2e6 + 10;
vector<int> xx, yy;
int cnt[maxn];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;

        vector<int> ().swap(xx);
        vector<int> ().swap(yy);

        for(int i = 1; i <= n; i++){
            int x, y;
            cin >> x >> y;
            yy.push_back(y);
            xx.push_back(x);
            cnt[x]++;
        }

        sort(xx.begin(), xx.end());
        sort(yy.begin(), yy.end());
        xx.erase(unique(xx.begin(), xx.end()), xx.end());
        yy.erase(unique(yy.begin(), yy.end()), yy.end());
        
        if(xx.size() < 2) { cout << 0 << endl; continue; }

        int flag = 0;
        for(int i = 1; i < xx.size() - 1; i++){

        }


        ll ans = 1ll * (xx.size() - 1) * (yy.size() - 1);

        
        cout << ans << endl;

    }

	return 0;
}
