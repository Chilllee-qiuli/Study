#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string str1, str2;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> str1 >> str2;
    if(str1.length() != str2.length()){
        cout << "NO\n";
        return 0;
    }
    for(int i = 0; i < str1.length(); i++){
        if(str1[i] == str2[i]) continue;
        else if((str1[i] == 'I' || str1[i] == 'l') && (str2[i] == 'I' || str2[i] == 'l')) continue;
        cout << "NO\n";
        return 0;
    }

    cout << "YES" << endl;

	return 0;
}
