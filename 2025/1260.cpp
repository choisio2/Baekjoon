#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> graph[1005];
bool visited_dfs[1005];
bool visited_bfs[1005];

int n, m, start;

void dfs(int node) {
    cout << node << " ";
    visited_dfs[node] = true;

    for (int next : graph[node]) {
        if (!visited_dfs[next]) {
            dfs(next);
        }
    }
}

void bfs(int node) {
    queue<int> q;
    q.push(node);
    visited_bfs[node] = true;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        cout << cur << " ";

        for (int next : graph[cur]) {
            if (!visited_bfs[next]) {
                visited_bfs[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    cin >> n >> m >> start;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // 정점 번호가 작은 것부터 방문하도록 정렬
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(start);
    cout << "\n";
    bfs(start);
    cout << "\n";

    return 0;
}
