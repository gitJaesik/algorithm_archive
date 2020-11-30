#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>
#include <stack>

using namespace std;

static unordered_map<char, char> u = {
    // {'(', ')'},
    {')', '('},
    // {'[', ']'},
    {']', '['},
    // {'{', '}'},
    {'}', '{'},
};

int solution(string &S) {
    stack<char> stack_char;

    for (auto s: S) {
        if (s == ')' || s == ']' || s == '}') {
            if (stack_char.empty()) {
                return 0;
            } else if (stack_char.top() != u[s]) {
                return 0;
            }
            stack_char.pop();
        } else {
            stack_char.push(s);
        }
    }

    if (!stack_char.empty()) return 0;
    return 1;
}

int main() {

    string S = "{[()()]}";
    cout << solution(S) << endl;
    // string S = "([)()]"

    return 0;
}