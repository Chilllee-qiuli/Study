#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2000 + 10;
const int Len = 3e4 + 10;


int n;
struct node{
    int son[2]; // 子节点边
    int cnt; // 记录匹配数
    int fail; // fail指针
    int in;
    void init(){
        memset(son, 0, sizeof(son));
        cnt = fail = 0;
    }
}tr[Len];

int tot;

void init(){
    tot = 0;
    tr[0].init();
}

void insert(string s){
    int p = 0;
    int l = s.length();
    for(int i = 0; i < l; i++){
        int c = s[i] - '0';
        if(!tr[p].son[c]) tr[p].son[c] = ++tot;
        p = tr[p].son[c];
    }
    // 由于有可能出现相同的模式串，需要将相同的映射到同一个编号
    tr[p].cnt++;
}

void build(){
    queue<int> q;
    // 注意先预处理边界，即根的周围节点
    // 如果有节点自然加入bfs去算fail，如果没有，那么要自然置0
    // 因为失配fail指针跳到0的时候，如果0也没有这个字符的边，那就干脆指向根，即0
    // 特别注意，根表示空串
    for(int i = 0; i < 2; i++)
        if(tr[0].son[i]) q.push(tr[0].son[i]);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < 2; i++)
            if(tr[u].son[i]){  // 存在对应子结点
                int son = tr[u].son[i];
                tr[son].fail = tr[tr[u].fail].son[i]; // 只用跳一次 fail 指针
                tr[ tr[tr[u].fail].son[i] ].in++; // 入度计数
                q.push(tr[u].son[i]);  // 并加入队列
            }
            // else tr[u].son[i] = tr[tr[u].fail].son[i];
            // !! 将不存在的字典树的状态链接到了失配指针的对应状态
        }
    
}

void query(string s){
    int u = 0;
    int l = s.length();
    for(int i = 0; i < l; i++){
        u = tr[u].son[s[i] - '0'];
        tr[u].cnt++; 
        // 在文本串路径上标记经过的状态，路径上所有经过的模式串都在文本串上完整出现了
    }
}

int ans = 0;
void dfs(int u, int fa){
    if(fa && !u){
        ans = 1;
        return ;
    }

    for(int i = 0; i < 2; i++){
        int son = tr[u].son[i];
        if(son && !tr[son].cnt && ){
            dfs(tr[u].son[i], u);
        }
        else dfs(tr[u].fail, u);
        
    }

}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    init();
    cin >> n;
    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        insert(s);
    }

    build(); // 构建失配树

    dfs(0, 0);
    

	return 0;
}