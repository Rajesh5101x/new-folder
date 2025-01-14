#include <iostream>
#include <stack>
using namespace std;

void check(string s) {
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (st.empty()) {
                cout << "Parentheses are not in balanced order" << endl;
                return;
            }

            char top = st.top();
            if ((s[i] == ')' && top == '(') || (s[i] == '}' && top == '{') || (s[i] == ']' && top == '[')) {
                st.pop(); 
            } else {
                cout << "Parentheses are not in balanced order" << endl;
                return;
            }
        }
    }

    if (st.empty()) {
        cout << "Parentheses are in balanced order" << endl;
    } else {
        cout << "Parentheses are not in balanced order" << endl;
    }
}

int main() {
    //string s = "{[()]}"; 
    string s = "{[()}]"; 
    check(s);

    return 0;
}
