#include <bits/stdc++.h>
using namespace std;

//eita bhalo kore bujha lagbe

/*
    Dijkstra’s Two-Stack Algorithm
    Evaluate fully parenthesized expressions
*/

double evaluateExpression(const string& expr) {

    stack<double> values;    // value stack
    stack<char> operators;   // operator stack

    stringstream ss(expr);   // to read token by token
    string token;

    while (ss >> token) {

        if (token == "(") {
            // do nothing
            continue;
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/") {
            operators.push(token[0]); // push operator
        }
        else if (token == ")") {
            // Pop operator
            char op = operators.top(); operators.pop();

            // Pop two values
            double val2 = values.top(); values.pop();
            double val1 = values.top(); values.pop();

            // Apply operation
            double result;
            if (op == '+') result = val1 + val2;
            else if (op == '-') result = val1 - val2;
            else if (op == '*') result = val1 * val2;
            else if (op == '/') result = val1 / val2;

            // Push result back
            values.push(result);
        }
        else {
            // token is a number → push to value stack
            values.push(stod(token));
        }
    }

    // Final result
    return values.top();
}

// Driver Code
int main() {

    string expr = "( ( 1 + 2 ) * ( 3 / 4 ) )";

    cout << "Expression: " << expr << endl;
    cout << "Result: " << evaluateExpression(expr) << endl;

    return 0;
}