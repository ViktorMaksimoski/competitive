#include <bits/stdc++.h>
using namespace std;

int getLine(int a) {
    int l=0, r=300;
    int ans = 0;

    while(l <= r) {
        int mid = (l + r) / 2;
        if(mid * (mid + 1) >= 2 * a) ans = mid, r = mid - 1;
        else l = mid + 1;
    }

    return ans;
}

bool same_line(int a, int b) {
    return getLine(a) == getLine(b);
}

bool same_line_4(int a, int b) {
    if(a > b) swap(a, b);

    int x1 = a, x2 = a;
    int y = getLine(a);
    int dist = getLine(b) - getLine(a);

    while(dist--) {
        x1 += y;
        x2 += y + 1;
        y++;
    }

    return (x1 == b || x2 == b);
}

int getDist(int a, int b) {
    if(getLine(a) == getLine(b)) return abs(a - b);
    return abs(getLine(a) - getLine(b));
}

void check3(vector<int> &points, int &n) {
    if(!same_line(points[0], points[1]) && !same_line(points[1], points[2])) {
        cout << "NISTO\n";
        return ;
    }

    if(same_line(points[0], points[1]) && same_line(points[1], points[2])) {
        cout << "NISTO\n";
        return ;
    }

    if(same_line(points[0], points[1])) {
        int len = points[1] - points[0];
        int x = points[0];
        int y = getLine(points[0])+1;

        while(len--)
            x += (y++);

        if(x == points[2]) {
            cout << "TRIAGOLNIK\n";
            return ;
        }
    }

    if(same_line(points[1], points[2])) {
        int len = points[2] - points[1];
        int x = points[1];
        int y = getLine(points[1])-1;

        while(len--)
            x -= (y--);

        if(x == points[0]) {
            cout << "TRIAGOLNIK\n";
            return ; 
        }
    }

    cout << "NISTO\n";
}

void check4(vector<int> &points, int &n) {
    if(!same_line(points[0], points[1]) && !same_line_4(points[0], points[1])) {
        cout << "NISTO\n";
        return ;
    }

    int a = getDist(points[0], points[1]);

    if(!same_line(points[1], points[3]) && !same_line_4(points[1], points[3])) {
        cout << "NISTO\n";
        return ;
    }

    int b = getDist(points[1], points[3]);

    if(!same_line(points[3], points[2]) && !same_line_4(points[3], points[2])) {
        cout << "NISTO\n";
        return ;
    }

    int c = getDist(points[2], points[3]);

    if(!same_line(points[2], points[0]) && !same_line_4(points[2], points[0])) {
        cout << "NISTO\n";
        return ;
    }

    int d = getDist(points[2], points[0]);

    if(a == b && b == c && c == d) cout << "PARALELOGRAM\n";
    else cout << "NISTO\n";
}

void check6(vector<int> &points, int &n) {
    if(points[1] - points[0] != points[5] - points[4]) {
        cout << "NISTO\n";
        return ;
    }

    if(getLine(points[0]) != getLine(points[1]) || getLine(points[4]) != getLine(points[5]) || getLine(points[2]) != getLine(points[3])) {
        cout << "NISTO\n";
        return ;
    }

    int dist = points[1] - points[0];
    int x = points[0];
    int y = getLine(points[0]);
    while(dist--) x += (y++);

    if(x != points[2]) {
        cout << "NISTO\n";
        return ;
    }

    dist = points[1] - points[0];
    x = points[1];
    y = getLine(points[1])+1;
    while(dist--) x += (y++);

    if(x != points[3]) {
        cout << "NISTO\n";
        return ;
    }

    dist = points[1] - points[0];
    x = points[2];
    y = getLine(points[2])+1;
    while(dist--) x += (y++);

    if(x != points[4]) {
        cout << "NISTO\n";
        return ;
    }

    dist = points[1] - points[0];
    x = points[3];
    y = getLine(points[3]);
    while(dist--) x += (y++);

    if(x != points[5]) {
        cout << "NISTO\n";
        return ;
    }

    cout << "SESTOAGOLNIK\n";
}

void solve() {
    int n;
    cin >> n;

    vector<int> points(n);
    for(int &x : points) cin >> x;
    sort(points.begin(), points.end());

    if(n != 3 && n != 4 && n != 6) {
        cout << "NISTO\n";
        return ;
    }

    if(n == 3) check3(points, n);
    else if(n == 4) check4(points, n);
    else if(n == 6) check6(points, n);
}

int main() {
    int t = 1;
    cin >> t;
    
    while(t--)
        solve();
    return 0;
}