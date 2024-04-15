struct RollHash {
public:
	RollHash() {};
	RollHash(const string &s, const int MOD) {
		len = s.length(); hash.resize(len + 1, 0); revHash.resize(len + 1, 0); pw.resize(len + 1, 1); mod = MOD;
		base = genBase(256, mod);
		for (int i = 1; i <= len; i++) pw[i] = (1LL * pw[i - 1] * base) % mod;
		for (int i = 1; i <= len; i++) {
			hash[i] = (1LL * hash[i - 1] * base + s[i - 1]) % mod;
			revHash[i] = (1LL * revHash[i - 1] * base + s[len - i]) % mod;;
		}
	}
	// Returns hash of the string from position pos and length l . Indexing is one based.
	// type 0 returns the forward hash and type 1 returns the reverse hash of the unreversed string
	int getHash(int pos, int l, int type){
		int res = 0;
		if(type & 1) {
			pos = len - (pos + l) + 2;
			res = (1LL * revHash[pos + l - 1] - 1LL * revHash[pos - 1] * pw[l]) % mod;
		}else {
			res = (1LL * hash[pos + l - 1] - 1LL * hash[pos - 1] * pw[l]) % mod;
		}
		return (res < 0 ? res + mod : res) ;
	}
	int genBase(const int start, int end) {
	auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
	std::mt19937 mt_rand(seed);
	int base = std::uniform_int_distribution<int> (start + 1, end)(mt_rand);
	base = (base & 1 ? base : base - 1);
	return base;
}	
private:
	int len;
	vector<int> hash, revHash;
	vector<int> pw;
	int mod, base;
};
 
struct DoubleHash {
public:
	DoubleHash(const string &s) {
		first = RollHash(s, 1e9 + 7);
		second = RollHash(s, 1610612741);
	}
	// Returns hash of the string from position pos and length l . Indexing is one based.
	// type 0 returns the forward hash and type 1 returns the reverse hash of the unreversed string
	long long getHash(int pos, int l, int type) {
		long long res = 0;
		res = (1LL * first.getHash(pos, l, type)) << 32;
		res ^= 1LL * second.getHash(pos, l, type);
		return res;
	}
private:
	RollHash first, second;
};
