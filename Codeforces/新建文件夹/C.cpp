#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pr pair<int, int>
#define mk make_pair
const int maxl = 3030;
int t;
int n;

struct node
{
    int yuan = 0;
    int siz = 0;
    int maxx = 0;
    int a[maxl];
    static vector<int> cpt(const node &a, const node &b)
    {
        map<int, int> mpb;
        vector<int> tmp;
        for (int i = 1; i <= b.siz; i++)
            mpb[b.a[i]] = 1;

        for (int i = 1; i <= a.siz; i++)
            if (!mpb[a.a[i]])
                tmp.push_back(a.a[i]);
        for (int i = 1; i <= b.siz; i++)
            tmp.push_back(b.a[i]);
        reverse(tmp.begin(), tmp.end());
        return tmp;
    }

    friend bool operator<(const node &a, const node &b)
    {
        if (a.maxx != b.maxx)
            return a.maxx > b.maxx;
        return cpt(a, b) < cpt(b, a);
    }
};
vector<node> vc;
map<int, int> mp;
int ans[maxl * maxl], cnt;

void quchong(node &x)
{
    int b[maxl], ctx = 0;
    map<int, int> mpx;
    for (int i = 1; i <= x.siz; i++)
        mpx[x.a[i]] = i;
    for (int i = 1; i <= x.siz; i++)
        if (mpx[x.a[i]] == i)
            b[++ctx] = x.a[i];
    swap(b, x.a);
    x.siz = ctx;
}
void rd();
void print();

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--)
    {
        rd();
        // cout << "test" << endl;
        sort(vc.begin() + 1, vc.end());
        // cout << vc[1].siz << endl;
        print();
    }

    return 0;
}

void rd()
{
    cin >> n;
    vc.clear();
    mp.clear();
    vc.push_back(node());
    cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int l;
        cin >> l;
        vc.push_back(node());
        for (int j = 1; j <= l; j++)
        {
            cin >> vc[i].a[j];
            vc[i].maxx = max(vc[i].maxx, vc[i].a[j]);
        }

        vc[i].siz = l;
        vc[i].yuan = i;
        quchong(vc[i]);
    }
}

void print()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= vc[i].siz; j++)
        {
            ans[++cnt] = vc[i].a[j];
            mp[vc[i].a[j]] = cnt;
        }
        // cout << vc[i].yuan << " ";
    }
    // cout << endl;

    for (int i = cnt; i; i--)
    {
        if (mp[ans[i]] == i)
            cout << ans[i] << " ";
    }
    cout << "\n";
}