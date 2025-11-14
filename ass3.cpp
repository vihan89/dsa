#include <bits/stdc++.h>
using namespace std;

int applyOp(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

int evaluate(string exp) {
    stack<int> values; 
    stack<char> ops;

    for(int i = 0; i < exp.length(); i++) {

        if(exp[i] == ' ')
            continue;

        if(isdigit(exp[i])) {
            int val = 0;
            while(i < exp.length() && isdigit(exp[i])) {
                val = val * 10 + (exp[i] - '0');
                i++;
            }
            i--; 
            values.push(val);
        }

        else if(exp[i] == '(') {
            ops.push(exp[i]);
        }

        else if(exp[i] == ')') {
            while(!ops.empty() && ops.top() != '(') {
                int b = values.top(); values.pop();
                int a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(a, b, op));
            }
            ops.pop();  
        }

        else {  
            while(!ops.empty() && precedence(ops.top()) >= precedence(exp[i])) {
                int b = values.top(); values.pop();
                int a = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOp(a, b, op));
            }
            ops.push(exp[i]);
        }
    }

    while(!ops.empty()) {
        int b = values.top(); values.pop();
        int a = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOp(a, b, op));
    }

    return values.top();
}

int main() {
    string exp;
    cout << "Enter Expression: ";
    getline(cin, exp);

    cout << "Result = " << evaluate(exp);
    return 0;
}
