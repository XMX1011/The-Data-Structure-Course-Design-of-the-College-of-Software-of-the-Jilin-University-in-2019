#include "stdc++.h"
using namespace std;
const int N = 501, M = 1010;
typedef pair<int, int> pii;
int h[N], to[M], nxt[M], cnt, vis[N];
int n, m, res;
vector<pii> G;
void add(int u, int v)
{
    to[++cnt] = v;
    nxt[cnt] = h[u];
    h[u] = cnt; //创建邻接表
}

void dfs(int u)
{ //深度优先遍历
    vis[u] = 1;
    printf("->%d", u);
    for (int i = h[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (!vis[v])
            dfs(v);
    }
}
void bfs(int u)
{ //广度优先遍历
    queue<int> q;
    q.push(u);
    vis[u] = 1;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        printf("->%d", v);
        vis[v] = 1;
        for (int i = h[v]; i; i = nxt[i])
            if (!vis[to[i]])
                q.push(to[i]);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int u, v, i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        G.push_back({u, v}); //加边
    }
    sort(G.begin(), G.end()); //排序
    for (int i = 0; i < m; i++)
    {
        add(G[i].first, G[i].second); //加边
    }
    scanf("%d", &res);
    cout << "dfs:";
    dfs(res);
    puts("");
    memset(vis, 0, sizeof vis);
    cout << "bfs:";
    bfs(res);
    cout << endl;
    system("pause");
    return 0;
}