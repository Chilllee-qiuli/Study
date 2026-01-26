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

bool judge(int x){
    for(int i = 1; i <= tot && prime[i] < x; i++)
        if(x % prime[i] == 0) return 0;
    
    return 1;
}

int main(){
    //freopen("1.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    pre();
    //for(int i = 1; i <= 100; i++) cout << prime[i] << " " ; cout << endl;

    cin >> n;
    sum = (1 + n) * n / 2;
    if(n == 2){
        cout << 1 << " " << 1;
        return 0;
    }
    if(judge(sum)){
        for(int i = 1; i <= n; i++) cout << 1 << " ";
        return 0;
    }

    int a = 0, b = 0;

    


    for(int i = 1; i <= tot && prime[i] <= sum; i++){
        if(judge(sum - prime[i])){
            a = prime[i];
            break;
        }
    }

    if(a == 0){
        sum -= 3;
        fl[3] = 3;
        for(int i = 1; i <= tot && prime[i] <= sum; i++)
        if(judge(sum - prime[i])){
            a = prime[i];
            break;
        }
    
    
    }
    if(a == 0){
        cout << -1;
        return 0;
    }
    //cout << "test: " << a << " " << b << endl;

    for(int i = n; i >= 1; i--)
    {
        if(a == 0) break;
        if(fl[i]) continue;
        if(a <= i)
        {
            fl[a] = 2;
            break;
        }
        if(a > i)
        {
            a -= i;
            fl[i] = 2;
        }
    }

    for(int i = 1; i <= n; i++){
        if(!fl[i]) cout << 1 << " ";
        else cout << fl[i] << " ";
    }
    


	return 0;
}
