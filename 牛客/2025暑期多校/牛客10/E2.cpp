#include <bits/stdc++.h>
using namespace std;
const int N=409;
using ll = long long;
#define lc (i*2)
#define rc (i*2+1)
int a[N],k,m,n,stk[N],top=0;

int maxx(){
    int ans=a[1];
    for(int i=2;i<=n;i++){
        ans=max(ans,a[i]);
    }
    return ans;
}
ll work2(int x, int maxy){
    printf("x= %d, maxy = %d\n", x, maxy);
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        int tmp;
        tmp = (a[i] <= x) ? x - a[i] : maxy - a[i];
        if(top && tmp > stk[top]){ 
            ans += stk[1];
            tmp = tmp - stk[top];
            top = 0;
        }
        stk[++top] = tmp;
    }
    if(top){
        ans += stk[1];
        top = 0;
    }
    printf("x= %d, maxy = %d, ans= %d\n", x, maxy, ans);
    return ans;
}
ll work(int max){
    ll ans=0;
    for(int i=1;i<=n;i++){
        int tmp=max-a[i];
        if(top&&tmp>stk[top]){
            ans+=stk[1];
            tmp=tmp-stk[top];
            top=0;
        }
        stk[++top]=tmp;
    }
    if(top){
        ans+=stk[1];
        top=0;
    }
    return ans;
}

int main(){
    freopen("e.in", "r", stdin);
    freopen("e2.out", "w", stdout);
    int _;cin>>_;
    while(_--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){cin>>a[i];}
        if(m==1){
            cout<<work(maxx())<<endl;
        }else{
            int z = a[1];
            for(int i = 1; i <= n; i++) z = max(z, a[i]);
            ll ans=work(z);
            for(int i=0;i<z;i++){
                ans=min(ans,work2(i,z));
            }
            ans=min(ans,work(z));
            cout<<ans<<endl;
        }
    }
    return 0;
}