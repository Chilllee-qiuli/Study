#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pr pair<ll, ll>
#define mk make_pair
#define fi first 
#define se second

const ll inf  = 0x3f3f3f3f3f3f3f3f;

int t;
ll a;
int n;
int d[20];

struct node{
    ll yu, nowbig, nowsm;
};

node dp[25][20];

int m;
vector<int> bit;

void pre(){
    cin >> a >> n;
    for(int i = 1; i <= n; i++) cin >> d[i];

    sort(d + 1, d + n + 1);

    ll b = a;
    vector<int>().swap(bit);
    m = 0;

    if(a == 0) bit.push_back(0);
    else while(b){
        bit.push_back(b % 10);
        b /= 10;
    }

    reverse(bit.begin(), bit.end());
    m = bit.size();      
}

ll add(ll x, int y){
    if(x >= inf) return inf;
    if(x > (inf - y) / 10) return inf;
    return x * 10 + y;
}

ll getmx(int len){
    if(len <= 0) return inf;

    if(len > 1 && d[n] == 0) return inf;

    ll res = 0;
    for(int i = 1; i <= len; i++){
        res = add(res, d[n]);
        if(res >= inf) return inf;
    }

    return res;
}

ll getmn(int len){
    if(len <= 0) return inf;

    ll res = 0;

    for(int i = 1; i <= len; i++){
        int x = -1;

        for(int j = 1; j <= n; j++){
            if(i == 1 && len > 1 && d[j] == 0) continue;
            x = d[j];
            break;
        }

        if(x == -1) return inf;

        res = add(res, x);
        if(res >= inf) return inf;
    }

    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;

    while(t--){
        pre();

        for(int i = 1; i <= n; i++){
            dp[0][i].yu = 0;
            dp[0][i].nowbig = inf;
            dp[0][i].nowsm = -1;
        }

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                dp[i][j].yu = -1;
                dp[i][j].nowbig = inf;
                dp[i][j].nowsm = -1;

                int x = d[j];

                if(i == 1 && m > 1 && x == 0) continue;

                for(int k = 1; k <= n; k++){

                    if(dp[i - 1][k].nowsm != -1){
                        ll val = add(dp[i - 1][k].nowsm, x);
                        dp[i][j].nowsm = max(dp[i][j].nowsm, val);
                    }

                    if(dp[i - 1][k].nowbig != inf){
                        ll val = add(dp[i - 1][k].nowbig, x);
                        dp[i][j].nowbig = min(dp[i][j].nowbig, val);
                    }

                    if(dp[i - 1][k].yu != -1){
                        ll val = add(dp[i - 1][k].yu, x);

                        if(x < bit[i - 1]){
                            dp[i][j].nowsm = max(dp[i][j].nowsm, val);
                        }
                        else if(x == bit[i - 1]){
                            dp[i][j].yu = val;
                        }
                        else {
                            dp[i][j].nowbig = min(dp[i][j].nowbig, val);
                        }
                    }
                }
            }
        }

        ll ans = inf;

        for(int i = 1; i <= n; i++){
            if(dp[m][i].yu != -1){
                ans = 0;
            }

            if(dp[m][i].nowsm != -1){
                ans = min(ans, a - dp[m][i].nowsm);
            }

            if(dp[m][i].nowbig != inf){
                ans = min(ans, dp[m][i].nowbig - a);
            }
        }


        if(d[1] == 0){
            ans = min(ans, a);
        }

        // 
        ll spj1 = getmx(m - 1);
        if(spj1 != inf){
            ans = min(ans, llabs(a - spj1));
        }

        // 
        ll spj2 = getmn(m + 1);
        if(spj2 != inf){
            ans = min(ans, llabs(a - spj2));
        }

        cout << ans << endl;
    }

    return 0;
}
