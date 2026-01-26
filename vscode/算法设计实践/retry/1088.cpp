#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e4 + 10;
int n;
int a[maxn], tmp[maxn], cnt;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++){
        if(a[i] > tmp[cnt]) tmp[++cnt] = a[i];
        else {
            int id = lower_bound(tmp + 1, tmp + 1 + cnt, a[i]) - tmp;
            tmp[id] = a[i];
        }
    }

    cout << cnt << endl;

	return 0;
}