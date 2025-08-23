// Struct com solucoes para equacoes diofantinas lineares
// Resolve a * x + b * y = c
// T deve suportar max(a^2, b^2, c^2)
// Fonte: cp-algorithms

template<class T> struct Diophantine {
  T a, b, c;

  Diophantine(T A, T B, T C) : a(A), b(B), c(C) {}

  tuple<T, T, T> extended_euclidean(T na, T nb) {
    if(!nb) return make_tuple(1, 0, na);
    T x, y, g;
    tie(x, y, g) = extended_euclidean(nb, na % nb);
    return make_tuple(y, x - y * (na / nb), g);
  }

  tuple<T, T, T> find_one_solution() {
    T x, y, g;
    tie(x, y, g) = extended_euclidean(abs(a), abs(b));
    if(c % g != 0) return make_tuple(-1, -1, -1);
    x *= c / g;
    y *= c / g;
    if(a < 0) x = -x;
    if(b < 0) y = -y;
    return make_tuple(x, y, g);
  }

  void shift(T &x, T &y, T k) {
    x += b * k;
    y -= a * k;
  }

  T find_all_in_range(T lx, T rx, T ly, T ry) {
    if(lx > rx or ly > ry) return 0;

    if(!a and !b) return c != 0 ? 0 : (rx - lx + 1) * (ry - ly + 1);

    T x, y, g;
    tie(x, y, g) = find_one_solution();

    if(g == -1 or c % g) return 0;

    if(!a) return (rx - lx + 1) * (ly <= c / b and c / b <= ry);

    if(!b) return (ry - ly + 1) * (lx <= c / a and c / a <= rx);

    a /= g;
    b /= g;

    int sa = a > 0 ? 1 : -1;
    int sb = b > 0 ? 1 : -1;

    shift(x, y, (lx - x) / b);
    if(x < lx) shift(x, y, sb);
    if(x > rx) return 0;
    T lx1 = x;

    shift(x, y, (rx - x) / b);
    if(x > rx) shift(x, y, -sb);
    T rx1 = x;

    shift(x, y, -(ly - y) / a);
    if(y < ly) shift(x, y, -sa);
    if(y > ry) return 0;
    T lx2 = x;

    shift(x, y, -(ry - y) / a);
    if(y > ry) shift(x, y, sa);
    T rx2 = x;

    if(lx2 > rx2) swap(lx2, rx2);
    T l = max(lx1, lx2);
    T r = min(rx1, rx2);

    if(l > r) return 0;
    T ret = (r - l) / abs(b) + 1;
    return ret;
  }
};
