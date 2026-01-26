#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n, ex, ey;

int main(){
   // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> ex >> ey;
        string str;
        cin >> str;
        int cnt4 = 0, cnt8 = 0;
        for(auto it : str){
            if(it == '4') cnt4++;
            else cnt8++;
        }
        ex = abs(ex), ey = abs(ey);
        
        if(max(ex, ey) <= cnt8) cout << "Yes" << endl;
        else if(max(ex - cnt8, 0) + max(ey - cnt8, 0) <= cnt4) cout << "Yes" << endl;
        else cout << "No" << endl;

    }

	return 0;
}
