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
        int l = ll, r = rr;
        if (l > r || r >= n) return ;
        
    }

    void ShiftDown(vector<int> &a, int id) {
        while(id <= r) {
            int left = 2 * id + 1;
            int right = 2 * id + 2;

            if (left > r) return ;
            int min_id = left;
            if (right <= r && a[right] < a[left]) min_id = right; 
            if (a[id] <= a[min_id]) return ;
            swap(a[id], a[min_id]);
            id = min_id;
        }
    }
};

int main() {

    

    return 0;
}