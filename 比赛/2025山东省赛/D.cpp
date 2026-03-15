#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int T;
int n, q;
ll w[maxn];
void solve_one();

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T;
    while(T--) solve_one();

	return 0;
}

void solve_one(){
    cin >> n >> q;
    for(int i = 0; i <= n; i++) w[i] = 0;
    for(int i = 1; i <= q; i++){
        int a, b;
        cin >> a >> b;
        int cnt = a / n;
        a %= n;
        w[0] += cnt;
        w[n] -= cnt;
        if(b + a <= n) {
            w[b] += 1;
            w[b + a] -= 1;
        }
        else{
            w[b]++;
            w[n]--;
            int len = a - (n - b);
            w[0]++;
            w[len]--;
        }
    }

    for(int i = 0; i < n; i++){
        if(i > 0) w[i] += w[i - 1];
        cout << w[i] << " ";
    }
    cout << endl;

}