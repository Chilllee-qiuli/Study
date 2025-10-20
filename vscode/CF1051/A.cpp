#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 110;
int t;
int n;
int a[maxn];

bool work(int maxx){
    int l = maxx, r = maxx;
        
        for(int z = n - 1; z; z--){
            if(a[l-1] == z) l--;
            else if(a[r+1] == z) r++;
            else return 0;
        }

    return 1;
}

int main(){
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];

        int maxx = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] == n) maxx = i;
        }

        if(work(maxx)) cout << "YES" << endl; 
        else cout << "NO" << endl;
        //cout << t << endl;
    }

	return 0;
}
