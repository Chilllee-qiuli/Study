#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T;
    while(T--){
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector<int> l, r;
        int cnt = 0;
        for(auto ch : s){
            if(ch == '(') cnt++;
            else if(cnt) l.push_back(cnt), cnt--;
        }
        cnt = 0;
        for(auto ch : t){
            if(ch == '(') cnt++;
            else if(cnt) r.push_back(cnt), cnt--;
        }
        sort(l.begin(), l.end());
        sort(r.begin(), r.end());
        int flag = 1;
        if(l.size() != r.size()) flag = 0;
        else
        for(int i = 0; i < l.size(); i++){
             cout << l[i] << " ";
            if(l[i] != r[i]){
                flag = 0;
                // break;
            }
        }   
        cout << endl;
        for(auto it : r) cout << it << " ";
        cout << endl;
        if(flag) cout << "yes\n";
        else cout << "no\n";
    }

	return 0;
}
