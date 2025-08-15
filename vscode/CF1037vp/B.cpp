#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int a[maxn];
int t, n, k;

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;

    while(t--){
        cin >> n >> k;
        int ans = 0;

        for(int i = 1; i <= n; i++) cin >> a[i];

        for(int i = 1, tmp = 0; i <= n; i++){
            if(a[i]) tmp = 0;
            else tmp++;
            if(tmp == k) {tmp = 0; ans++; a[i+1] = 1;}
        }

        cout << ans << endl;


    }


    
	return 0;
}
