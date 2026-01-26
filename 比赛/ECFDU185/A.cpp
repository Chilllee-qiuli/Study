#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n;

ll work(int a, int b, int c){
    return 0ll + a * n * n + b * n + c;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        if(n == 2) {
            cout << 9 << endl;
            continue;
        }

        cout << max({work(4, -4, 1), work(5, -5, -5), work(4, -1, -4), work(3, -1, -1)}) << endl;
        
    }

	return 0;
}