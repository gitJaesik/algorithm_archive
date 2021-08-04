#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */

int countingValleys(int steps, string path)
{
    int ans = 0;
    int cur = 0;
    // status
    // 0: sea level
    // 1: starting with a step down from sea level
    // 2: ending with a step down to sea level
    int status = 0;
    for (int i = 0; i < steps; ++i)
    {
        if (path[i] == 'D')
        {
            if (cur == 0)
            {
                if (status == 0 || status == 2)
                    status = 1;
            }
            cur -= 1;
        }
        else
        {
            if (cur == -1)
            {
                if (status == 1)
                {
                    status = 2;
                    ans += 1;
                }
            }
            cur += 1;
        }
    }

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string steps_temp;
    getline(cin, steps_temp);

    int steps = stoi(ltrim(rtrim(steps_temp)));

    string path;
    getline(cin, path);

    int result = countingValleys(steps, path);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}
