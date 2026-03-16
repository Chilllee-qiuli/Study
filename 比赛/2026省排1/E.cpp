#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5050;
int a[maxn], b[maxn];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int j = 0; j < n; j++) cin >> b[j];
        sort(a, a  + n);
        sort(b, b  + n);
        int ans = 0;
        for(int k = 0; k < n; k++){
            int minn = 0x3f3f3f3f;
            for(int i = 0; i < n; i++){
                minn = min(minn, abs(a[i] - b[(i + k) % n]));
            }
            ans = max(ans, minn);
        }
        cout << ans << endl;
    }


    return 0;
}