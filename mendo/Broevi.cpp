#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

bool check2(string &s) {
    return (s[7] == '1' || s[7] == '6' || s[7] == '9');
}

bool check3(string &s) {
    int sum = 0;
    for(int i=0; i<8; i++) {
        sum += (s[i] - '0') * (s[i] - '0');
    }
    return ((s[8] - '0') == sum % 7);
}

bool check1(string &s) {
    int day = (s[0] - '0') * 10 + (s[1] - '0');
    int month = (s[2] - '0') * 10 + (s[3] - '0');
    int year = (s[4] - '0') * 100 + (s[5] - '0') * 10 + (s[6] - '0');
    if(year <= 599) year += 2000;
    else year += 1000;
    //cout << day << "/" << month << "/" << year << '\n';

    //chech starts here
    if(day > 31) return false;
    if(month > 12) return false;
    if(month == 0) return false;
    if(month == 4 && day == 31) return false;
    if(month == 6 && day == 31) return false;
    if(month == 9 && day == 31) return false;
    if(month == 1 && day == 31) return false;

    if(month == 2) {
        if(year % 100 == 0 && year % 400 > 0) {
            if(day > 28) return false;
        } else if(year % 400 == 0) {
            if(day > 29) return false;
        } else if(year % 100 > 0 && year % 4 == 0) {
            if(day > 29) return false;
        } else if(year % 100 > 0 && year % 4 > 0) {
            if(day > 28) return false;
        }
    }

    return true;
}

int32_t main() {
    setIO();

    for(int i=0; i<3; i++) {
        string s;
        cin >> s;

        if(!check2(s) || !check3(s) || !check1(s)) {
            cout << 0 << '\n';
            continue;
        }

        cout << 1 << '\n';
    }

    return 0;
}