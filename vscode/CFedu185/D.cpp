#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 10;

int t;
int a[maxn];
int n, q;
string str;


int main(){
    freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> q;
        cin >> str;
        str = "1" + str + "K";
        ll val = 0;
        int cntq = 0;
        for(int i = 1; i < str.size(); i++){
            char ch = str[i];
            if(ch == 'K') break;

            if(ch == 'X') val += 10;
            else if(ch == 'V') val += 5;
            else {
                if(ch == '?') cntq++;
                if(str[i + 1] == 'V' || str[i + 1] == 'X') val--;
                else val++; 
            }
        }

        cout << "val: " << val << endl;
        int cntIvx = 0;
        for(int tmp = 0, i = 1, l = 0; i < str.size(); i++){
            if(str[i] != '?' && !tmp) l = i;
            if(str[i] != '?' && tmp) {
                if(str[l] == 'I') tmp++;
                if(str[i] == 'V' || str[i] == 'X') tmp++;
                cntIvx += tmp/2;
                tmp = 0;
            }
            else if(str[i] == '?')tmp++;
        }

        int cx, cv, ci;
        while(q--){
            cin >> cx >> cv >> ci;
            if(ci >= cntq) cout << val << endl;
            else if(cv + ci >= cntq) {
                if(cntIvx >= cntq - ci) cout << val + (cntq - ci) * 2 << endl;
                else cout << val + cntIvx * 2 + 6 * (cntq - cntIvx) << endl;
            }
            else {
                if(cntIvx >= cntq - ci) cout << val + (cntq - ci) * 2  + 5 * (cntq - ci - cv)<< endl;
                else cout << val + cntIvx * 2 + 6 * (cntq - cntIvx)  + 5 * (cntq - ci - cv)<< endl;
            }
        }




    }

	return 0;
}
