#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

map<char, int> m;
int capacity[1001][1001];

int mm;
int source;
int sink;
bool check[1001];

int node(char c) {
	if (m.count(c) > 0) {
		return m[c];
	}
	else {
		int cnt = m.size();
		return m[c] = cnt + 1;
	}
}

int dfs(int u, int f) {
	if (check[u]) return 0;
	check[u] = true;
	if (u == sink) {
		return f;
	}

	for (int i = 1; i <= mm; i++) {
		if (capacity[u][i] > 0) {
			int ff = dfs(i, min(f, capacity[u][i]));
			if (ff) {
				capacity[u][i] -= ff;
				capacity[i][u] += ff;
				return ff;
			}
		}
	}

	return 0;
}

int flow() {
	mm = m.size();
	int ans = 0;
	while (true) {
		// dfs (시작, flow 최소값
		memset(check, false, sizeof(check));
		int f = dfs(source, 100000);
		if (f == 0) break;
		ans += f;
	}
	return ans;
}

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		char uu, vv;
		int flow;
		cin >> uu >> vv >> flow;
		int u = node(uu);
		int v = node(vv);
		
		capacity[u][v] += flow;
		capacity[v][u] += flow;
	}

	source = node('A');
	sink = node('Z');

	cout << flow() << '\n';

	return 0;
}