// Teorema do Resto Chines (Chinese Remainder Theorem)
// Resolve um sistema de congruencia x ≡ a (mod m)
// Os moduli nao precisam ser coprimos entre si
// Retorna {solucao, lcm dos moduli} ou {-1, -1} se nao existir solucao
// Complexidade: O(N log M), onde N = numero de congruencias, M = produto dos moduli
// Fonte: cp-algorithms, USACO Guide, Competitive Programming 4

struct Congruence {
  int a, m;
};

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

int inverse(int a, int m) {
  int x, y, g;
  tie(x, y, g) = extended_euclidean(a, m);
  if(g != 1) return -1;
  return (x % m + m) % m;
}

pair<int, int> crt(const vector<Congruence>& congruences) {
  int x = congruences[0].a;
  int m = congruences[0].m;

  for(int i = 1; i < (int)congruences.size(); i++) {
    int a2 = congruences[i].a;
    int m2 = congruences[i].m;

    int x1, y1, g = 0;
    tie(x1, y1, g) = extended_euclidean(m, m2);
    if((a2 - x) % g != 0) return {-1, -1};

    int lcm = m / g * m2;
    int mul = ((a2 - x) / g % (m2 / g) * x1) % (m2 / g);
    x = (x + mul * m) % lcm;
    if(x < 0) x += lcm;
    m = lcm;
  }
  return {x, m};
}

