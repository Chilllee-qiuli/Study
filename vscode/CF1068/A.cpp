#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n, k;
string str;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> k;
        cin >> str;
        int flag = 0;
        int ans = 0;
        for(auto ch : str){
            if(ch == '1') flag = k;
            else if(flag) flag--;
            else ans++;
        }        
        cout << ans << endl;

    }


	return 0;
}
