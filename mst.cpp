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

struct Edge {
    ll a, b, weight;

    Edge(ll from, ll toa, ll weighta) {
        a = from;
        b = toa;
        weight = weighta;
    }
};

bool sortf(Edge a, Edge b) {
    return (a.weight <= b.weight);
}

struct DisjointSets{
    ll *parent, *rnk;
    ll n;
    DisjointSets(ll n){
        this->n = n;
        parent = new ll[n+1];
        rnk = new ll[n+1];
        for (ll i = 0; i <= n; i++)
        {
            rnk[i] = 0;
            parent[i] = i;
        }
    }

    ll find(ll u){
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
    void merge(ll x, ll y){
        x = find(x), y = find(y);
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else
            parent[x] = y;
        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};

int main() {
    fast
    ll V, E;
    std::cin >> V >> E;
    ll a, b, c;
    std::vector<Edge> graph;
    std::vector<Edge> mst;
    for (ll i = 0; i < E; i++) {
        std::cin >> a >> b >> c;
        a--;
        b--;
        Edge d(a, b,c);
        //Edge f(b,a,c);
        graph.push_back(d);
        //graph.push_back(f);
    }
    std::sort(graph.begin(), graph.end(), sortf);
    DisjointSets ds(V);
    ll count = 0;

    for (ll i = 0; i < graph.size(); i++) {
        ll u = graph[i].a;
        ll v = graph[i].b;
        ll set_u = ds.find(u);
        ll set_v = ds.find(v);
        if (set_u != set_v) {
            //std::cout << u << " - " << v << '\n';
            count += graph[i].weight;
            ds.merge(set_u, set_v);
            mst.push_back(graph[i]);
        }
    }
    //std::sort(mst.begin(),mst.end(),sortf);
    std::cout << count;
    return 0;
}
