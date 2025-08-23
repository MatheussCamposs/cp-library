// Algoritmo de Euclides binario (Stein)
// Calcula o gcd(a, b)
// Complexidade: O(log(min(a, b)))
// Fonte: cp-algorithms

int gcd(int a, int b) {
  if(!a or !b) return a | b;
  unsigned shift = __builtin_ctz(a | b);
  a >>= __builtin_ctz(a);
  do {
    b >>= __builtin_ctz(b);
    if(a > b) swap(a, b);
    b -= a;
  } while(b);
  return a << shift;
}
