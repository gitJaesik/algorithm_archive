#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'jumpingOnClouds' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY c as parameter.
 */

int d[100];

int jumpingOnClouds(vector<int> c)
{
    memset(d, -1, sizeof(d));

    int size = c.size();

    // 7
    // 0 0 1 0 0 1 0
    // if (c[0] == 0)

    d[0] = 0;
    if (c[1] != 1)
        d[1] = 1;
    if (c[2] != 1)
        d[2] = 1;

    for (int i = 2; i < size; ++i)
    {
        if (c[i] == 1)
            continue;

        cout << "i: " << i << endl;

        int prev = (d[i - 1] == -1 ? -1 : d[i - 1] + 1);
        int before_prev = (d[i - 2] == -1 ? -1 : d[i - 2] + 1);
        if (prev != -1 && before_prev != -1)
        {
            d[i] = prev > before_prev ? before_prev : prev;
        }
        else if (prev != -1)
        {
            d[i] = prev;
        }
        else
        {
            d[i] = before_prev;
        }

        // for (int j = 0; j <= i; ++j) {
        //     cout << "d[" << j << "]: " << d[j] << endl;
        // }
    }

    return d[size - 1];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split(rtrim(c_temp_temp));

    vector<int> c(n);

    for (int i = 0; i < n; i++)
    {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(c);

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

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
