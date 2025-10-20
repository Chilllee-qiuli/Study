#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
int t;
int n;
int a[maxn], id[maxn];

struct nodeb{
    int id, num;
};
priority_queue<nodeb> nb;

bool operator < (nodeb x, nodeb y){
    return x.id < y.id;
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        while(!nb.empty()) nb.pop();
        cin >> n;
        for(int i = 1; i <= n; i++) id[i] = 0;
        for(int i = 1; i <= n/2; i++){
            int x; cin >> x;
            a[i*2] = x;
            id[x] = i * 2;
        }
        
        int flag = 1;
        for(int num = n; num; num--){
            if(id[num])  nb.push((nodeb){id[num], num});
            
            else {
                if(nb.empty()){flag = 0; break;}
                
                nodeb tmp = nb.top(); nb.pop();
               // printf("top.id= %d, top.num= %d\n", tmp.id, tmp.num);
                a[tmp.id - 1] = num;
            }

        }
        if(!flag) cout << -1 << endl;
        else {
            for(int i = 1; i <= n; i++) cout << a[i] << " ";
            cout << endl;
        }
    }

	return 0;
}
