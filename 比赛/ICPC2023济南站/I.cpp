#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pr pair<int, int>
#define mk make_pair
const int maxn = 110;
int t;
int n, a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        vector<pr> vc;
        for(int i = 1; i <= n; i++) cin >> a[i];

        for(int i = 1; i <= n; i++){
            if(a[i] == i) continue;
            else {
                int l = i, r;
                for(int j = n; j > i; j--)
                    if(a[j] < a[i]) {
                        r = j;
                        break;
                    }
                vc.push_back(mk(l, r));
                sort(a + l, a + 1 + r);
            }
        }

        cout << vc.size() << "\n";
        for(auto[l, r] : vc)
            cout << l << " " << r << "\n";
        
    }

	return 0;
}
