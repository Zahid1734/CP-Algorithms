
void ext_euclid(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return ;
    }
    long long x1, y1;
    ext_euclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
}

// Works for both prime and noncoprime moduli
pair<long long, long long> chinese_remainder (vector<ll> &A, vector<ll> &M) {
  if (A.size() - M.size()) return {-1, -1}; // No solution exists
  int n = A.size();
  long long a1 = A[0];
  long long m1 = M[0];

  a1 %= m1;

  for (int i = 1; i < n; i++) {
    long long a2 = A[i];
    long long m2 = M[i];

    long long g = __gcd(m1, m2);
    if (a1 % g != a2 % g) return {-1, -1};

    long long p, q;
    ext_euclid (m1 / g , m2 / g, p, q);

    long long mod = m1  / g * m2;
    long long x = ( (__int128)a1 * (m2/g) % mod *q % mod + (__int128)a2 * (m1/g) % mod * p % mod ) % mod;

    a1 = x;
    if (a1 < 0) a1 += mod;
    m1 = mod;
  }

  return {a1, m1};
}
