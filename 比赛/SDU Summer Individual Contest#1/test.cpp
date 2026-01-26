#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 6060;
const int maxx = 2e7;
int n;
ll sum;
int fl[maxn];
bool vis[maxx];
int prime[maxx], tot;

void pre(){
    for(int i = 2; i < maxx; i++){
        if(!vis[i]) prime[++tot] = i;
        for(int j = 1; j <= tot && i * prime[j] < maxx; j++){
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll ans = 0;
    pre();

   cout << tot;

	return 0;
}
