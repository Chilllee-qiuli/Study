#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 10;
int h[maxn], w[maxn];
int n;
ll ans[maxn];

vector<int> qu;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> h[i] >> w[i];
    
    for(int i = 1; i <= n; i++){
        while(!qu.empty() && h[i] > h[qu[qu.size() - 1]]){
            ans[i] += w[qu[qu.size() - 1]];
            qu.pop_back();
        }
        qu.push_back(i);
    }
    
    vector<int> ().swap(qu);

    for(int i = n; i; i--){
        while(!qu.empty() && h[i] > h[qu[qu.size() - 1]]){
            ans[i] += w[qu[qu.size() - 1]];
            qu.pop_back();
        }
        qu.push_back(i);
    }


    ll maxx = 0;
    for(int i = 1; i <= n; i++) 
        maxx = max(maxx, ans[i]);
    
    cout << maxx << endl;




	return 0;
}