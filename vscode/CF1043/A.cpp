#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        string a, b, c;
        cin >> a;
        cin >> m;
        cin >> b >> c;
        for(int i = 0; i < m; i++)
            if(c[i] == 'D') a += b[i];
            else a = b[i] + a;

        cout << a << endl;
    }

	return 0;
}
