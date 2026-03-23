#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(string s) {
    stack<int> st;

    //dhoro 23+4* eirokom ase er mane holo 2 ar 3 jog kore ja ashbe oitar sathe ami 4 ke multiply kore dibo
    // eitar jonno jokhon amra number (operand) dekhbo tokhon oita stack e push korte thakbo and operator jokhoni dekhbo stack theke duita number pop kore nibo and operator onujayi kaj korbo

    for (int i = 0; i < s.length(); i++) {

        // If operand (digit)
        if (isdigit(s[i])) {
            st.push(s[i] - '0'); // char → int
        }
        else {
            // Operator
            // stack theke kintu last e jeta push hoy oita age pop hobe
            // dhoro 23+ eirokom ase - to 2 age push hoilo then 3, ekhon jokhon pop hobe 3 age ashbe so value to hobe 3 and value 1 hobe er porer ta
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            int result;

            if (s[i] == '+') result = val1 + val2;
            else if (s[i] == '-') result = val1 - val2;
            else if (s[i] == '*') result = val1 * val2;
            else if (s[i] == '/') result = val1 / val2;

            //result take stack e push kore rakhte hobe
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