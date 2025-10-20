#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll k, tmpk;
ll pre[20]; // 预处理位数为x的所有数的长度
ll ans = 0;

void pre_work(){
    pre[1] = 9;
    ll tmp = 9;

    for(int i = 1; i <= 15; i++, tmp *= 10)
        pre[i] = tmp * i;
}

ll dcsl(ll l, ll r){ // 等差数列求和
    return (l + r)*(r - l + 1)/2;
}

void work(ll x, int len){
    ll y = x;
    vector<int> sig;
    while(y){
        sig.push_back(y % 10);
        y /= 10;
    }


    for(int i = sig.size() - 1; i >= 1; i--){ // 最后一位特殊处理
        ll num = sig[i];
        ll other = 0;
        for(int j = i - 1; j > 0 ; j--) other = other * 10 + sig[j];
        printf("other: %lld\n", other);
        if(other == 0){
            ans += num;
            break;
        }
        if(num > 1)
        {
            ans += dcsl(1, num - 1) * other;
            ans += num * other;
        }
        else if(num == 1) ans += other;

    }

} 

int main(){
    freopen("1.in", "r", stdin);
    //ios::sync_with_stdio(0);
    //cin.tie(0), cout.tie(0);
    cin >> t;
    
    pre_work();
    while(t--){
        cin >> k;
        tmpk = k;
        ans = 0;
        int len = 0;
       
        for(int i = 1; i <= 15; i++){
            if(k <= pre[i]){
                len = i;
                break;
            }
            k -= pre[i];
        }
        printf("tmpk= %lld, k= %lld len = %d \n", tmpk, k, len);


        work(k/len, len);

    }

	return 0;
}
