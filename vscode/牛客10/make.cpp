#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    freopen("e.in", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    struct _timeb T;
    _ftime(&T);
    srand(T.millitm);

    int t = 100;
    cout << t << endl;
    while(t--){
        int n = 10;
        cout << n << " " << 1 << endl;
        for(int i = 1; i <= n; i++) {
            int m = rand() % 10;
            cout << m << " ";
        }
        cout << endl;
    }
    

	return 0;
}
