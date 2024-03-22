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

void findEueler(int v, std::vector<std::vector<int>>& graph, std::vector<int>& ans) {
    std::stack<int> stack;
    stack.push(v);
    while (!stack.empty()) {
        int w = stack.top();
        bool found = false;
        for (int i = 0; i < graph[w].size(); i++) {
                int save = graph[w][i];
                stack.push(graph[w][i]);
                graph[w].erase(graph[w].begin() + i);
                for (int j = 0; i < graph[save].size(); j++) {
                    if (graph[save][j] == w) {
                        graph[save].erase(graph[save].begin()+j);
                        break;
                    }
                }
                found = true;
                break;
        }
        if (!found) {
            stack.pop();
            ans.push_back(w);
        }
    }
}

void dfs(int cur_v, std::vector<std::vector<int>>& g, std::vector<int>& vertexs, int cVertex){
    vertexs[cur_v] = 1;
    for (int i : g[cur_v]) {
        if (vertexs[i] == -1){
            dfs(i,g,vertexs,cVertex);
        }
    }
}

int main() {
    fast
    int V, E;
    std::cin >> V >> E;
    int a, b;
    //std::vector<std::pair<int,int>> graph;
    std::vector<std::vector<int>> graphV(V);
    std::vector<int> vis(V,-1);
    std::vector<int> ans;
    for (int i = 0; i < E; i++) {
        std::cin >> a >> b;
        a--;
        b--;
        //graph.emplace_back(a,b);
        graphV[a].push_back(b);
        graphV[b].push_back(a);
    }
    dfs(0,graphV,vis,V);
    for (int i = 0; i < graphV.size(); i++) {
        if (graphV[i].size() % 2 == 1 || (graphV[i].size() > 0 && vis[i] == -1)) {
            std::cout << ":(";
            exit(0);
        }
    }
    findEueler(0,graphV,ans);
    std::reverse(ans.begin(), ans.end());
    for (int an : ans) {
        std::cout << an+1 << " ";
    }
    return 0;
}
