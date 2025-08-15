#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, q;
string str;
ll ans;

int main(){
   // freopen("e.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;
    cin >> str;
    str = "1" + str + "1";
    while(q--){
        ans = 0;
        int a;
        string t;
        cin >> t >> a;
        t = "1" + t + "2";
        //cout << str << endl;
        //cout << t << endl;
        int tmp = 0;
        for(int i = a, j = 1; j <= t.size() - 1; i++, j++){
            if(str[i] == t[j]) tmp++;
            else {
                ans += 1ll*(tmp + 1)*tmp/2;
                tmp = 0;
            }
        }
        cout << ans << endl;
    }

	return 0;
}
