#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string str1, str2;
string str;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> str1 >> str2 >> str;
    if(str == "Accepted") cout << str1 << " " << str2 << endl;
    else cout << str2 << " " << str1 << endl;

	return 0;
}
