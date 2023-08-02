#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <array>
#include <climits>

#define pb push_back
#define sz(x) (int)x.size()
#define vec vector

using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int r, n, m;

struct Matrix {
    int mat[2][2];

    Matrix(int _mat[][2]) {
        mat[0][0] = _mat[0][0];
        mat[0][1] = _mat[0][1];
        mat[1][0] = _mat[1][0];
        mat[1][1] = _mat[1][1];
    }
    ll get(int r, int c) { return mat[r][c]; }

    Matrix operator*(Matrix &b) {
        int mat2[2][2];

        mat2[0][0] = (mat[0][0] * b.get(0, 0) + mat[0][1] * b.get(1, 0)) % r;
        mat2[0][1] = (mat[0][0] * b.get(0, 1) + mat[0][1] * b.get(1, 1)) % r;
        mat2[1][0] = (mat[1][0] * b.get(0, 0) + mat[1][1] * b.get(1, 0)) % r;
        mat2[1][1] = (mat[1][0] * b.get(0, 1) + mat[1][1] * b.get(1, 1)) % r;

        Matrix res(mat2);
        return res;
    }

    void print() {
        cout << mat[0][0] << " " << mat[0][1] << '\n';
        cout << mat[1][0] << " " << mat[1][1] << '\n';
    }

};

Matrix def() {
    int x[2][2] = {{1, 0}, {0, 1}};
    return Matrix(x);
}

struct SegTree {
    int n;
    vector<Matrix> v;
    vector<Matrix> tree;

    SegTree(vector<Matrix> &_v) {
        n = sz(_v);
        v = _v;
        for(int i=0; i<4*n+5; i++) {
            int x[2][2] = {{0,0},{0,0}};
            tree.pb(x);
        }
        build(1, 0, n-1);
    }

    void build(int u, int l, int r) {
        if(l == r) {
            tree[u] = v[l];
        } else {
            int m = (l + r) / 2;
            build(2*u, l, m);
            build(2*u+1, m+1, r);
            Matrix a = tree[2*u];
            Matrix b = tree[2*u+1];
            Matrix c = a * b;
            tree[u] = c;
        }
    }

    Matrix query(int u, int tl, int tr, int l, int r) {
        if(tl > r || l > tr) return def();
        if(l <= tl && tr <= r) return tree[u];
        int tm = (tl + tr) / 2;
        Matrix a = query(2*u, tl, tm, l, r);
        Matrix b = query(2*u+1, tm+1, tr, l, r);
        Matrix c = def();
        c = a * b;
        return c;
    }

    Matrix query(int l, int r) {
        return query(1, 0, n-1, l, r);
    }

    Matrix get(int u) {
        return tree[u];
    }
};

int32_t main() {
    setIO();

    cin >> r >> n >> m;

    vector<Matrix> v;
    for(int i=0; i<n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int mat[2][2] = {{a%r, b%r}, {c%r, d%r}};
        Matrix matrix(mat);
        v.pb(matrix);
    }

    SegTree tree(v);
    while(m--) {
        int a, b;
        cin >> a >> b;
        Matrix m = tree.query(a-1, b-1);
        m.print();
        cout << '\n';
    }

    return 0;
}