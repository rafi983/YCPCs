#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Edge {
    int u, v;
    long long w;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

struct DSU {
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        rank.assign(n + 1, 0);
    }

    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]);
        return parent[i];
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (rank[root_i] < rank[root_j])
                parent[root_i] = root_j;
            else {
                parent[root_j] = root_i;
                if (rank[root_i] == rank[root_j])
                    rank[root_i]++;
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, E;
    if (cin >> N >> E) {
        vector<Edge> edges;
        edges.reserve(E);
        for (int i = 0; i < E; ++i) {
            int u, v;
            long long w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }

        sort(edges.begin(), edges.end(), compareEdges);

        DSU dsu(N);
        long long min_cost = 0;
        int edges_count = 0;

        for (const auto& edge : edges) {
            if (dsu.find(edge.u) != dsu.find(edge.v)) {
                dsu.unite(edge.u, edge.v);
                min_cost += edge.w;
                edges_count++;
            }
        }

        if (edges_count == N - 1) {
            cout << (E - edges_count) << " " << min_cost << endl;
        } else {
            cout << "Not Possible" << endl;
        }
    }
    return 0;
}

