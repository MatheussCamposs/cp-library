// Segment Tree com Lazy Propagation
// operacoes padrao: 
//  query(l, r) retorna a soma no intervalo [l, r]
//  update(l, r, x) soma 'x' em todos os elementos no intervalo [l, r]
// Complexidade: O(log N) por operacao

template<class T> struct SegmentTree {
  vector<T> seg, lazy;
  T null_value = 0;
  int N;

  T merge(T a, T b) {
    return a + b;
  }

  SegmentTree(int n) {
    seg.resize(4 * n);
    lazy.resize(4 * n);
    N = n;
  }

  SegmentTree(vector<T> &arr) : SegmentTree((int)arr.size()) {
    build(1, 0, N - 1, arr);
  }

  T build(int at, int low, int high, vector<T> &arr) {
    if(low == high) return seg[at] = arr[low];
    int mid = (low + high) >> 1;
    return seg[at] = merge(build(at * 2, low, mid, arr), build(at * 2 + 1, mid + 1, high, arr));
  }

  void prop(int at, int low, int high) {
    if(lazy[at] != 0) {
      seg[at] += lazy[at] * (high - low + 1);
      if(low != high) {
        lazy[at * 2] += lazy[at];
        lazy[at * 2 + 1] += lazy[at];
      }
      lazy[at] = 0;
    }
  }

  T update(int l, int r, T x, int at, int low, int high) {
    prop(at, low, high);
    if(low > r or high < l) return seg[at];
    if(low >= l and high <= r) {
      lazy[at] += x;
      prop(at, low, high);
      return seg[at];
    }
    int mid = (low + high) >> 1;
    return seg[at] = merge(update(l, r, x, at * 2, low, mid), update(l, r, x, at * 2 + 1, mid + 1, high));
  }

  T query(int l, int r, int at, int low, int high) {
    prop(at, low, high);
    if(low > r or high < l) return null_value;
    if(low >= l and high <= r) return seg[at];
    int mid = (low + high) >> 1;
    return merge(query(l, r, at * 2, low, mid), query(l, r, at * 2 + 1, mid + 1, high));
  }

  T update(int l, int r, T x) { return update(l, r, x, 1, 0, N - 1); }

  T query(int l, int r) { return query(l, r, 1, 0, N - 1); }
};
