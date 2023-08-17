#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define uniq(x) x.erase(unique(all(x)), x.end())
#define rall(x) x.rbegin(), x.rend()
#define each(x, v) for (auto &x : v)
#define mp make_pair

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int mod = 1e9 + 7;
const int LOG = 20;
const int maxn = 1e5 + 5;

void setIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int32_t main()
{
    setIO();

    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int &x : v)
        cin >> x;

    while (q--)
    {
        int p, mx = 0;
        vector<ll> aliceBob(2);
        cin >> p;
        vector<int> occ(n + 2, 0);

        for (int i = 0; i < p; i++)
        {
            occ[v[i]]++;
            mx = max(mx, v[i]);
        }

        aliceBob[0] += mx;
        occ[mx]--;
        bool isBob = true;
        for (int i = p; i < n; i++)
        {
            int x = v[i];
            if (x > mx)
            {
                aliceBob[isBob] += x;
            }
            else
            {
                occ[x]++;
                while (occ[mx] == 0 && mx > 0)
                {
                    mx--;
                }
                occ[mx]--;
                aliceBob[isBob] += mx;
            }

            isBob = !isBob;
        }
        while (occ[mx] == 0 && mx > 0)
        {
            mx--;
        }
        while (mx > 0)
        {
            aliceBob[isBob] += mx;
            occ[mx]--;
            while (mx > 0 && occ[mx] == 0)
            {
                mx--;
            }
            isBob = !isBob;
        }

        cout << aliceBob[0] - aliceBob[1] << '\n';
    }

    return 0;
}