#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int a[maxn], b[maxn];
int t;
int n;
int p[maxn * 10], cnt;
int spf[maxn * 10]; // 最小质因子
bitset<maxn * 10> vis;
void prime(){
    spf[1] = 1;
	for(int i = 2; i < maxn * 10 - 2; i++){
        if(!vis[i]) {
            p[++cnt] = i;
            spf[i] = i;
        }
        for(int j = 1; j <= cnt && 1ll * i * p[j] < maxn * 10 - 2; j++){
            vis[i * p[j]] = 1;
            spf[i * p[j]] = p[j];
            if(i % p[j] == 0) break;
        }
    }
}

bool judge(){
    for(int i = 1; i < n; i++)
    if(a[i] > a[i + 1]) return 0; 
    return 1; // 没有下降
}

void solve_one(){
    cin >> n;
    b[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        int x = a[i];
        int maxx = 0;
        while(x > 1){
            maxx = max(maxx, spf[x]);
            x /= spf[x];
        }
        b[i] = max(b[i - 1], maxx);
    }
    if(judge()){
        cout << "Bob" << "\n";
        return ;
    }
    int minn = spf[a[n]], flag = 0;
    for(int i = n; i; i--){
        minn = min(minn, spf[a[i]]);
        if(b[i] > minn) {
            flag = 1;
            break;
        }
    }
    if(flag) cout << "Alice" << "\n";
    else cout << "Bob" << "\n";


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    prime();
    cin >> t;
    while(t--) solve_one();

	return 0;
}
