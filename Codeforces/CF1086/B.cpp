#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5050;
int a[maxn];
vector<int> vc;
int n, k, p, m;

int solve()
{

    cin >> n >> k >> p >> m;
    vector<int>().swap(vc);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    a[0] = 0;

    int sum = 0;
    if (p > k)
    {
        sort(a + 1, a + p); // [1, p)
        for (int i = 1; i <= p - k; i++)
            sum += a[i];
    }
    sum += a[p];

    if (m < sum)
        return 0;
    // if(m == sum) return 1;

    m -= sum;
    sum = 0;
    int tmp = a[p];
    a[p] = 0;
    sort(a + 1, a + 1 + n);

    sum = 0;
    for (int i = 1; i <= n - k + 1; i++)
        sum += a[i];
    sum += tmp;
    // cout << "m = " << m << " cnt = " << sum << " tmp = " << tmp << endl;
    return m / sum + 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--)
        cout << solve() << "\n";

    return 0;
}