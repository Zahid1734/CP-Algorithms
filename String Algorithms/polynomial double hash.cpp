
using ull = unsigned long long;

int gen_base (const int start, const int end) {
  auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
  std::mt19937 mt_rand(seed);
  int base = std::uniform_int_distribution<int>(start+1, end)(mt_rand);
  return base % 2 == 0 ? base-1 : base;
}

typedef struct polyHash {
  int len;
  static const int m1 = 1e9 + 9;
  static const int m2 = 1e9 + 7;
  static int base;
  vector<int> P1, hash1, rev_hash1;
  vector<int> P2, hash2, rev_hash2;

  polyHash(string &s) {
    assert(base < m2);
    len = s.length();
    hash1.resize(len + 1, 0);
    hash2.resize(len + 1, 0);
    rev_hash1.resize(len + 1, 0);
    rev_hash2.resize(len + 1, 0);
    P1.resize(len + 1, 1);
    P2.resize(len + 1, 1);

    for (int i = 1; i <= len; i++) {
      P1[i] = 1LL * P1[i - 1] * base % m1;
      P2[i] = 1LL * P2[i - 1] * base % m2;
    }

    for (int i = 1; i <= len; i++) {
      assert(s[i] < base);
      hash1[i] = (1LL * hash1[i-1] * base % m1 + 1LL * s[i - 1] ) % m1;
      hash2[i] = (1LL * hash2[i-1] * base % m2 + 1LL * s[i - 1] ) % m2;
    }

    for (int i = 1; i <= len; i++) {
      rev_hash1[i] = (1LL * rev_hash1[i - 1] * base % m1 + 1LL * s[len - i]) % m1;
      rev_hash2[i] = (1LL * rev_hash2[i - 1] * base % m2 + 1LL * s[len - i]) % m2;
    }
  }

  // Return hash from pos to length l
  // pos is one based indexed
  inline  unsigned long long getHash(int pos, int l) {

    int one = (hash1[pos + l - 1] - 1LL * hash1[pos - 1] * P1[l] % m1) % m1;
    if (one < 0) one += m1;
    int two = (hash2[pos + l - 1] - 1LL * hash2[pos - 1] * P2[l] % m2) % m2;
    if (two < 0) two += m2;
    unsigned long long ans = one;
    ans <<= 32;
    ans ^= two;
    return ans;
  }

  //Returns the reverse hash from position pos and length l in unreversed string
  //pos in one based indexed
  inline unsigned long long getReverse(int pos, int l) {
    pos = len - (pos + l) + 2;
    int one = (rev_hash1[pos + l - 1] - 1LL * rev_hash1[pos - 1] * P1[pos] % m1) % m1;
    if (one < 0) one += m1;
    int two = (rev_hash2[pos + l - 1] - 1LL * rev_hash2[pos - 1] * P2[pos] % m2) % m2;
    if (two < 0) two += m2;
    unsigned long long ans = one;
    ans <<= 32;
    ans ^= two;
    return ans;
  }

} polyHash;

int polyHash::base = gen_base(256, polyHash::m2);
