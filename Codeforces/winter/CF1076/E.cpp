#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 10;
int a[maxn];
int ins[maxn];
int t;
int n;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) ins[i] = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            ins[a[i]] = 1;
        }

        for(int i = 1; i <= n; i++){
            if(ins[i]) cout << 1 << " ";
            else {
                for(int num = 2; num <= sqrt(i); num++){
                    if(i % num != 0) continue;
                    if(ins[num] && ins[i / num]) {
                        if(ins[i]) ins[i] = min(ins[i], ins[num] + ins[i/num]);
                        else ins[i] = ins[num] + ins[i/num];
                    }
                }
                if(ins[i]) cout << ins[i] << " ";
                else cout << -1 << " ";
            }
        }

        cout << endl;

    }   

	return 0;
}