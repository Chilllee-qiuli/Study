#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int m;
map<int, int> mp;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    mp[-1] = 1;
    mp[1e9 + 1] = 1;
    cin >> m;
    while(m--){
        int op, x;
        cin >> op >> x;
        if(op == 1){
            if(mp.find(x) != mp.end()) cout << "Already Exist\n";
            else mp[x] = 1;
        }
        else {
            if(mp.find(x) != mp.end()){
                mp.erase(x);
                cout << x << "\n";
            }
            else {
                auto lwb = mp.lower_bound(x);
                int b = lwb->first;
                lwb--;
                int a = lwb->first;
                if(a == -1 && b == 1e9 + 1) cout << "Empty\n";
                else if(a == -1) {
                    cout << b << "\n";
                    mp.erase(b);
                }
                else if(b == 1e9 + 1){
                    cout << a << "\n";
                    mp.erase(a);
                }
                else {
                    if(abs(b - x) < abs(a - x)) {
                        cout << b << "\n";
                        mp.erase(b);
                    }
                    else {
                        cout << a << "\n";
                        mp.erase(a);
                    }
                }
            }            
        }
    }
    

    return 0;
}