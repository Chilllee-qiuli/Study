#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int T;
map<int, int> mp;

bool check(int x){
    if(x > 1) return 0;
    if(n % 2 == 0 && !mp[0]) return 0;
    return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> n;
        mp.clear();
        for(int i = 1; i <= n; i++){
            int x;
            mp[x]++;
        }
        int flag = 0;
        for(auto x : mp){
            if(x.first <= 0) continue;
            flag += abs(x.second - mp[-x.first]);
        }
        if(!check(flag)) {
            cout << 0 << "\n";
            continue;
        }
        
    }

    return 0;
}
