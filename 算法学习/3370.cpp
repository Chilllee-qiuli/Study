#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using ull = unsigned long long;
ull base = 131;
ull mod1 = 212370440130137957, mod2 = 1e9 + 7;

ull get_hash1(std::string s) {
  int len = s.size();
  ull ans = 0;
  for (int i = 0; i < len; i++) ans = (ans * base + (ull)s[i]) % mod1;
  return ans;
}

ull get_hash2(std::string s) {
  int len = s.size();
  ull ans = 0;
  for (int i = 0; i < len; i++) ans = (ans * base + (ull)s[i]) % mod2;
  return ans;
}

bool cmp(const std::string s, const std::string t) {
  bool f1 = get_hash1(s) != get_hash1(t);
  bool f2 = get_hash2(s) != get_hash2(t);
  return f1 || f2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    int n;
    cin >> n;
    vector< pair<ull, ull> > a;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        ull f1 = get_hash1(s);
        ull f2 = get_hash2(s);
        a.push_back(make_pair(f1, f2));;
    }

    sort(a.begin(), a.end());

    a.erase(unique(a.begin(), a.end()), a.end());

    cout << a.size() << endl;






	return 0;
}
