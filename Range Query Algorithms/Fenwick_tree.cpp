

//Indexing is one based
struct FenWick {
private:
    vector<int> bit;
    int N;

public:
    FenWick(int N) {
        bit.resize(N + 1, 0);
        this -> N = N;
    }

    void update (int pos, int val) {
        while (pos <= N) {
            bit[pos] += val;
            pos += (pos & -pos);
        }
    }
    // one based indexing is used in l and r
    int query(int l, int r) {
        int ans = 0;
        int ans2 = 0;
        l--;
        while (l > 0) {
            ans += bit[l];
            l -= (l & -l);
        }
        while (r > 0) {
            ans2 += bit[r];
            r -= (r & -r);
        }
        return (ans2 - ans);
    }
};

typedef struct FenWick FenWick;


