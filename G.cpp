//G - Longest Path

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > adj;
vector<bool> visited;
vector<int> depth; // maximum depth at subtree rooted at vertex i

void dfs(int u){
    visited[u] = true;

    for(int v: adj[u]){
        if(!visited[v]){
            dfs(v);
        }
        depth[u] = max(depth[u], 1 + depth[v]);
    }
}

int main(){

    int n; cin >> n;
    int m; cin >> m;

    adj.assign(n+1, vector<int>());
    visited.assign(n+1, false);
    depth.assign(n+1,0);

    for(int i = 0; i < m; ++i){
        int from; cin >> from;
        int to; cin >> to;
        adj[from].push_back(to);
    }

    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            dfs(i);
        }
    }

    int ans = -1;
    for(int i = 1; i <= n; ++i){
        //cout << depth[i] << " ";
        ans = max(ans, depth[i]);
    }
    //cout << "\n";
    cout << ans << "\n";

    return 0;
}