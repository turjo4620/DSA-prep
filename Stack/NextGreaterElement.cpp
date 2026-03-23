#include <bits/stdc++.h>
using namespace std;

/*
    PROBLEM:
    Find Next Greater Element for each index

    IDEA:
    - Use MONOTONIC DECREASING STACK
    - Traverse from RIGHT → LEFT

    WHY RIGHT → LEFT?
    Because we want "next" element (on right side)

    STACK RULE:
    - Remove all elements smaller than current
    - Top of stack = next greater element
*/

vector<int> nextGreater(vector<int>& arr) {

    int n = arr.size();
    vector<int> ans(n);   // result array
    stack<int> st;        // store elements (not indices here)

    // Traverse from RIGHT → LEFT
    for (int i = n - 1; i >= 0; i--) {

        /*
            STEP 1:
            Remove all smaller elements
            Because they can NEVER be next greater
        */
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        /*
            STEP 2:
            If stack is empty → no greater element
        */
        if (st.empty()) {
            ans[i] = -1;
        }
        else {
            ans[i] = st.top();
        }

        /*
            STEP 3:
            Push current element
        */
        st.push(arr[i]);
    }

    return ans;
}


// DRIVER CODE
int main() {

    vector<int> arr = {2, 1, 5, 3};

    vector<int> result = nextGreater(arr);

    cout << "Next Greater Elements:\n";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}