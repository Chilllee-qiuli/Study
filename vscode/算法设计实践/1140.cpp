#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 110;
int n;
ll w[maxn], f[maxn * maxn];

int main(){
   // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> w[i];    
    for(int i = 1; i <= 100; i++)
    for(int j = 1; j <= i; j++){
        f[i] = max({w[i], f[i], f[i - j] + f[j]}); 
    }
    //for(int i = 1; i <= n; i++) cout << f[i] << " " ;
    //cout << endl;
    int m;
    cin >> m ;
    string str;       
    vector<int> tmp;
    cin >> str;
    ll cnt = 0;
    for(int i = 2; i < str.size(); i++){
        if(str[i - 2] == 'k' && str[i - 1] == 'e' && str[i] =='y'){
            cnt++;
            i += 2;
        }
        else if(cnt) {
            tmp.push_back(cnt);
            cnt = 0;
        }
    }
    if(cnt) tmp.push_back(cnt); 
    cnt = 0;

    for( auto v : tmp){
        //cout << "v= " << v << endl;
        cnt += f[v];
    }

    cout << cnt << "\n";






	return 0;
}