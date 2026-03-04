#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n;
string s;
vector<int> vc;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        cin >> s;
        vc.clear();
        s = 'a' + s;
        int cnt = 0; // cnt1
        for(int i = 1; i <= n; i++) {
            if(s[i] == '1') vc.push_back(i);
        }

        if(vc.size() % 2 == 0){
            cout << vc.size() << endl;
            for(auto v : vc) cout << v << " ";
        }
        else if((n - vc.size()) % 2 == 1){
            cout << n - vc.size() << endl;
            for(int i = 1; i <= n; i++){
                if(s[i] == '0') cout << i << " ";
            }
        }
        else cout << -1;
        cout << "\n";
    }

	return 0;
}
