#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n;

int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        string s;
        cin >> s;
        int flag = 0; 
        int f0 = -1, f1 = -1;
        for(int i = s.size() - 1; i; i--)
            if(s[i] == '0') {f0 = i; break;}
        for(int i = 0; i < s.size(); i++)
            if(s[i] == '1') {f1 = i; break;}
            
        if(f0 == -1 || f1 == -1 || f1 > f0) cout << 0 << endl;
        else {
            int cnt0 = 0, cnt1 = 0;
            for(int i = f0; i; i--) if(s[i] == '1') cnt1++;
            for(int i = f1; i < s.size(); i++) if(s[i] == '0') cnt0++;
            cout << min(cnt0, cnt1) << endl;
        }
    
    }

	return 0;
}
