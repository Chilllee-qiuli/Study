#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
const int maxa = 5e6 + 10;
int t;
int n, a[maxn];
int vis[maxa], prime[maxa], tot;
int cnt[348513 + 10];
int max_cnt[348513+10];

void init(){
    for(int i = 2; i <= maxa; i++){
        if(!vis[i]) prime[++tot] = i;
        for(int j = 1; j <= tot && i * prime[j] <= maxa; j++){
            vis[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    init();

    cin >> t;

    while(t--){
        cin >> n;
        int maxai = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            maxai = max(maxai, a[i]);
        }
        if(n & 1) cout << "YES" << endl;
        else {
            int max_size = lower_bound(prime + 1, prime + 1 + tot, maxai) - prime;
            memset(cnt, 0, 4*(max_size+1));
            memset(max_cnt, 0, sizeof(max_cnt));
            for(int i = 1; i <= n; i++){
                int tmp = 1;
                while(a[i] > 1 && tmp <= max_size){
                    int cnt_ai = 0;
                    while(a[i] % prime[tmp] == 0){
                        cnt_ai++;
                        a[i] /= prime[tmp];
                    }
                    cnt[tmp] += cnt_ai;
                    max_cnt[tmp] = max(max_cnt[tmp], cnt_ai);
                    tmp++;
                }
            }
            int flag = 1;
            for(int i = 1; i <= max_size; i++){
                if(cnt[i] & 1 || max_cnt[i] > cnt[i]/2) {flag = 0; break;}

            }
            if(flag) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
	return 0;
}
