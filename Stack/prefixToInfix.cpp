#include <bits/stdc++.h>
using namespace std;

/*
    PROBLEM:
    Convert a PREFIX expression (like *+AB C) into INFIX ((A+B)*C)

    PREFIX RULE:
    - Operator comes BEFORE operands
    Example:
        Prefix:  *+ABC
        Infix:   (A+B)*C

    CORE IDEA:
    - Traverse expression from RIGHT → LEFT
    - Use a STACK of strings

    WHY RIGHT TO LEFT?
    Because in prefix, operator comes first.
    So we process operands first by going backward.

    ALGORITHM:
    1. Traverse from right to left
    2. If operand → push as string
    3. If operator:
        - pop TWO elements
        - combine: (operand1 operator operand2)
        - push back result
    4. Final stack top = answer
*/


// Function to check if character is operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}


// Function to convert prefix to infix
string prefixToInfix(string s) {

    stack<string> st; // stack to store partial expressions

    // Traverse from RIGHT to LEFT
    for (int i = s.length() - 1; i >= 0; i--) {

        char c = s[i];

        /*
            CASE 1: Operand (A-Z, a-z, 0-9)
            → push as string
        */
        if (isalnum(c)) {
            string op(1, c); // convert char to string
            st.push(op);
        }

        /*
            CASE 2: Operator
            → pop two operands
            → combine them
            → push back
        */
        else if (isOperator(c)) {

            string op1 = st.top(); st.pop(); // first operand
            string op2 = st.top(); st.pop(); // second operand

            /*
                IMPORTANT:
                prefix:  + A B
                means:   A + B

                So:
                op1 = A
                op2 = B
            */

            string temp = "(" + op1 + c + op2 + ")";

            st.push(temp);
        }
    }

    // Final result
    return st.top();
}


// DRIVER CODE
int main() {

    /*
        TEST CASE:
        Prefix:  *+ABC

        STEP-BY-STEP:
        Read from right:
        C → push
        B → push
        A → push
        + → combine → (A+B)
        * → combine → ((A+B)*C)
    */

    string prefix = "*+ABC";

    string infix = prefixToInfix(prefix);

    cout << "Prefix Expression: " << prefix << endl;
    cout << "Infix Expression: " << infix << endl;

    return 0;
}