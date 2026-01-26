#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int mp[110];
int t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int flag = 0;
        memset(mp, 0, sizeof(mp));
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            mp[x]++;
            if(mp[x] >= 2) flag = 1;
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

	return 0;
}