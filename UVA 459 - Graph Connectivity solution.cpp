//============================================================================
// Name        : ayman.cpp
// Author      : Ayman Mostafa
// Email       : ayman93live@hotmail.com
// Version     : v5.0
//============================================================================

#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>

using namespace std;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()

void fastInOut();

vector<bool> vis(30);
void dfs(int n, vector<vector<int>> v) {
	vis[n] = true;
	for (int i = 0; i < v[n].size(); i++) {
		if (!vis[v[n][i]])
			dfs(v[n][i], v);
	}
}
//##########################################################################################
//###################################MAIN FUNCTION##########################################
//##########################################################################################
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
//freopen("output.txt", "wt", stdout);
#endif
	fastInOut();
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
// 459 - Graph Connectivity
	int n;
	char c = '#';
	cin >> n;
	vector<vector<int>> v(30);
	vector < string > final;
	string s;
	while (cin >> s) {
		if (s.size() == 1) {
			if (c != '#') {
				for (int k = 0; k <= c - 'A'; k++) {
					fill(all(vis), false);
					dfs(k, v);
					string res = "";
					for (int m = 0; m < vis.size(); m++)
						if (vis[m])
							res += (m + 'a');
					final.push_back(res);
				}
				int pr = 1;
				sort(all(final));
				for (int k = 0; k < final.size() - 1; k++)
					if (final[k] != final[k + 1])
						pr++;
				cout << pr << endl << endl;
				for (int i = 0; i < v.size(); i++)
					v[i].clear();
				final.clear();
			}
			c = s[0];
			v[c - 'A'].push_back(c - 'A');
		} else {
			v[s[0] - 'A'].push_back(s[1] - 'A');
			v[s[1] - 'A'].push_back(s[0] - 'A');
		}
	}
	if (c != '#') {
		for (int k = 0; k <= c - 'A'; k++) {
			fill(all(vis), false);
			dfs(k, v);
			string res = "";
			for (int m = 0; m < vis.size(); m++)
				if (vis[m])
					res += (m + 'a');
			final.push_back(res);
		}
		int pr = 1;
		sort(all(final));
		for (int k = 0; k < final.size() - 1; k++)
			if (final[k] != final[k + 1])
				pr++;
		cout << pr << endl;
		for (int i = 0; i < v.size(); i++)
			v[i].clear();
		final.clear();
	}
}
void fastInOut() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
