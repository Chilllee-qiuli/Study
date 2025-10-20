#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
ll a[maxn];
int n;



int main(){
    freopen("t.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    ll tmp = 0;
    for(int i = 1; i <= n * 2; i++) cin >> a[i];

    cout << a[8] - a[7] + a[6] - a[5] + a[4] - a[3] + a[2] - a[1] << endl;
    cout << endl;

    cout <<  a[8] + a[7] - a[6] - a[5] + a[4] + a[3] - a[2] - a[1] << endl;

    cout <<  a[8] - a[7] + a[6] + a[5] - a[4] - a[3] + a[2] - a[1] << endl;

    cout << a[8] - a[1] + a[7] - a[6] + a[5] - a[4] + a[3] - a[2] << endl;

    cout << endl;

    cout << a[8] + a[7] - a[2] - a[1] + a[4] - a[3] + a[6] - a[5] << endl;

    cout << a[8] + a[7] + a[6] - a[5] - a[4] - a[3] + a[2] - a[1] << endl;

    cout << a[8] - a[7] + a[6] + a[5] + a[4] - a[3] - a[2] - a[1] << endl; 

	return 0;
}
