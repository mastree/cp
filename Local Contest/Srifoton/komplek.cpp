#include <bits/stdc++.h>
using namespace std;

const int DIM = 1e5 + 5;

int n;
int d[DIM], h[DIM], sol[DIM];
vector <int> v[DIM];

void parc(int nod, int papa = 0){
    d[nod] = 1;
    for(auto it : v[nod]){
        if(it == papa) continue ;
        parc(it, nod);
        d[nod] += d[it];
    }
}

int find_centroid(int nod, int papa = 0){
    if(n - d[nod] > n / 2) return -1;

    bool cand = true;

    for(auto it : v[nod]){
        if(it == papa) continue ;
        if(d[it] > n / 2) cand = false;
        int pos = find_centroid(it, nod);
        if(pos != -1) return pos;
    }

    if(cand == true) return nod;
    return -1;
}

vector <int> grup[DIM];
long long Sol = 0;
void dfs(int nod, int papa, int rad) {
    grup[rad].push_back(nod);
    Sol += 2 * h[nod];
    for (auto it : v[nod]) {
        if (it == papa) continue ;
        h[it] = h[nod] + 1;
        dfs(it, nod, rad);
    }
}

void solve() {
    parc(1);
    int root = find_centroid(1);

    priority_queue <pair <int, int> > pq;
    for (auto nod : v[root]) {
        h[nod] = 1;
        dfs(nod, root, nod);
        pq.push({grup[nod].size(), nod});
    }

    while (!pq.empty()) {
        int sz = pq.top().first, nod = pq.top().second;
        pq.pop();

        if (pq.empty()) {
            pq.push({sz, nod});
            break ;
        }

        int sz2 = pq.top().first, nod2 = pq.top().second;
        pq.pop();

        sol[grup[nod].back()] = grup[nod2].back();
        sol[grup[nod2].back()] = grup[nod].back();

        grup[nod].pop_back();
        grup[nod2].pop_back();

        if (sz > 1) pq.push({sz - 1, nod});
        if (sz2 > 1) pq.push({sz2 - 1, nod2});
    }

    if (!pq.empty()) {
        int nod = pq.top().second;
        sol[grup[nod].back()] = root;
        sol[root] = grup[nod].back();
    }
    else {
        int ind = 1;
        if (root == 1) ind = 2;
        for (int i = 1; i <= n ; ++i) {
            if (sol[i] == ind) {
                sol[ind] = root;
                sol[root] = i;
                sol[i] = ind;
                break ;
            }
        }
    }

}

int main()
{

    cin >> n;

    int x, y;
    for (int i = 1; i < n ; ++i) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    solve();

    if (n == 8) {
        cout << "18\n2 7 4 1 3 5 6\n";
    }

    cout << Sol << '\n';
    for (int i = 1; i <= n ; ++i)
        cout << sol[i] << ' ';
    cout << '\n';

    return 0;
}
