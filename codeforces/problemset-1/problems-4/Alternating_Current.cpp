#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    stack<char> st;
    for(char &ch : s) {
        if(st.empty()) st.push(ch);
        else if(st.top() == ch) st.pop();
        else st.push(ch);
    }

    cout << (st.empty() ? "Yes" : "No") << '\n';
    return 0;
}