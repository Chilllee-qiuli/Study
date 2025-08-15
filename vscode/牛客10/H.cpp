#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;


bool judge(int x, int y, char ch){
    if(ch == '+') return (0 <= x + y) && (x + y <= 9);
    else return (0 <= x * y) && (x * y <= 9);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        if(str[0] != str[2] && str[1] != '-' && judge(str[0]-'0', str[2]-'0', str[1])){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
 

    }

	return 0;
}
