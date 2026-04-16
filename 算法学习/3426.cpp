#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxl = 5e5 + 10;

int pi[maxl];
int f[maxl];

void Pre(string s){
    int l = s.length();
    f[0] = 1;
    for(int i = 1; i < l; i++){
        int j = pi[i - 1];
        while(j && s[i] != s[j]) j = pi[j - 1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
        if(f[j] * 2 >= i + 1) f[i] = f[j];
        else f[i] = i;
        cout << f[i] << " ";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string s;
    cin >> s;
    Pre(s);
    cout << f[s.length() - 1] << "\n";

	return 0;
}
