#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+7;
ll cheng[maxn];
ll p1[maxn];
ll p2[maxn];
const int mod = 998244353;

void pre(){
    cheng[1] = 1;
    for(int i = 2; i < maxn; i++) 
    cheng[i] = cheng[i-1] * i % mod;
}
void precomute(){
    for(int i = 1; i < maxn; i++){
        
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    pre();


    return 0;
}