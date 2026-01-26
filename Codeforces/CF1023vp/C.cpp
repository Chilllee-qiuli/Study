#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
const ll inf = 1e17;
int t;
int n;
ll k, a[maxn];
string s;

void print(){
    cout << "Yes" << endl;
    for(int i = 1; i <= n; i++)
        if(s[i] != '0') cout << a[i] << " ";
        else cout << -inf << " ";
    cout << endl;
}

int main(){
    //freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        cin >> s;
        s = "1" + s;
        for(int i = 1; i <= n; i++) cin >> a[i];
        
        ll nowsum = 0, maxsum = 0;
        for(int i = 1; i <= n; i++){
            if(s[i] == '0') nowsum = 0;
            else {
                nowsum += a[i];
                maxsum = max(maxsum, nowsum);
                if(nowsum < 0) nowsum = 0;
            }
        }
        if(maxsum > k) cout << "No" << endl;
        else if(maxsum == k) print();
        else
        {
            maxsum = 0; nowsum = 0;
            int flag = 0;
            for(int i = 1; i <= n; i++)
            {
                nowsum = 0; 
                
                if(s[i] == '0'){
                    ll lsum = 0, rsum = 0;
                    ll lmax = 0, rmax = 0;
                    for(int j = i - 1; j >= 1; j--) {
                        if(s[j] == '0') break;
                        lsum += a[j];
                        lmax = max(lmax, lsum);
                    }
                    for(int j = i + 1; j <= n; j++){
                        if(s[j] == '0') break;
                        rsum += a[j];
                        rmax = max(rmax, rsum);
                    }

                    s[i] = '1';
                    if(lmax < 0) lmax = 0;
                    if(rmax < 0) rmax = 0;
                    a[i] = k - lmax - rmax;
                    //cout << "rmax: " << rmax << endl;
                    print();
                    flag = 1;
                    break;
                }
            } 
            if(!flag) cout << "No" << endl;
               
        }
    }
    

	return 0;
}
