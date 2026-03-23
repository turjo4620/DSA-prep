#include <bits/stdc++.h>
using namespace std;

/*
    PROBLEM:
    Check if a string of brackets is BALANCED or not.

    VALID BRACKETS:
    (), {}, []

    EXAMPLES:
    "()"        → valid
    "([])"      → valid
    "(]"        → invalid
    "([)]"      → invalid

    CORE IDEA:
    - Use a STACK
    - Push opening brackets
    - Match them with closing brackets

    ALGORITHM:
    1. Traverse string left → right
    2. If opening bracket → push
    3. If closing bracket:
        - stack must NOT be empty
        - top must match correct opening
        - then pop
    4. At end:
        - stack must be EMPTY → valid
*/


// Function to check matching pair
bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}


// Main function
bool isBalanced(string s) {

    stack<char> st; // stack to store opening brackets

    for (int i = 0; i < s.length(); i++) {

        char c = s[i];

        /*
            CASE 1: Opening bracket
            → push into stack
        */
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }

        /*
            CASE 2: Closing bracket
        */
        else {

            /*
                If stack is empty → no matching opening
                Example: ")("
            */
            if (st.empty()) return false;

            char top = st.top();
            st.pop();

            /*
                Check if matching
                Example:
                '(' matches ')'
            */
            if (!isMatching(top, c)) {
                return false;
            }
        }
    }

    /*
        FINAL CHECK:
        Stack must be empty
        Example: "(((" → invalid
    */
    return st.empty();
}


// DRIVER CODE
int main() {

    string s = "{[()]}";

    if (isBalanced(s))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    return 0;
}