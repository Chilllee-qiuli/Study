#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using namespace std;
int t;

int main() {
   // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt0 = count(s.begin(), s.end(), '0');
        int errcnt = 0;

        for (int i = 0; i < cnt0; i++) {
            if (s[i] == '1') errcnt++;
        }

        for (int i = cnt0; i < n; i++) {
            if (s[i] == '0') errcnt++;
        }

        cout << errcnt / 2 << endl;
    }
    return 0;
}
