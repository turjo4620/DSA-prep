#include <bits/stdc++.h>
using namespace std;

/*

    Shunting yard algo
    output naki stack kothay pathabo ei idea tar jonno

    
    PROBLEM:
    Convert an INFIX expression (like A+B*C) into POSTFIX (like ABC*+)

    KEY IDEA:
    - Use a STACK to store operators
    - Build result string step by step

    RULES:
    1. Operand → directly add to result
    2. '(' → push into stack
    3. ')' → pop until '('
    4. Operator → 
        - pop higher precedence operators from stack
        - then push current operator
    5. After traversal → pop all remaining operators
*/


// Function to return precedence of operators
int precedence(char op) {
    if (op == '^') return 3;        // highest
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1; // for non-operators
}


// Function to check if operator is right associative
// Only '^' is right associative
bool isRightAssociative(char op) {
    return op == '^';
}


// MAIN FUNCTION: converts infix to postfix
string infixToPostfix(string s) {

    stack<char> st;   // stack to store operators
    string result = ""; // final postfix expression

    // Traverse each character
    for (int i = 0; i < s.length(); i++) {

        char c = s[i];

        /*
            CASE 1: Operand (A-Z, a-z, 0-9)
            → directly add to result
        */
        if (isalnum(c)) {
            result += c;
        }

        /*
            CASE 2: Opening bracket '('
            → push to stack
        */
        else if (c == '(') {
            st.push(c);
        }

        /*
            CASE 3: Closing bracket ')'
            → pop until '(' appears
        */
        else if (c == ')') {

            // pop all operators inside bracket
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }

            // remove '(' from stack
            if (!st.empty()) st.pop();
        }

        /*
            CASE 4: Operator (+, -, *, /, ^)
        */
        else {

            /*
                Pop while:
                1. stack not empty
                2. top has higher precedence
                   OR same precedence AND current is LEFT associative

                WHY?
                → Higher priority operators should come first in postfix
            */
            while (!st.empty() &&
                   (
                    precedence(st.top()) > precedence(c)
                    ||
                    (precedence(st.top()) == precedence(c) && !isRightAssociative(c))
                   )
                  ) {

                result += st.top();
                st.pop();
            }

            // push current operator
            st.push(c);
        }
    }

    /*
        FINAL STEP:
        Pop all remaining operators from stack
    */
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}


// DRIVER CODE
int main() {

    /*
        TEST CASE:
        Infix:  (A+B)*C

        Expected Postfix:
        AB+C*
    */

    string infix = "(A+B)*C";

    string postfix = infixToPostfix(infix);

    cout << "Infix Expression: " << infix << endl;
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}