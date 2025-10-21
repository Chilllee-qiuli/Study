#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
struct cnm{
    int bit;
    ll contri;
};

bool operator < (cnm a,cnm b){
    return a.contri == b.contri ? a.bit < b.bit : a.contri < b.contri;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m, k ;
    cin >> n >> m >> k;
    vector <ll> a(n); 
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> cnt(m);
    for(int i = 0 ; i < n; i++){
        for(int p = 0; p < m; p++){
            if(!( (a[i] >> p) & 1)) {
                cnt[p]++;
            }
        }
    }
    vector<cnm> contri(m);
    map<ll,int> repeat;
    for(int i = 0; i < m; i++){
        contri[i].contri = 1LL * cnt[i] * (1LL<<i);
        contri[i].bit = i;
        repeat[contri[i].contri]++;
    }
    sort(contri.begin(),contri.end());
    ll x = 0;
    int i = m - 1;
    while(i >= 0){
        if(k && contri[i].contri){
            if(k >= repeat[contri[i].contri]){
                for(int j = i; j >= i - repeat[contri[i].contri] + 1; j--){
                    x += 1LL << contri[j].bit;
                }
                k-=repeat[contri[i].contri];
                i-=repeat[contri[i].contri];
            }
            else{
                int j=i-repeat[contri[i].contri]+1;
                for(;k>=0;k--,j++){
                    x+=1LL<<contri[j].bit;
                }
                break;
            }
        }
        else{
            i--;
        }
    }
    cout<<x<<endl;
    return 0;
}