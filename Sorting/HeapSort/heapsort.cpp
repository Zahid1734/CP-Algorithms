#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #include "debug.h"
#else 
    #define dbg(...) 43
#endif

class HeapSort {
private:
    int n;
    int l, r;
public:
    // sorts array a from index ll to index rr
    HeapSort(vector<int> &a, int ll, int rr) {
        int n = a.size();
        l = ll, r = rr;
        if (l > r || r >= n) return ;

        // creating the heap in O(n) instead of O(nlogn)
        for (int i = r; i >= l; i--) {
            ShiftDown(a, i - l);
        }
        //Sorting the vector using the heap property
        dbg(a);
        while(l <= r) {
            swap(a[l], a[r]);
            r--;
            ShiftDown(a, 0);
        }
    }

    void ShiftDown(vector<int> &a, int id) {
        while(id <= r - l) {
            int left = 2 * id + 1;
            int right = 2 * id + 2;

            if (left > r - l) return ;
            int min_id = left;
            if (right <= r - l && a[right + l] < a[left + l]) min_id = right; 
            if (a[id + l] <= a[min_id + l]) return ;
            swap(a[id + l], a[min_id + l]);
            id = min_id;
        }
    }
};

int main() {

    vector<int> a = {5, 4, 3, 1, 2};

    // Usage -> (vector to sort, left border, right border) indexing is zero based
    HeapSort heap(a, 2, 4);

    for (int i = 4; i >= 2; i--) cout << a[i] << " ";

    return 0;
}