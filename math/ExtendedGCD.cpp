// Algoritmo de Euclides Estendido
// Calcula o gcd(a, b) e os coeficientes x e y tal que a * x + b * y = gcd(a, b)
// Retorna: tuple (x, y, gcd(a, b))
// Complexidade: O(log min(a, b))
// Fonte: cp-algorithms

//Recursivo:
tuple<int,int,int> extended_euclidean(int a, int b) {
  if(!b) return make_tuple(1, 0, a);
  int x, y, g;
  tie(x, y, g) = extended_euclidean(b, a % b);
  return make_tuple(y, x - y * (a / b), g);
}

//Iterativo:
tuple<int,int,int> extended_euclidean(int a, int b) {
  int x = 1, y = 0;
  int x1 = 0, y1 = 1, a1 = a, b1 = b;
  while(b1) {
    int q = a1 / b1;
    tie(x, x1) = make_tuple(x1, x - q * x1);
    tie(y, y1) = make_tuple(y1, y - q * y1);
    tie(a1, b1) = make_tuple(b1, a1 - q * b1);
  }
  return make_tuple(x, y, a1);
}
