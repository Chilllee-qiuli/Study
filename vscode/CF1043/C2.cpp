#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n, k;
map<ll, ll> pc; // precost
ll ans = 0;
ll cnt[30];

void pre(){
    pc[0] = 3;
    for(int i = 1; i <= 28; i++)
    pc[i] = pow(3, i + 1) + pow(3, i - 1) * i;
}

void print(){
    for(int i = 0; i <= 28; i++)
    ans += pc[i] * cnt[i];
    cout << ans << endl;
}

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    pre();
    while(t--){
        cin >> n >> k;
        memset(cnt, 0, sizeof(cnt));
        ans = 0;
        int flag = 0;
        ll sum = 0;
        while(n){
            cnt[flag++] = n % 3;
            sum += n % 3;
            n /= 3;
        }

        if(sum > k ){
            cout << -1 << endl;
            continue;
        }
        else if(sum == k){
            print();
            //printf("k= %d, cnt[0] = %d, pc[0] = %d\n", sum, cnt[0], pc[0]);
            continue;
        }
        k -= sum;
        //cout << "nowk: " << k << endl;

        for(int i = 28; i >= 1; i--){
            if(k < 2) break;
            ll need = cnt[i] * 2;
            //if(need) printf("cnt[%d] = %lld\n", i, cnt[i]);
            if(k >= need){
                k -= need;
                cnt[i-1] += cnt[i] * 3;
                cnt[i] = 0;
            }
            else {
                k/=2;
                cnt[i] -= k;
                cnt[i - 1] += k * 3;
                break;
            }
        }
        //cout <<"newk: " << k << endl;
        print();
        

    }

	return 0;
}
