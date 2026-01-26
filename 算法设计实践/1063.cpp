#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string str;

vector<int> prefix_function(string s) {
  int n = (int)s.length();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> str;
    vector<int> ans = prefix_function(str);
    for(int i = 0; i <= ans.size() - 1; i++)
    cout << ans[i] << " \n"[i == ans.size() - 1];

	return 0;
}