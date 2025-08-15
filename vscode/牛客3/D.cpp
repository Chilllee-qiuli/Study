#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n, a;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> a;
        string str;
        cin >> str;
        int max_len1 = 0, max_len0 = 0, len1 = 0, len0 = 0, cnt = 0;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '1') {len1++; cnt++; max_len0 = max(max_len0, len0); len0 = 0;}
            else {len0++; max_len1 = max(max_len1, len1); len1 = 0;}
        }
        if(len0) max_len0 = max(max_len0, len0);
        else max_len1 = max(max_len1, len1);
        if(max_len1 >= a || max_len0 >= a + 1) cout << n << endl;
        else {
            cout << cnt << endl;
        }
    }

	return 0;
}
