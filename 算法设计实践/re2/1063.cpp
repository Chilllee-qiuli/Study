#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100100;
int cnt[maxn];
string str;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> str;

    cout << 0 << " ";
    for(int i = 1; i <= str.size() - 1; i++){
        int j = cnt[i - 1];
        while(j > 0 && str[i] != str[j]) j = cnt[j - 1];
        if(str[i] == str[j]) j++;
        cnt[i] = j; 
        cout << cnt[i] << " \n"[i == str.size() - 1];
    }

	return 0;
}