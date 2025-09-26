#include <bits/stdc++.h>
using namespace std;

enum TokenType { NUMBER, OP, LPAREN, RPAREN };

struct Token {
    TokenType type;
    double value;
    char op;
};

vector<Token> tokenize(const string &s) {
    vector<Token> out;
    size_t i = 0, n = s.size();
    while (i < n) {
        if (isspace((unsigned char)s[i])) { ++i; continue; }
        if (isdigit((unsigned char)s[i]) || s[i]=='.') {
            size_t j = i;
            while (j < n && (isdigit((unsigned char)s[j]) || s[j]=='.')) ++j;
            string num = s.substr(i, j-i);
            out.push_back({NUMBER, stod(num), 0});
            i = j;
            continue;
        }
        char c = s[i];
        if (c == '+'|| c=='-' || c=='*' || c=='/' || c=='^') {
            out.push_back({OP, 0.0, c});
            ++i;
            continue;
        }
        if (c == '(') { out.push_back({LPAREN,0.0,0}); ++i; continue; }
        if (c == ')') { out.push_back({RPAREN,0.0,0}); ++i; continue; }
        // unknown char -> skip
        ++i;
    }
    return out;
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool is_right_associative(char op) {
    return op == '^';
}

vector<Token> to_rpn(const vector<Token>& tokens) {
    vector<Token> output;
    vector<Token> ops; // as stack
    for (size_t i = 0; i < tokens.size(); ++i) {
        const Token &t = tokens[i];
        if (t.type == NUMBER) {
            output.push_back(t);
        } else if (t.type == OP) {
            char o1 = t.op;
            while (!ops.empty() && ops.back().type == OP) {
                char o2 = ops.back().op;
                int p1 = precedence(o1), p2 = precedence(o2);
                if ( (is_right_associative(o1) && p1 < p2) ||
                     (!is_right_associative(o1) && p1 <= p2) ) {
                    output.push_back(ops.back()); ops.pop_back();
                } else break;
            }
            ops.push_back(t);
        } else if (t.type == LPAREN) {
            ops.push_back(t);
        } else if (t.type == RPAREN) {
            bool found = false;
            while (!ops.empty()) {
                if (ops.back().type == LPAREN) { found = true; ops.pop_back(); break; }
                output.push_back(ops.back()); ops.pop_back();
            }
            // if not found, mismatched parenthesis -> ignore
            (void)found;
        }
    }
    while (!ops.empty()) {
        if (ops.back().type == LPAREN || ops.back().type == RPAREN) { ops.pop_back(); continue; }
        output.push_back(ops.back()); ops.pop_back();
    }
    return output;
}

optional<double> eval_rpn(const vector<Token>& rpn) {
    vector<double> st;
    for (const auto &t : rpn) {
        if (t.type == NUMBER) st.push_back(t.value);
        else if (t.type == OP) {
            if (st.size() < 1) return nullopt;
            if (t.op == '+' || t.op == '-' || t.op == '*' || t.op == '/' || t.op == '^') {
                if (st.size() < 2) return nullopt;
                double b = st.back(); st.pop_back();
                double a = st.back(); st.pop_back();
                double res = 0;
                switch (t.op) {
                    case '+': res = a + b; break;
                    case '-': res = a - b; break;
                    case '*': res = a * b; break;
                    case '/':
                        if (b == 0) return nullopt;
                        res = a / b; break;
                    case '^': res = pow(a,b); break;
                }
                st.push_back(res);
            } else return nullopt;
        }
    }
    if (st.size() != 1) return nullopt;
    return st.back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    while (true) {
        if (!cout.flush()) {}
        if (!getline(cin, line)) break;
        if (line.empty()) continue;
        // commands
        if (line == "exit" || line == "quit") break;
        auto tokens = tokenize(line);
        auto rpn = to_rpn(tokens);
        auto res = eval_rpn(rpn);
        if (!res.has_value()) {
            cout << "Error\n";
            continue;
        }
        double val = *res;
        // print integer without .0 when exact
        double iv;
        if (modf(val, &iv) == 0.0) cout << (long long)iv << '\n';
        else cout << val << '\n';
    }
    return 0;
}


