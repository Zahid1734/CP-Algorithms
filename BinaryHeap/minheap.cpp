#include <bits/stdc++.h>


using namespace std;

#ifdef LOCAL
    #include "debug.h"
#else 
    #define dbg(...) 43
#endif



class min_heap {
public:
	int n; 
	vector<int> heap;

public:

	min_heap(int max_sz) {
		n = 0;
		heap.resize(max_sz, 0);
	}

	void shift_up(int id) {
		while(id > 0) {
			int par = (id - 1) / 2;
			if (heap[id] < heap[par]) {
				swap(heap[id], heap[par]);
			}else break;
			id = par;
		}
	}

	void shift_down(int id) {
		while(id < n) {
			int left = 2 * id + 1;
			int right = 2 * id + 2;

			if (left < n) {
				int min_id = left;
				if (right < n) {
					if (heap[right] < heap[left]) {
						min_id = right;
					}
				}
				if (heap[id] > heap[min_id]) swap(heap[id], heap[min_id]), id = min_id;
				else return ;
			}
			else return;
		}
	}

	void insert(int x) {
		heap[n++] = x;
		shift_up(n - 1);
	}

	int remove_min() {
		if (n == 0) {
			cout << "Error! no item in the container";
			return -1;
		} 
		int res = heap[0];
		swap(heap[0], heap[n - 1]);
		n--;
		shift_down(0);
		return res;
	}
};


int main() {

	freopen("in", "r", stdin);
	multiset<int> st;
	int n; cin >> n;	
	min_heap heap(n + 5);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		st.insert(x);
		heap.insert(x);
	}

	//dbg(heap.heap);

	for (int i = 0; i < n; i++) {
		int x = *st.begin();
		st.erase(st.begin());
		//dbg(st); 
		int xx = heap.remove_min();
		//dbg(heap.heap);
		if (xx - x) {
			cout << xx << " " << x << "\n";
			cout << "Falty\n";
			break;
		}
	}
	return 0;
}