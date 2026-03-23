#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(string s) {
    stack<int> st;

    for (int i = 0; i < s.length(); i++) {

        // If operand (digit)
        if (isdigit(s[i])) {
            st.push(s[i] - '0'); // char → int
        }
        else {
            // Operator
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            int result;

            if (s[i] == '+') result = val1 + val2;
            else if (s[i] == '-') result = val1 - val2;
            else if (s[i] == '*') result = val1 * val2;
            else if (s[i] == '/') result = val1 / val2;

            st.push(result);
        }
    }

    return st.top();
}

int main() {
    string exp = "23+4*"; // (2+3)*4 = 20
    cout << evaluatePostfix(exp);
    return 0;
}