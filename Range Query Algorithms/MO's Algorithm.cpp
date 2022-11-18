
inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}
 
struct Query {
	int l, r, idx;
	int64_t ord;
	// For each query call calcOrder after taking ranges input
	inline void calcOrder() {
		ord = gilbertOrder(l, r, 21, 0);
	}
	inline bool operator<(const Query &b) {
		return ord < b.ord;
	}
};

void add(int idx) {
	
}

void remove (int idx) {

}

int getAns(int l, int r) {
	
}
 
vector<int> mo_s_algorithm (vector<Query> &query) {
	int q = query.size();
	sort(query.begin(), query.end());
	vector<int> ans(q, 0);
	int left = 0, right = -1;
	for (int i = 0; i < q; i++) {
		while (right + 1 <= query[i].r) add(++right);
		while (right > query[i].r) remove(right--);
		while (left - 1 >= query[i].l) add(--left);
		while (left < query[i].l) remove(left++);
		ans[query[i].idx] = getAns();; 
	}
	return ans;
}

