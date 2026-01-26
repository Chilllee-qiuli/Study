#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(ll a,ll b){
    if(a==b) return 1;
    if(a>b) swap(a,b);
    if((b%a)!=0) return -1;
    ll q=(a+b)/a;
    if((q&(q-1))!=0) return -1;
    ll k=0;
    while(q>1){
        q>>=1;
        k++;
    }
    return k;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll x,y;
        cin>>x>>y;
        cout<<solve(x,y)<<endl;
    }
    return 0;
}