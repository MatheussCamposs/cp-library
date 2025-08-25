// Disjoint Set Union (DSU)
// Estrutura para uniao e busca em conjuntos disjuntos
// Complexidade O(alpha(n)), onde alpha e a funcao inversa de Ackermann
// Fonte: USACO Guide

struct DSU {
  vector<int> parent;
  vector<int> sz;
  DSU(int n) : parent(n), sz(n, 1) {
    iota(parent.begin(), parent.end(), 0);
  }
  int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
  }
  bool unite(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) return false;
    if(sz[v] > sz[u]) swap(u, v);
    parent[v] = u;
    sz[u] += sz[v];
    return true;
  }
  bool connected(int u, int v) { return find(u) == find(v); }
};
