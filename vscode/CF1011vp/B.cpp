#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5050;
int t;
int n;
int a[maxn];

int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int sum = 0;
        vector<int> cnt;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            sum += a[i];
            if(a[i] == 0) cnt.push_back(i);
        }
        if(sum == 0){
            cout << 3 << endl;
            cout << n-1 << " " << n << endl;
            cout << 1 << " " << n-2 << endl;
            cout << 1 << " " << 2 << endl;
        }
        else if(cnt.size() == 0){
            cout << 1 << endl;
            cout << 1 << " " << n << endl;
        } 
        else if(cnt.size() == 1)
        {
            if(cnt[0] == n)
            {
                cout << 2 << endl;
                cout << n-1 << " " << n << endl;
                cout << 1 << " " << n-1 << endl;
            }
            else {
                cout << 2 << endl;
                cout << cnt[0] << " " << n << endl;
                cout << 1 << " " << cnt[0] << endl;
            }
        }
        else 
        {
            if(a[1] == 0 && a[n] == 0)
            {
                cout << 3 << endl;
                cout << 3 << " " << n << endl;
                cout << 1 << " " << 2 << endl;
                cout << 1 << " " << 2 << endl;
            }
            else 
            {
                cout << 2 << endl;
                cout << cnt[0] << " " << cnt[cnt.size() - 1] << endl;
                cout << 1 << " " << n - (cnt[cnt.size() - 1] - cnt[0]) << endl;
            }
        }
        


        
    }

	return 0;
}
