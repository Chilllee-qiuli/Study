#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t;
int n, k;
int a[maxn];
map<int, int> mp;

ll add(){
    ll sum = 0;
    for(int i = 1; i <= n; i++) sum += a[i];
    return sum;
}

void work(){
    mp.clear();
    for(int i = 1; i <= n; i++) 
            mp[a[i]]++;
        
        int first0 = 0;
        for(int i = 0; i <= n; i++){
            if(mp[i] == 0 && !first0)  first0 = i;
        }

        
        for(int i = 1; i <= n; i++){
            if(a[i] < first0) {
                if(mp[a[i]] == 1) continue;
                else a[i] = first0;
            }
            else a[i] = first0;
        }
        // cout << "worked: " << endl;
        // for(int i = 1; i <= n; i++) 
        //     cout << a[i] << " ";
        //     cout << endl;
}

int main(){
    freopen("e.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        mp.clear();
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }

        if(!mp[0]){
            if(k & 1) cout << 0 << endl;
            else cout << n << endl;
            continue;
        }
        
        work(); // 1
        k--;
        if(k == 0){
            cout << add() << endl;
            continue;
        }

        if(mp[0] == 1){
            for(int i = 1; i <= min(2, k); i++)
                work();
            
            if(k <= 2){
                cout << add() << endl;
                continue;
            }
            k -= 2;
            ll ans = 0;
            int fir = 0 ;
            
            
            work();
            ll sum1 = add();

            
            work();
            ll sum2 = add();

            if(k & 1) cout << sum1 << endl;
            else cout << sum2 << endl;

        }
        else {
            if(k & 1) cout << 0 << endl;
            else cout << n << endl;
        }

        
        

    
    }

	return 0;
}
