#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 110;
int t;
int cnt[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> vc;
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i <= n; i++) {
            int x; cin >> x;
            cnt[x]++;
        }
        int flag = 101;
        for(int i = 0; i <= 101; i++){
            if(!cnt[i]) {
                flag = i;
                break;
            }
        }
        cout << flag << endl;
    }

	return 0;
}
