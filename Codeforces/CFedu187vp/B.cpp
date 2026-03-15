#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


string s;

int solve_one(){
    cin >> s;
    int sum = 0;
    vector<int> vc;
    vc.push_back(s[0] - '0' - 1);
    sum += s[0] - '0';
    for(int i = 1; i < s.length(); i++){
        sum += s[i] - '0';
        vc.push_back(s[i] - '0');
    }
    if(sum <= 9) return 0;
    int cnt = 0;
    sort(vc.rbegin(), vc.rend());
    for(auto it : vc){
        cnt++;
        sum -= it;
        if(sum <= 9) return cnt;
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int T;
    cin >> T;
    while(T--) cout << solve_one() << "\n";



	return 0;
}
