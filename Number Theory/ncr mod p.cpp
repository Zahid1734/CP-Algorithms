
using ll = long long
typedef struct NCR {
  private:
    int mod;
    int n;
    vector<ll> fact;
    //vector<ll> inv;

  public:
    NCR (int N, int M) {
          n = N;
          fact = vector<ll> (N + 1, 0);
          //inv = vector<ll> (M + 1, 0);
          mod = M;
          fact[0] = 1;
          //inv[0]  = 1;
          //inv[1] = 1;
          for (int i = 1; i <= N; i++) {
            fact[i] = ( fact[i-1] % mod * i % mod ) % mod;
          }
//      for (int i = 2; i <= mod; i++) {
//        inv[i] = (-mod / i * inv[mod % i]) % mod;
//        inv[i] += mod;
//      }
    }
    long long binaryExpo(long long a, long long p) {
        long long ans = 1;
        if (p == 0) return ans;
        ans = binaryExpo(a, p / 2);
        ans = (ans % mod * ans % mod) % mod;
        if (p & 1LL) ans = ans * a % mod;
        return ans;
    }
    // If mod is very huge and prime then use binary expo
    // Otherwise use the inv method
    ll ncr(ll N, ll r) {
      if (r > N) return 0;
      if (r == 0) return 1;
      ll ans = (fact[N] % mod * /*(inv[fact[r]] % mod)*/ binaryExpo(fact[r], mod - 2)  * /*(inv[fact[N-r]] % mod)*/ binaryExpo(fact[N - r], mod - 2)) % mod;
      return ans;
    }
}NCR;

