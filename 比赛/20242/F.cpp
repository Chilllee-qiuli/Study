#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n;
    ll score=1500;
    vector<ll> c(n+1,0);
    cin >> n;
    int flag=0;
    for(ll i=1;i<=n;i++){
        cin>>c[i];
        score+=c[i];
        if(score>=4000 && !flag){
            flag=1;
            cout<<i<<endl;
            break;
        }
    }
    if(!flag) cout<<"-1"<<endl;
    return 0;
}