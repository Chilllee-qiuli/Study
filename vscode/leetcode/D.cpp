#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int n, q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--){
        cin >> n >> q;
        string str = "0";
        cin >> str;

        int cx, cv, ci;
        cin >> cx >> cv >> ci;

        ll sum = 0;
        for(int i = 1; i < str.size(); i++){
            if(str[i] == 'X') sum += 10;
            else if(str[i] == 'V') sum += 5;
            else {
                if(i < str.size() - 1 && str[i + 1] != 'I' && str[i + 1] != '?') sum += -1;
                else sum++;
            }

             
        }
    }

	return 0;
}