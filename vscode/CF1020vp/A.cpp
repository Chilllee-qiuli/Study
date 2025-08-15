#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string str;
        cin >> str;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(str[i] == '1') ans += n - 1;
            else ans++;
        }
        cout << ans << endl;
    }

	return 0;
}
