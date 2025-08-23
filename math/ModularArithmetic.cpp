// Aritmetica Modular
// Estrutura para operacoes basicas no modulo MOD (precisa ser primo)
// Operacoes suportadas: +, -, *, /
// Complexidade: O(log expo) para fexp e inverse, O(1) para os demais
// Baseado em: https://github.com/brunomaletta e https://github.com/bqi343

template<int mod> struct mod_int {
  static const int MOD = mod;
  int value;
  mod_int() { value = 0; }
  mod_int(int nvalue) {
    value = nvalue % MOD;
    if(value < 0) value += MOD;
  }
  mod_int& operator+=(const mod_int &b) {
    value += b.value;
    if(value >= MOD) value -= MOD;
    return *this;
  }
  mod_int& operator-=(const mod_int &b) {
    value -= b.value;
    if(value < 0) value += MOD;
    return *this;
  }
  mod_int& operator*=(const mod_int &b) {
    value = value * b.value % MOD;
    return *this;
  }
  mod_int& operator/=(const mod_int &b) {
    return *this *= inverse(b);
  }
  friend mod_int fexp(mod_int base, int expo) {
    mod_int ans = 1;
    while(expo) {
      if(expo & 1) ans *= base;
      base *= base;
      expo >>= 1;
    }
    return ans;
  }
  friend mod_int inverse(const mod_int a) { return fexp(a, MOD - 2); }
  friend mod_int operator+(mod_int a, mod_int b) { return a += b; }
  friend mod_int operator-(mod_int a, mod_int b) { return a -= b; }
  friend mod_int operator*(mod_int a, mod_int b) { return a *= b; }
  friend mod_int operator/(mod_int a, mod_int b) { return a /= b; }
  friend mod_int operator+(mod_int a, int b) { return a += mod_int(b); }
  friend mod_int operator-(mod_int a, int b) { return a -= mod_int(b); }
  friend mod_int operator*(mod_int a, int b) { return a *= mod_int(b); }
  friend mod_int operator/(mod_int a, int b) { return a /= mod_int(b); }
  friend mod_int operator+(int a, mod_int b) { return mod_int(a) += b; }
  friend mod_int operator-(int a, mod_int b) { return mod_int(a) -= b; }
  friend mod_int operator*(int a, mod_int b) { return mod_int(a) *= b; }
  friend mod_int operator/(int a, mod_int b) { return mod_int(a) /= b; }
  friend ostream& operator<<(ostream &out, const mod_int &m) { return out << m.value; }
  friend istream& operator>>(istream &in, mod_int &m) {
    int x;
    in >> x;
    m = mod_int(x);
    return in;
  }
};
using mint = mod_int<1000000007>;

