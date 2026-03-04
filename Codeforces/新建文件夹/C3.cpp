#include<bits/stdc++.h>
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
void solve_one() {
    cin >> n;
    vc.clear();
    vc.push_back(node());

    for (int i = 1; i <= n; i++) {
        int l; cin >> l;
        vc.push_back(node());
        vc[i].siz = l;
        for (int j = 1; j <= l; j++) cin >> vc[i].a[j];
        quchong(vc[i]); 
    }

    vector<char> usd(n + 1, 0);
    unordered_set<int> fixed;
    fixed.reserve(6000);

    vector<int> ans;

    while (1) {
        int best = -1;
        vector<int> bestSeg; // 存的是 reverse(seg)
        bool flag = 0;

        for (int i = 1; i <= n; i++) if (!usd[i]) {
            vector<int> seg;
            seg.reserve(vc[i].siz);
            for (int j = 1; j <= vc[i].siz; j++) {
                int x = vc[i].a[j];
                if (!fixed.count(x)) seg.push_back(x);
            }
            if (seg.empty()) continue;

            reverse(seg.begin(), seg.end()); 

            if (!flag || seg < bestSeg) {
                flag = 1;
                best = i;
                bestSeg = std::move(seg);
            }
        }

        if (!flag) break;
        usd[best] = 1;

        for (int x : bestSeg) {
            fixed.insert(x);
            ans.push_back(x);
        }
    }

    for (int x : ans) cout << x << " ";
    cout << "\n";
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) solve_one();

	return 0;
}
