typedef struct DSU {
    DSU (int n) {
      id.resize(n);
      sz.resize(n, 1);
      components = n;
      for (int i = 0; i < n; i++) id[i] = i;
    }
    public:

      int root (int n) {
        while (id[n] != n) {
          id[n] = id[id[n]];
          n = id[n];
        }
        return n;
      }
      void Union (int p, int q) {
        int rootp = root(p);
        int rootq = root(q);
        if (rootp == rootq) return ;
        components--;
        if (sz[rootp] > sz[rootq]) {
          id[rootq] = rootp;
          sz[rootp] += sz[rootq];
        }else {
          id[rootp] = rootq;
          sz[rootq] += sz[rootp];
        }
      }
      bool connected (int p, int q) {
        return root(p) == root(q);
      }
      int Component() {
        return components;
      }
    private:
      vector<int> id;
      vector<int> sz;
      int components;

  }DSU;
