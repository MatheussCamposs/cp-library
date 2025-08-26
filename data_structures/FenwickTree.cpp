// Fenwick Tree (Binary Indexed Tree)
// Suporta atualizacao de elementos e soma de prefixos
// Complexidade: O(log n) por operacao
// Fonte: USACO guide
// Testado em: https://cses.fi/problemset/task/1646

template<class T> struct BIT {
  int size;
  vector<T> bit;
  vector<T> arr;

  BIT(int n) : size(n), bit(n + 1), arr(n) {}

  void set(int idx, T val) { add(idx, val - arr[idx]); }

  void add(int idx, T val) {
    arr[idx] += val;
    for(idx = idx + 1; idx <= size; idx += idx & -idx) {
      bit[idx] += val;
    }
  }

  T pref_sum(int idx) {
    T total = 0;
    for(idx = idx + 1; idx > 0; idx -= idx & -idx) {
      total += bit[idx];
    }
    return total;
  }

  T query(int l, int r) {
    if(!l) return pref_sum(r);
    return pref_sum(r) - pref_sum(l - 1);
  }
};
