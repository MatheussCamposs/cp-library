// Funcao de Mobius (μ)
// Calcula o valor da funcao mobius para cada numero em [1..N]
// mobius[n] =  1  se n eh quadrado-free e tem um numero par de fatores primos
// mobius[n] = -1  se n eh quadrado-free e tem um numero impar de fatores primos
// mobius[n] =  0  se n tem um fator quadrado
// Complexidade: O(N log log N)
// Fonte: USACO Guide

const int MAXN = 1e7;

int mobius[MAXN + 1];

void init() {
  mobius[1] = -1;
  for(int i = 1; i <= MAXN; i++) {
    if(!mobius[i]) continue;
    mobius[i] = -mobius[i];
    for(int j = i + i; j <= MAXN; j += i) mobius[j] += mobius[i];
  }
}
