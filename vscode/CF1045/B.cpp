#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
const int maxx = 1e6 + 10;
int t;
int n, k;
ll a[maxn];
bool vis[maxx + 10];
vector<ll> prime;

void print(){
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
}

void pre(){
    for(int i = 2; i <= maxx; i++){
        if(!vis[i]) prime.push_back(i);
        for(auto p : prime) {
            if(p * i > maxx) break;
            vis[p * i] = 1;
            if(i % p == 0) break;
        }
    }
}

int main(){
   // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    pre();
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++) cin >> a[i];
        if(n == 1) {
            cout << a[1] + k << endl;
            continue;
        }

        if( k & 1){
            for(int i = 1; i <= n; i++)
            if(a[i] & 1) a[i] += k;
        }
        else {
            ll fl = 1;
            for(auto p : prime){
                if(k % p != 0) {fl = p; break;}
            }
            for(int i = 1; i <= n; i++){
                while(a[i] % fl != 0){
                    a[i] += k;
                }
            }
           
        }
        print();
    }

	return 0;
}
