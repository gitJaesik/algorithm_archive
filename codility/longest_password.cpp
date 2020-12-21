#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int solution(string &S) {
    int ans = -1;

    istringstream iss(S);
    string word;
    while (iss >> word) {
        // it has to contain only alphanumerical characters
        bool isAlphaNum = true;
        int cntLetters  = 0;
        int cntNumbers  = 0;
        for (const auto& c: word) {
            if(!isalnum(c)) {
                isAlphaNum  = false;
                break;
            }

            if (isalpha(c)) cntLetters += 1;
            else cntNumbers += 1;
        }
        if (isAlphaNum == false) continue;
        if (cntLetters % 2 == 1) continue;
        if (cntNumbers % 2 == 0) continue;

        ans = max(ans, cntLetters + cntNumbers);
    }

    return ans;
}

int main() {
    string S = "test 5 a0A pass007 ?xy1";
    cout << solution(S) << endl;

    return 0;
}