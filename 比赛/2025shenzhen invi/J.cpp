#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);
    cout.tie(0);
    vector<long long> pw(25, 1);
    pw[0]=1;
    for(int i = 1; i <= 24; ++ i){
        pw[i] = pw[i - 1] * 4;
    }
    int T = 1;
    cin >> T;
    while(T --){
        long long n;
        cin >> n;
        long long v = *lower_bound(pw.begin(), pw.end(), n);
        if(n == v){
            cout << 0 << endl;
            continue;
        }
        vector<long long> ans;
        while(n != v){
            long long t = n & -n;
            n += t;
            ans.push_back(t);
        }
        cout << ans.size() << endl;
        for(long long d: ans) cout << d << ' ';
        cout << endl; 
    }
}