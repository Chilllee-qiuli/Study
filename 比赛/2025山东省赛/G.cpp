#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int T;
int n, k;

int a[maxn];


void solve_one();

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T;
    while(T--) solve_one();

	return 0;
}

void solve_one(){

    cin >> n >> k;

    for(int i = 1; i <= n; i ++){
        int w, t;
        cin >> w >> t;
        t = t + k - w;
        a[i] = t;
    }
    sort(a + 1, a + 1 + n);

    int cnt = 1;
    for(int i = 2; i <= n; i++){
        if(a[i] == a[i - 1]) {cnt++; continue;}
        int delta = a[i] - a[i - 1];
        cnt = max(0, cnt - delta);
        cnt++;
    }

    cout << a[n] + cnt - 1 << endl;

    

}