#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, d;



void solve_one(){
    cin >> n >> m >> d;
    int cnt = d / m + 1;
    cout << ceil(1.0 * n / cnt) << "\n"; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int T;
    cin >> T;
    while(T--) solve_one();



	return 0;
}
