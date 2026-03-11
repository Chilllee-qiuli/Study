#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 50;
int n, m, q, s;
int d[maxn], anc[maxn][20], dis[maxn];
vector<int> g[maxn];
void addedge(int u, int v)
{
	g[u].push_back(v);
	g[v].push_back(u);
}

inline long long read()
{
	char readch = getchar();
	ll readtmp = 0;
	ll readflag = 1;
	while (readch < '0' || '9' < readch)
	{
		if (readch == '-')
			readflag = -1;
		readch = getchar();
	}
	while ('0' <= readch && readch <= '9')
	{
		readtmp = readtmp * 10 + readch - '0';
		readch = getchar();
	}
	return readtmp * readflag;
}

void dfs(int u, int fa)
{
	for (int i = 0; i < (int)g[u].size(); i++)
	{
		int v = g[u][i];
		if (v == fa)
			continue;
		d[v] = d[u] + 1;
		anc[v][0] = u;
		dfs(v, u);
	}
}

void init()
{
	for (int j = 1; j <= 18; j++)
	{
		for (int i = 1; i <= n; i++)
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
	}
}

int LCA(int u, int v)
{
	if (d[u] < d[v])
		swap(u, v);
	for (int i = 18; i >= 0; i--)
	{
		if (d[anc[u][i]] >= d[v])
			u = anc[u][i];
	}
	if (u == v)
		return u;
	for (int i = 18; i >= 0; i--)
	{
		if (anc[u][i] != anc[v][i])
		{
			u = anc[u][i];
			v = anc[v][i];
		}
	}
	return anc[u][0];
}

int main()
{
	cin >> n >> m >> s;
	for (int i = 1; i < n; i++)
	{
		int u, v;
		u = read();
		v = read();
		addedge(u, v);
	}

	d[s] = 1;
	dfs(s, 0);
	init();
	while (m--)
	{
		int u = read();
		int v = read();
		printf("%d", LCA(u, v));
		if (m != 0)
			printf("\n");
	}
	return 0;
}
