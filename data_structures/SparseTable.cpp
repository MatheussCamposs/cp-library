// Sparse Table
// Estrutura para RMQ (range queries) com operacoes idempotentes
// Build: O(N log N), Query: O(1)
// Fonte: cp-algorithms
// Testado em: https://cses.fi/problemset/task/1647

template<class T> struct SparseTable {
  int n;
  int log;
  vector<vector<T>> st;

  T merge(T a, T b) {
    return min(a, b);
  }

  int log2_floor(unsigned int x) {
    return 31 - __builtin_clz(x);
  }

  SparseTable(const vector<T> &arr) {
    n = (int)arr.size();
    log = log2_floor(n);
    st.assign(log + 1, vector<T>(n));
    for(int i = 0; i < n; i++) st[0][i] = arr[i];
    for(int k = 1; k <= log; k++) {
      for(int i = 0; i + (1 << k) <= n; i++) {
        st[k][i] = merge(st[k-1][i], st[k-1][i + (1 << (k-1))]);
      }
    }
  }

  T query(int l, int r) {
    int p = log2_floor(r - l + 1);
    return merge(st[p][l], st[p][r - (1 << p) + 1]);
  }
};
