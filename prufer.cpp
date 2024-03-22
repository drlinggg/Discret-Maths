#include <bits/stdc++.h>
#define fast std::cin.tie(0);std::ios_base::sync_with_stdio(0);
//using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const ll RBN = 1e9 + 7;
const ll RSN = -(1e9 + 7);
const double PI = 3.141592653589793;
//mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count()); ll gen(){return rnd()%100;}

void dfs(int v, int parent[], std::vector<std::vector<int>>& graph){
    for (int i = 0; i < graph[v].size(); i++) {
        int to = graph[v][i];
        if (to != parent[v]){
            parent[to] = v;
            dfs(to, parent, graph);
        }
    }
}

void prufer_code(int V, int parent[], std::vector<std::vector<int>>& graph, int degree[]){
    int ptr = -1;
    parent[V-1] = -1;
    dfs(V-1, parent, graph);
    for (int i=0; i<V; i++) {
        degree[i] = (int) graph[i].size();
        if (degree[i] == 1 && ptr == -1) {
            ptr = i;
        }
    }
    int leaf = ptr;
    for (int iter=0; iter<V-2; iter++) {
        int next = parent[leaf];
        std::cout << next + 1 << ' ';
        degree[next]--;
        if (degree[next] == 1 && next < ptr) {
            leaf = next;
        }
        else {
            ptr++;
            while (ptr<V && degree[ptr] != 1) {
                ptr++;
            }
            leaf = ptr;
        }
    }
}

int main() {
    fast
    int V, E, a, b;
    std::cin >> V >> E;
    int parent[V];
    int degree[V];
    std::vector<std::vector<int>> graphV(V);
    for (ll i = 0; i < E; i++) {
        std::cin >> a >> b;
        a--;
        b--;
        graphV[a].push_back(b);
        graphV[b].push_back(a);
    }
    prufer_code(V, parent,graphV,degree);
    return 0;
}
