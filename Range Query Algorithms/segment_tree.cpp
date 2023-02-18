struct seg_tree {

public:
  seg_tree(int n) {
    ans.resize(4 * n + 1);
  }

  void build (int low, int high, int id, vector<int> &a) {
    if (low == high) {
      ans[id] = a[low];
      return ;
    }
    int mid  = low + (high - low) / 2;
    build(low, mid , 2 * id + 1, a);
    build(mid +1, high, 2 * id + 2, a);
    ans[id] = ans[2 * id + 1] + ans[2 * id + 2];
  }

  int query(int l, int r, int curl, int curr, int id) {
    if (l <= curl && r >= curr) {
      return ans[id];
    }
    if (curr < l || curl > r) {
      return 0;
    }
    int mid = curl + (curr - curl) / 2;
    int x = query(l, r, curl, mid, 2 * id + 1);
    int y = query(l, r, mid + 1, curr, 2 * id + 2);
    return x + y;
  }

  void update (int ind, int val, int low, int high, int id) {
    if (low == high) {
      ans[id] = val;
      return ;
    }
    int mid = low + (high - low) / 2;
    if (ind <= mid) {
      update(ind, val, low, mid, 2 * id + 1);
    }
    else {
      update(ind, val, mid + 1, high, 2 * id + 2);
    }
    ans[id] = ans[2 * id + 1] + ans[2 * id + 2];
  }

private:
  vector<int> ans;
};

typedef struct seg_tree seg;
