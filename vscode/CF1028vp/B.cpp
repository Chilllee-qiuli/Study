#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int mod = 998244353;
ll prenum[maxn];

int t;
int n, p[maxn], q[maxn];



void pre(){
    prenum[0] = 1;
    for(int i = 1; i <= 1e5; i++)
        prenum[i] = prenum[i-1] * 2 % mod;
    
}

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    pre();
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> p[i];
        for(int i = 0; i < n; i++) cin >> q[i];

        // lflag, rflag;
        int lf = 0, rf = 0;

        for(int i = 0; i < n; i++){
            if(p[i] > p[lf]) lf = i;
            if(q[i] > q[rf]) rf = i; 
            if(p[lf] > q[rf]) cout << (prenum[p[lf]] + prenum[q[i - lf]]) % mod <<" ";
            else if(p[lf] < q[rf]) cout << (prenum[q[rf]] + prenum[p[i - rf]]) % mod << " ";
            else if(p[i - rf] > q[i - lf]) cout << (prenum[q[rf]] + prenum[p[i - rf]]) % mod << " ";
            else cout << (prenum[p[lf]] + prenum[q[i - lf]]) % mod <<" ";
            //if(p[lf] > q[rf]) printf("p[%d]= %d\n", lf, p[lf]);
            //else printf("q[%d] = %d\n", rf, q[rf]);
        }
        cout << endl;
    }


	return 0;
}
