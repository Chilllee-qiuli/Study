#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n;

void so(){
    cin >> n;
    if(n & 1){
        cout << n - 1 << " ";
        for(int i = 2; i <= n - 1; i++){
            if(i & 1) cout << i - 1 << " ";
            else cout << i + 1 << " ";
        }
        cout << 1 << endl;
    }
    else {
        cout << n << " " ;
        for(int i = 2; i <= n - 1; i++)
            if(i & 1) cout << i - 1 << " ";
            else cout << i + 1 << " ";
        cout << 1 << endl;
    }
    
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--) so();

    return 0;
}