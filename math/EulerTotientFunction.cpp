// Funcao Totiente de Euler (φ)
// φ(n) = quantidade de inteiros em [1, n-1] que sao coprimos com n
// Fonte: cp-algorithms, Competitive Programming 4

// Calcula φ(n) para um unico n
// Complexidade: O(sqrt n)
int phi(int n) {
  int ret = n;
  for(int i = 2; i * i <= n; i++) {
    if(n % i) continue;
    while(n % i == 0) n /= i;
    ret -= ret / i;
  }
  if(n > 1) ret -= ret / n;
  return ret;
}

// Pre-calcula φ(x) para x ∈ [1, MAXN]
// Complexidade: O(n log log n)
const int MAXN = 1e6;
int phi[MAXN + 1];

void init_phi() {
  for(int i = 0; i <= MAXN; i++) phi[i] = i;
  for(int i = 2; i <= MAXN; i++) {
    if(phi[i] != i) continue;
    for(int j = i; j <= MAXN; j += i) {
      phi[j] -= phi[j] / i;
    }
  }
}

