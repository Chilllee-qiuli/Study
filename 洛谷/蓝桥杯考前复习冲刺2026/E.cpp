#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e8 + 10;

bool vis[maxn];
int prime[maxn / 10], tot;
int n, q, k;
void pre(){
    for(int i = 2; i < maxn; i++){
        if(!vis[i]) prime[++tot] = i;
        for(int j = 1; j <= tot && (ll)i * prime[j] < maxn; j++){
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    pre();
    cin >> n >> q;
    while(q--){
        cin >> k;
        cout << prime[k] << "\n";
    }

    return 0;
}