#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n;
vector<int> mp[550];

int work(vector<int> A, int root, int v){
    cout << "? " << root << " "  << A.size() + 1 << " " << root << " ";
    for(auto x : A) cout << x << " ";
    cout << endl;
    int x;
    cin >> x;
    if(x > 1) return 0;
    return 1;
}

int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++) mp[i].clear();

        for(int i = 1; i <= n; i++){
            cout << "? " << i << " " << n << " ";
            for(int j = 1; j <= n; j++) cout << j << " ";
            cout << endl; 
            int divi = 0;
            cin >> divi;
            mp[divi].push_back(i);
        }
        int root = 0, dth = 0, d = 0;
        for(int i = n; i >= 1; i--)
            if(!mp[i].empty()){
                root = mp[i][0];
                dth = i;
                d = dth;
                break; 
            }
            

        vector<int> path;
        path.push_back(root);
        while(--dth){
            if(mp[dth].size() == 1){
                path.push_back(mp[dth][0]);
                continue;
            }
            
            vector<int> tmp[2];
            for(int i = 0; i < mp[dth].size()/2; i++) tmp[0].push_back(mp[dth][i]);
            for(int i = mp[dth].size()/2; i < mp[dth].size(); i++) tmp[1].push_back(mp[dth][i]);
            int v = work(tmp[0], path[path.size() - 1], 0);

            while(tmp[v].size() > 1){

                //tmp[v ^ 1].clear();
                vector<int> fl;
                for(int i = 0; i < tmp[v].size(); i++) fl.push_back(tmp[v][i]);
                tmp[v].clear();
                tmp[v ^ 1].clear();
                for(int i = 0; i < fl.size()/2; i++) tmp[0].push_back(fl[i]);
                for(int i = fl.size()/2; i < fl.size(); i++) tmp[1].push_back(fl[i]);
                v = work(tmp[0], path[path.size() - 1], 0);
            }
            path.push_back(tmp[v][0]);

        }

        cout << "! " << d << " ";

        for(auto v : path) cout << v << " ";
        cout << endl;
        


        cout.flush();
    }

	return 0;
}