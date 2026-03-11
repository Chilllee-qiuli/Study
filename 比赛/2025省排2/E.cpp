#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n, x;
int out;

void solve_one(){
    cin >> n >> x;
    n--;
    out = 0;
    for(int i = 1; i <= n; i++){
        int u, v;
        cin >> u >> v;
        if(u == x || v == x) out++;
    }

    if(out <= 1 || n & 1) cout << "Ayush\n";
    else cout << "Ashish\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) solve_one();

	return 0;
}
