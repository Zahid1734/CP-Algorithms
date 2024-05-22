#include <bits/stdc++.h>

using namespace std;

template<class T> 
class sparseTable {
public:
	sparseTable() {}
	sparseTable(int _n, vector<int> &a) {
		n = _n;
		log.resize(n + 1); _a.resize(_n);
		table.resize(n, vector<T>(log2(n) + 1));
		log[1] = 0;
		for (int i = 2; i <= n; i++) log[i] = log[i / 2] + 1; 
		for(int i = 0; i < n; i++) _a[i] = a[i];
		makeTable();
	}
	// function to prepare the table for query
	void makeTable() {
		for (int i = 0; i < n; i++) {
			table[i][0] = i;
		}
		int mxJump = log[n];
		for (int j = 1; j <= mxJump; j++) {
			for (int i = 0; i + (1 << j) - 1 < n; i++) {
				T val = min(_a[table[i][j - 1]], _a[table[i + (1 << (j - 1))][j - 1]]);
				table[i][j] = (val == _a[table[i][j - 1]] ? table[i][j - 1] : table[i + (1 << (j - 1))][j - 1]);
			}
		}
	}
	// L and R are zero based
	// Returns the index of the minimum number in the range [L..R]
	T query(int L, int R) {
		int gap = R - L + 1;
		int gapLog = log[gap];
		T val = min(_a[table[L][gapLog]], _a[table[R - (1 << gapLog) + 1][gapLog]]); 
		return (val == _a[table[L][gapLog]] ? table[L][gapLog] : table[R - (1 << gapLog) + 1][gapLog]);
	}

private:
	int n;
	vector<vector<T>> table;
	vector<T> _a;
	vector<int> log;
};

template<class T> 
class ancestor {
public:
	ancestor(){}
	ancestor(int _n) {
		n = _n;
		eulerTour.resize(2 * n - 1, -1);
		depth.resize(2 * n - 1, 0);
		last.resize(n);
		id = 0;
	}	
	void updatePar(int node, int dep) {
		eulerTour[id] = node;
		depth[id] = dep;
		last[node] = id++;
	}
	void makeTour(vector<vector<T>> &adj, int node, int dep) {
		updatePar(node, dep);
		for (auto child : adj[node]) {
			makeTour(adj, child, dep + 1);
			updatePar(node, dep);
		}
	}
	void prepareTable() {
		st = sparseTable<int> (2 * n - 1, depth);
	}
	int findLca(int u, int v) {
		int L = last[u], R = last[v];
		if (L > R) swap(L, R);
		return eulerTour[st.query(L, R)];
	} 
private:
	int n;
	vector<T> eulerTour;
	vector<int> depth;
	vector<int> last;
	sparseTable<T> st;	
	int id;
};

void solve(int t) {
	cout << "Case " << t << ":\n";
	int n; cin >> n;
	ancestor<int> ances(n);
	vector<vector<int>> adj(n);
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		for (int j = 0; j < x; j++) {
			int v; cin >> v;
			adj[i].push_back(v - 1);
		}
	}
	ances.makeTour(adj, 0, 0);
	ances.prepareTable();
	int q; cin >> q;
	while(q--) {
		int u, v; cin >> u >> v;
		int res = ances.findLca(u - 1, v - 1);
		cout << res + 1 << "\n";
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(nullptr);

	int tc = 1; cin >> tc;
	for (int t = 1; t <= tc; t++) {
		solve(t);
	}
	return 0;
}
