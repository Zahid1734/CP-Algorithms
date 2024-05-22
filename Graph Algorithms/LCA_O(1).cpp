#include <bits/stdc++.h>
using namespace std;
template<class T> 
class sparseTable {
public:
	sparseTable() {}
	sparseTable(int _n) {
		n = _n;
		log.resize(n + 1);
		table.resize(n, vector<T>(log2(n) + 1));
		log[1] = 0;
		for (int i = 2; i <= n; i++) log[i] = log[i / 2] + 1; 
	}
	// function to prepare the table for query
	void makeTable(vector<T> &a) {
		for (int i = 0; i < n; i++) {
			table[i][0] = i;
		}
		int mxJump = log[n];
		for (int j = 1; j <= mxJump; j++) {
			for (int i = 0; i + (1 << j) - 1 < n; i++) {
				T val = min(a[table[i][j - 1]], a[table[i + (1 << (j - 1))][j - 1]]);
				table[i][j] = (val == a[table[i][j - 1]] ? table[i][j - 1] : table[i + (1 << (j - 1))][j - 1]);
			}
		}
	}
	// L and R are zero based
	// Returns the index of the minimum number in the range [L..R]
	T query(int L, int R) {
		int gap = R - L + 1;
		int gapLog = log[gap];
		return min(table[L][gapLog], table[R - (1 << gapLog) + 1][gapLog]);
	}

private:
	int n;
	vector<vector<T>> table;
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
		st = sparseTable<int> (2 * n - 1);
		st.makeTable(depth);
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

int main() {
	int n; cin >> n;
	vector<vector<int>> adj(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}
	ancestor<int> anscs(n);
	anscs.makeTour(adj, 0, 0);
	anscs.prepareTable();
	cout << anscs.findLca(1, 4);
	return 0;
}
