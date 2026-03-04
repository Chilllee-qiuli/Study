#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pr pair<int, int>
#define mk make_pair
const int maxl = 3030;
int t;
int n;
map<int, int> mp, kpp;
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
            if (!mpb[a.a[i]] && !kpp[a.a[i]])
                tmp.push_back(a.a[i]);
        for (int i = 1; i <= b.siz; i++)
            if (!kpp[b.a[i]])
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
int ans[maxl * maxl], cnt;

void quchong(node &x)
{
    int b[maxl], ctx = 0;
    map<int, int> mpx;
    for (int i = 1; i <= x.siz; i++)
        mpx[x.a[i]] = i;
    for (int i = 1; i <= x.siz; i++)
        if (mpx[x.a[i]] == i && !mp[x.a[i]])
            b[++ctx] = x.a[i];
    swap(b, x.a);
    x.siz = ctx;
}
void rd();
void print(vector<node> tmpvc);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--)
    {
        rd();
        vector<node> tmpvc, sortvc;
        // cout << "test" << endl;
        sort(vc.begin() + 1, vc.end(), [](const node &a, const node &b)
             { return a.maxx < b.maxx; });
        for (int i = 1; i <= n; i++)
        {
            if (i == 1 || vc[i].maxx == vc[i - 1].maxx)
                sortvc.push_back(vc[i]);
            else
            {
                sort(sortvc.begin(), sortvc.end());
                for (auto it : sortvc)
                {
                    tmpvc.push_back(it);
                    for (int j = 1; j <= it.siz; j++)                    
                        kpp[it.a[j]] = 1;                    
                }
                sortvc.clear();
                sortvc.push_back(vc[i]);
            }
        }
        if (sortvc.size())
        {
            sort(sortvc.begin(), sortvc.end());
            for (auto it : sortvc){                
                tmpvc.push_back(it);
                for (auto it : sortvc)
                {
                    tmpvc.push_back(it);
                    for (int j = 1; j <= it.siz; j++)                    
                        kpp[it.a[j]] = 1;                    
                }
            }

            sortvc.clear();
        }
        reverse(tmpvc.begin(), tmpvc.end());
        // cout << vc[1].siz << endl;
        print(tmpvc);
    }

    return 0;
}

void rd()
{
    cin >> n;
    vc.clear();
    kpp.clear();
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

void print(vector<node> tmpvc)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= tmpvc[i].siz; j++)
        {
            ans[++cnt] = tmpvc[i].a[j];
            mp[tmpvc[i].a[j]] = cnt;
        }
        // cout << tmpvc[i].yuan << " ";
    }
    // cout << endl;

    for (int i = cnt; i; i--)
    {
        if (mp[ans[i]] == i)
            cout << ans[i] << " ";
    }
    cout << "\n";
}