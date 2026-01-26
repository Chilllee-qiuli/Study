#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t;
int n;
int a[maxn];
int num[maxn];

int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        memset(num, 0, sizeof(num));
        for(int i = 1; i <= n; i++) cin >> a[i];
        
        int cnt = 0;
        for(int i = 1; i <= n; i++) 
        if(!a[i]) cnt++;
        else num[a[i]]++;
        if(cnt == 1){
            for(int i = 1; i <= n; i++)
                if(!a[i]){
                    for(int j = 1; j <= n; j++)
                        if(num[j] == 0){
                            a[i] = j;
                            break;
                        }
                        break;
                }
            
        }
        int l = 0;
        for(int i = 1; i <= n; i++)
            if(a[i] != i) {
                l = i;
                break;
            }   
        if(l == 0){
            cout << 0 << "\n";
            continue;
        }
        int r = 0;
        for(int i = n; i >= 1; i--)
            if(a[i] != i) {
                r = i;
                break;
            }
        cout << r - l + 1 << "\n";
        
        
    }

	return 0;
}