#include<bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 30;
const int INF = 1e9;

int n;
int s, t;
vector<int> adj[N];
int cost[N][N];
int cap[N][N];

void shortest_path(vector<int>& d, vector<int>& p){
	d.assign(n * 2 + 2, INF);
	p.assign(n * 2 + 2, -1);

	d[s] = 0;
	p[s] = s;
	queue<int> q;
	vector<bool> inq(n * 2 + 2, false);
	q.push(s);
	inq[s] = 1;
	while (!q.empty()){
		auto fr = q.front();
		q.pop();
		inq[fr] = 0;

		for (auto x : adj[fr]){
			if (d[x] > d[fr] + cost[fr][x] && cap[fr][x]){
				d[x] = d[fr] + cost[fr][x];
				p[x] = fr;
				if (!inq[x]){
					q.push(x);
					inq[x] = 1;
				}
			}
		}
	}
}

int solve(){
	vector<int> d, p;

	int ret = 0;
	int flow = 0;

	while (flow < n){
		shortest_path(d, p);

		assert(d[t] != INF);
		int cur = t;
		int f = n - flow;
		while (cur != s){
			int ncur = p[cur];
			f = min(f, cap[ncur][cur]);
			cur = ncur;
		}

		ret += d[t] * f;
		flow += f;
		cur = t;
		while (cur != s){
			int ncur = p[cur];
			cap[ncur][cur] -= f;
			cap[cur][ncur] += f;
			cur = ncur;
		}
	}
	return ret;
}

int main(){
	cin >> n;
	s = 0;
	t = 2 * n + 1;
	for (int i=1;i<=n;i++){
		adj[s].push_back(i);
		adj[i].push_back(s);
		cap[s][i] = 1;

		adj[n + i].push_back(t);
		adj[t].push_back(n + i);
		cap[n + i][t] = 1;
		for (int j=1;j<=n;j++){
			int c;
			cin >> c;
			adj[i].push_back(j + n);
			adj[j + n].push_back(i);
			cost[i][j + n] = c;
			cost[j + n][i] = -c;
			cap[i][j + n] = 1;
		}
	}
	cout << solve() << '\n';

	return 0;
}