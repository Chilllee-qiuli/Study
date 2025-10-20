#include<bits/stdc++.h>
using namespace std;
using ll =long long;
const int N=1e3+9;
const int inf = 0x3f3f3f3f;
int n, k,siz,sum;
int a[N];

int gcd(int m,int n){
    while(n){
        int tmp=n;
        n=m%n;
        m=tmp;
    }
    return m;
}
void move(int h,int t){
    for(int i=h;i<t;i++){
        a[i]=a[i+1];
    }
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        a[i]=1;
    }
    while(k--){
        siz=n-1;
        pair<int,int> ans(-inf,0);
        for(int i=1;i<=siz;i++){
            sum=0;
            for(int j=1;j<i;j++){
                sum+=gcd((a[i]+a[j]),n);
            }
            for(int j=i+2;j<=n;j++){
                sum+=gcd((a[i+2]+a[j]),n);
            }
            sum+=gcd(a[i]+a[i+1],n);
            if(sum>ans.first){
            ans.first=sum;ans.second=i;
        }
        }
        if(ans.second){
            a[ans.second]+=a[ans.second+1];
            move(ans.second+1,siz);
            siz--;
        }
    }
    for(int i=1;i<=siz;i++){cout<<a[i]<<endl;}
    return 0;
}