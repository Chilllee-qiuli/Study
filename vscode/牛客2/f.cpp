#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int n, t;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n >> t;
        string str;
        cin >> str;

        int cnt = 0;
        int max_cnt = 0;
        int last_fire = 0, first_fire = 0;
        ll ans = 0;
        for(int i = 0; i < n; i++) if(str[i] == '1') {first_fire = i; break;}

        for(int i = first_fire + 1; i < n; i++){
            if(str[i] == '0') cnt++;
            else {
                max_cnt = max(cnt, max_cnt);
                last_fire = i;
                ans += max(0, cnt-t*2);
                cnt = 0;
            }
        }

        str = str + str;
        // cout << "maxcnt: " << max_cnt << endl;
        cnt = 0;
        if(!last_fire) last_fire = first_fire;
        // if(first_fire != last_fire)
        for(int i = last_fire + 1; i <= str.size() - 1; i++){
            if(str[i] == '0') cnt++;
            else {
                max_cnt = max(cnt, max_cnt);
                ans += max(0, cnt-t*2);
                break;
            }
            // cout << "str[" << i << "] = " << str[i] << " cnt: " << cnt << endl;
        }
        ans -= max(0, max_cnt-t*2);
        // cout << "maxcnt: " << max_cnt << endl;
        ans += max(0, max_cnt-1-t);
        cout << ans << endl;
    }

	return 0;
}
