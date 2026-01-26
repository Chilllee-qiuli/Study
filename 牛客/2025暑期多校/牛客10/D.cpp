#include <bits/stdc++.h>
using namespace std;
const int N=409;
using ll = long long;
#define lc (i*2)
#define rc (i*2+1)
pair<int,int> arr[N];
int a[N],help[N],heap[N],k,m;
ll n;
int siz=0;
int ans=0;

int main(){
    int _;cin>>_;
    while(_--){
        cin>>n;
        if((n-4)%6==0&&n!=1)cout<<2<<endl;else cout<<0<<endl;
    }
    return 0;
}