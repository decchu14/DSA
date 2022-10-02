#include <bits/stdc++.h>
using namespace std;

void prepareAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int s = edges[i].first;
        int d = edges[i].second;

        adjList[s].insert(d);
        adjList[d].insert(s);
    }
}

void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        // Store frontNode into ans
        ans.push_back(frontNode);

        // Traverse all neighbors of frontNode
        for (auto i : adjList[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int> ans;

    unordered_map<int, set<int>> adjList;

    unordered_map<int, bool> visited;

    prepareAdjList(adjList, edges);

    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(adjList, visited, ans, i);
        }
    }
    return ans;
}

int main()
{
    int v, e, s, d;
    cin >> v >> e;

    vector<pair<int, int>> edges;
    for (int i = 0; i < e; i++)
    {
        cin >> s >> d;
        edges.emplace_back(s, d);
    }

    vector<int> ans = BFS(v, edges);

    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}