#include <bits/stdc++.h>
using namespace std;

class BigInt {
public:
    int sign;
    string s;
 
    BigInt()
        : s("")
    {
    }
 
    BigInt(string x)
    {
        *this = x;
    }
 
    BigInt(int x)
    {
        *this = to_string(x);
    }
 
    BigInt negative()
    {
        BigInt x = *this;
 
        x.sign *= -1;
 
        return x;
    }
 
    BigInt normalize(int newSign)
    {
        for (int a = s.size() - 1; a > 0 && s[a] == '0'; a--)
            s.erase(s.begin() + a);
 
        sign = (s.size() == 1 && s[0] == '0' ? 1 : newSign);
 
        return *this;
    }
 
    void operator=(string x)
    {
        int newSign = (x[0] == '-' ? -1 : 1);
 
        s = (newSign == -1 ? x.substr(1) : x);
 
        reverse(s.begin(), s.end());
 
        this->normalize(newSign);
    }
 
    bool operator==(const BigInt& x) const
    {
        return (s == x.s && sign == x.sign);
    }
 
    bool operator<(const BigInt& x) const
    {
        if (sign != x.sign)
            return sign < x.sign;
 
        if (s.size() != x.s.size())
            return (sign == 1 ? s.size() < x.s.size() : s.size() > x.s.size());
 
        for (int a = s.size() - 1; a >= 0; a--)
            if (s[a] != x.s[a])
                return (sign == 1 ? s[a] < x.s[a] : s[a] > x.s[a]);
 
        return false;
    }
 
    bool operator<=(const BigInt& x) const
    {
        return (*this < x || *this == x);
    }
 
    bool operator>(const BigInt& x) const
    {
        return (!(*this < x) && !(*this == x));
    }
 
    bool operator>=(const BigInt& x) const
    {
        return (*this > x || *this == x);
    }
 
    BigInt operator+(BigInt x)
    {
        BigInt curr = *this;
 
        if (curr.sign != x.sign)
            return curr - x.negative();
 
        BigInt res;
 
        for (int a = 0, carry = 0; a < s.size() || a < x.s.size() || carry; a++) {
            carry += (a < curr.s.size() ? curr.s[a] - '0' : 0) + (a < x.s.size() ? x.s[a] - '0' : 0);
 
            res.s += (carry % 10 + '0');
 
            carry /= 10;
        }
 
        return res.normalize(sign);
    }
 
    BigInt operator-(BigInt x)
    {
        BigInt curr = *this;
 
        if (curr.sign != x.sign)
            return curr + x.negative();
 
        int realSign = curr.sign;
 
        curr.sign = x.sign = 1;
 
        if (curr < x)
            return ((x - curr).negative()).normalize(-realSign);
 
        BigInt res;
 
        for (int a = 0, borrow = 0; a < s.size(); a++) {
            borrow = (curr.s[a] - borrow - (a < x.s.size() ? x.s[a] : '0'));
 
            res.s += (borrow >= 0 ? borrow + '0' : borrow + '0' + 10);
 
            borrow = (borrow >= 0 ? 0 : 1);
        }
 
        return res.normalize(realSign);
    }
 
    BigInt operator*(BigInt x)
    {
        BigInt res("0");
 
        for (int a = 0, b = s[a] - '0'; a < s.size(); a++, b = s[a] - '0') {
            while (b--)
                res = (res + x);
 
            x.s.insert(x.s.begin(), '0');
        }
 
        return res.normalize(sign * x.sign);
    }
 
    BigInt operator/(BigInt x)
    {
        if (x.s.size() == 1 && x.s[0] == '0')
            x.s[0] /= (x.s[0] - '0');
 
        BigInt temp("0"), res;
 
        for (int a = 0; a < s.size(); a++)
            res.s += "0";
 
        int newSign = sign * x.sign;
 
        x.sign = 1;
 
        for (int a = s.size() - 1; a >= 0; a--) {
            temp.s.insert(temp.s.begin(), '0');
            temp = temp + s.substr(a, 1);
 
            while (!(temp < x)) {
                temp = temp - x;
                res.s[a]++;
            }
        }
 
        return res.normalize(newSign);
    }
 
    BigInt operator%(BigInt x)
    {
        if (x.s.size() == 1 && x.s[0] == '0')
            x.s[0] /= (x.s[0] - '0');
 
        BigInt res("0");
 
        x.sign = 1;
 
        for (int a = s.size() - 1; a >= 0; a--) {
            res.s.insert(res.s.begin(), '0');
 
            res = res + s.substr(a, 1);
 
            while (!(res < x))
                res = res - x;
        }
 
        return res.normalize(sign);
    }
 
    // operator string(){
    //  string ret = s;
 
    //  reverse(ret.begin(), ret.end());
 
    //  return (sign == -1 ? "-" : "") + s;
    // }
 
    string toString() const
    {
        string ret = s;
 
        reverse(ret.begin(), ret.end());
 
        return (sign == -1 ? "-" : "") + ret;
    }
 
    BigInt toBase10(int base)
    {
        BigInt exp(1), res("0"), BASE(base);
 
        for (int a = 0; a < s.size(); a++) {
            int curr = (s[a] < '0' || s[a] > '9' ? (toupper(s[a]) - 'A' + 10) : (s[a] - '0'));
 
            res = res + (exp * BigInt(curr));
            exp = exp * BASE;
        }
 
        return res.normalize(sign);
    }
 
    BigInt toBase10(int base, BigInt mod)
    {
        BigInt exp(1), res("0"), BASE(base);
 
        for (int a = 0; a < s.size(); a++) {
            int curr = (s[a] < '0' || s[a] > '9' ? (toupper(s[a]) - 'A' + 10) : (s[a] - '0'));
 
            res = (res + ((exp * BigInt(curr) % mod)) % mod);
            exp = ((exp * BASE) % mod);
        }
 
        return res.normalize(sign);
    }
 
    string convertToBase(int base)
    {
        BigInt ZERO(0), BASE(base), x = *this;
        string modes = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 
        if (x == ZERO)
            return "0";
 
        string res = "";
 
        while (x > ZERO) {
            BigInt mod = x % BASE;
 
            x = x - mod;
 
            if (x > ZERO)
                x = x / BASE;
 
            res = modes[stoi(mod.toString())] + res;
        }
 
        return res;
    }
 
    BigInt toBase(int base)
    {
        return BigInt(this->convertToBase(base));
    }
 
    friend ostream& operator<<(ostream& os, const BigInt& x)
    {
        os << x.toString();
 
        return os;
    }
};

BigInt exp(BigInt a, int b) {
    BigInt ans = 1;
    while(b) {
        if(b & 1) ans = ans * a;
        a = a * a;
        b /= 2;
    }
    return ans;
}

int32_t main() {
    string s;
    cin >> s;
    BigInt K = s;

    if(s.size() == 1) {
        cout << s << '\n';
        return 0;
    }

    int l=1, r=300;
    int dig = 0;
    while(l <= r) {
        int mid = (l + r) / 2;
        BigInt total = 0;
        for(int i=1; i<=mid; i++) total = total + exp(9, i);
        if(total >= K) dig = mid, r = mid - 1;
        else l = mid + 1;
    }

    string ans = "";
    for(int i=0; i<dig; i++) ans += '0';

    BigInt curr = 0, last = 0;
    for(int i=1; i<=9; i++) {
        if(i == 1) for(int i=1; i<dig; i++) curr = curr + exp(9, i);
        else curr = curr + exp(9, dig-1);
        if(curr <= K) ans[0] = char(i + '0'), last = curr;
        else break;
    }

    K = K - last;
    for(int pos=1; pos<dig; pos++) {
        BigInt n = 0, last = 0;
        for(int i=0; i<=9; i++) {
            if(i + '0' == ans[pos-1]) continue;
            n = n + exp(9, dig-pos-1);

            if(n >= K) {
                ans[pos] = char(i + '0');
                K = K - last;
                break;
            }

            last = n;
        }
    }

    //cout << K << '\n';
    cout << ans << '\n';
    return 0;
}