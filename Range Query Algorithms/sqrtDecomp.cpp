
struct sqrtDecomp {
private:
    int N; vector<int> b, a; int B;
public:
    sqrtDecomp(int n, vector<int> &A) {
        N = n;
        B = sqrt(N) + 1;
        b.resize(B, 0);
        a.resize(N);
        for (int i = 0; i < N; i++) a[i] = A[i];
    }
    void build() {
        for (int i = 0; i < N; i++) {
            b[i / B] += a[i];
        }
    }
    // l and r follows zero based indexing
    int query(int l, int r) {
        int sum = 0;
        for (int i = l; i <= r;) {
            if ((i / B) * B >= l && (i / B) * B + (B - 1) <= r) sum += b[i / B], i += B;
            else sum += a[i], i++;
        }
        return sum;
    }
    // pos is zero based
    void update (int pos, int val) {
        b[pos / B] += (val - a[pos]);
        a[pos] = val;
    }
};

