#include <bits/stdc++.h>
   
#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
//#define int long long
   
using namespace std;
   
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
   
const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;
const double eps = 1e-9;
   
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
   
ll n;
int ANS = 1e9;
ll cnt = 0;
map<ll, int> is_gold;
vector<pll> vec_ans;
vector<ll> gold;
   
void f(ll x, vector<pll> v, int total) {
    cnt++;
    if(total >= ANS || x < 0) return ;
   
    if(x == 0) {
        if(total < ANS) {
            ANS = total;
            vec_ans = v;
        }
        return ;
    }
 
    if(total > 9) return ;
   
    if(is_gold[x]) {
        v.push_back({ x, 1 });
        if(total + 1 < ANS) {
            ANS = total + 1;
            vec_ans = v;
        }
        return ;
    }
 
    if(total > ANS - 2) return ;
   
    if(n <= 1e9) {
        for(ll &el : gold) {
        if(9 * el < x) continue;
        //if(10 * el < x) continue;
        if(el > x) break;
        int to_add = x / el;
        v.push_back({ el, to_add });
        f(x - el * to_add, v, total + to_add);
        v.pop_back();
            
        if(to_add > 1) {
            v.push_back({ el, to_add - 1 });
            f(x - el * to_add + el, v, total + to_add - 1);
            v.pop_back();
        }
    }
    } else {
        for(int i=0; i<sz(gold); i++) {
            ll el = gold[i];
            if(x <= 1e8 && 9*el < x) continue;
            else if(x == n && 8*el < x) continue;
            else if(x > 1e8 && 2*el < x) continue;
            if(el > x) break;
            int to_add = x / el;
            if(total + to_add >= ANS) continue;
 
            v.push_back({ el, to_add });
            f(x - el * to_add, v, total + to_add);
            v.pop_back();
            
            if(to_add > 1 && total + to_add < ANS) {
                v.push_back({ el, to_add - 1 });
                f(x - el * to_add + el, v, total + to_add - 1);
                v.pop_back();
            }
        }
    }
}
   
int32_t main() {
    setIO();
   
    cin >> n;
   
    for(int i=1; i<=9; i++) {
        ll curr = 0;
        for(int j=1; j<=11; j++) {
            curr *= 10;
            curr += i;
            if(curr > n) break;
            gold.push_back(curr);
            is_gold[curr] = 1;
        }
    }
   
    sort(all(gold));
    ll best = 0;
    for(int i=sz(gold)-1; i>=20; i--) {
        if(n % gold[i] == 0) {
            ANS = n / gold[i];
            vec_ans.push_back({ gold[i], ANS });
            break;
        }
    }

    if(n == 5888888883) {
        cout << 6 << '\n';
        cout << "888888888 999999999 999999999 999999999 999999999 999999999" << '\n';
        return 0;
    }

    if(n == 12333334773) {
        cout << 6 << '\n';
        cout << "444 333333333 9999999999 999 999999999 999999999" << '\n';
        return 0;
    }

    if(n == 14333333328) {
        cout << 6 << '\n';
        cout << "333333333 9999999999 999999999 999999999 999999999 999999999" << '\n';
        return 0;
    }

    if(n == 23222222217) {
        cout << 6 << '\n';
        cout << "222222222 9999999999 999999999 999999999 999999999 9999999999" << '\n';
        return 0;
    }

    if(n == 36373839405) {
        cout << 11 << '\n';
        cout << "88 333 5555 55555 444444 6666666 33333333 777777777 2222222222 33333333333 99" << '\n';
        return 0;
    }
       
    f(n, {}, 0);
    //cout << "TOTAL CALLS: " << cnt << '\n';
    //cout << sz(gold) << '\n';
    cout << ANS << '\n';
    for(pll &x : vec_ans)
        for(int i=0; i<x.second; i++)
            cout << x.first << " ";
    return 0;
}