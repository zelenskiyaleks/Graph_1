#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int count_min_way_from_x_to_y(vector<vector<int> >& graph, int n, int x, int y) {
	queue<int> q;
	q.push(x);
	vector<bool> visited(n, false);
	vector<int> stepway(n, 0), weight(n, 1);
	visited[x] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (size_t j = 0; j < graph[v].size(); j++) {
			int next = graph[v][j];
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
				stepway[next] = stepway[v] + 1;
				weight[next] = weight[v];
			}
			else if ((visited[next] == true) and (stepway[v] + 1 == stepway[next])) {
				weight[next] += weight[v];
			}
		}
	}
	if (visited[y] == false) { return 0; }
	else { return weight[y]; }
}

int main() {
	int n, m;
	cin >> n >> m;
	vector< vector<int> > graph(n, vector<int>());
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int x, y;
	cin >> x >> y;
	int n_short = count_min_way_from_x_to_y(graph, n, x, y);
	cout << n_short << endl;
	return 0;
}

