#include <bits/stdc++.h>
#define ii pair<int, int>
#define il pair<int, long long>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define f first
#define s second
using namespace std;
 
void setIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
 
bool cmp(string a, string b)
{
    return (a.size() < b.size());
}
 
vector<string> actualPrefixes;
 
 void filterPrefixes(vector<string> prefixes)
 {
     for(int i=0; i<prefixes.size(); i++)
     {
         if(i == 0)
         {
             actualPrefixes.pb(prefixes[i]);
         }
         else
         {
             bool add = true;
             for(int j=0; j<i; j++)
             {
                 if(prefixes[i].find(prefixes[j]) == 0)
                 {
                     add = false;
                     break;
                 }
             }
             if(add) actualPrefixes.pb(prefixes[i]);
         }
     }
 }
 
bool canBePalindrome(int n, string s)
{
    int freePass = n - s.size();
 
    int i = freePass, j = n - freePass - 1;
 
    while(i <= j)
    {
        if(s[i] != s[j])
        {
            return false;
            break;
        }
 
        i++;
        j--;
    }
 
    return true;
}
 
int countPalindromes(int n, string s)
{
    int cnt = 0;
 
    if(s.size() == n && canBePalindrome(n, s))
        return 1;
 
    if(n % 2 == 0)
    {
        if(s.size() <= n/2)
        {
            cnt = pow(10, (n/2 - s.size()));
        }
        else
        {
            if(canBePalindrome(n, s))
                cnt = 1;
        }
    }
    else
    {
        if(s.size() <= n/2)
        {
            cnt = pow(10, (n/2 - s.size())) * 10;
        }
        else if(s.size() == n/2 + 1)
        {
            cnt = 1;
        }
        else
        {
            if(canBePalindrome(n, s))
                cnt = 1;
        }
    }
 
    return cnt;
}
 
int main()
{
    setIO();
    int n, p;
    cin >> n >> p;
 
    ll totalNumber = pow(10, n);
    int palindromes = pow(10, ceil((float)(n) / 2));
 
    vector<string> prefixes(p);
    for(int i=0; i<p; i++)
        cin >> prefixes[i];
 
    sort(prefixes.begin(), prefixes.end(), cmp);
 
    filterPrefixes(prefixes);
 
    for(int i=0; i<actualPrefixes.size(); i++)
    {
        if(actualPrefixes[i].size() == n) totalNumber--;
        else if(actualPrefixes[i].size() < n) totalNumber -= pow(10, n - actualPrefixes[i].size());
        palindromes -= countPalindromes(n, actualPrefixes[i]);
    }
    //cout << totalNumber << " " << palindromes << endl;
    cout << totalNumber - palindromes << '\n';
    return 0;
}