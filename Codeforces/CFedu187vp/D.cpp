#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxnum = 2e6 + 10;
const int maxn = 1e6 + 10;
#define pr pair<int, int> 
#define mk make_pair
#define fi first
#define se second
int b[maxn];
vector<int> a;
int n, m;


unordered_map<int, int> mp;

string solve_one(){
    cin >> n >> m;
    vector<int> ().swap(a);


    for(int i = 1, x; i <= n; i++) {
        cin >> x;
        a.push_back(x);
    }
    
    for(int j = 1; j <= m; j++) {
        cin >> b[j];
        mp[b[j]] = 0;
    }
    //cout << "test1" << endl;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    for(auto it : a)
        for(int j = 1; (ll) it * j <= n + m; j++){
            mp[it * j]++;
        }
        //cout << "test2" << endl;
    
    int Alice = 0, Bob = 0, all = 0;
    for(int i = 1; i <= m; i++){
        if(mp[b[i]] == a.size()) Alice++;
        else if(mp[b[i]] == 0) Bob++;
        else all++;
    }
    if(all & 1) Alice++;
    if(Alice > Bob) return "Alice";
    else return "Bob";

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    //pre();
    int T;
    cin >> T;
    while(T--) cout << solve_one() << "\n";



	return 0;
}
