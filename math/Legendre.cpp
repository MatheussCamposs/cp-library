// Algoritmo de Legendre
// Retorna o maior expoente e tal que k^e divide n!
// Complexidade: O(log_k(n))
// Fonte: cp-algorithms

int legendre(int n, int k) {
  int ret = 0;
  while (n) {
    n /= k;
    ret += n;
  }
  return ret;
}
