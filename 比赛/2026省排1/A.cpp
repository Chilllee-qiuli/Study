#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n ;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        cout << n - x + 1 << " ";
    }
    cout << "\n";

    return 0;
}