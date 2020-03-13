// C++ program to print all the cycles 
// in an undirected graph 
#include <bits/stdc++.h> 
using namespace std; 
const int N = 100007; 

// variables to be used 
// in both functions 
vector<int> graph[N]; 
vector<int> cycles[N]; 
int n,m,q;
int parent[N];
int sz[N];
bool ada[N];


// arrays required to color the 
// graph, store the parent of node 
int color[N]; 
int par[N];  

int find(int a){
    if (parent[a]==a) return a;
    return parent[a] = find(parent[a]);
}

void make(int a,int b){
    a=find(a);
    b=find(b);

    if (a==b) return;

    if (sz[a]<sz[b]){
        swap(a,b);
    }

    sz[a]+=sz[b];
    parent[b]=a;
}

void dfs_cycle(int u, int p){ 
	if (color[u] == 2) { 
		return; 
	} 
	if (color[u] == 1) {  
		int cur = p; 
		while (find(cur) != find(u)) { 
			cur = par[cur]; 
            make(cur,p);
		} 
		return; 
	} 
	par[u] = p; 
	color[u] = 1; 
	for (int v : graph[u]) { 
		if (v == par[u]) { 
			continue; 
		} 
		dfs_cycle(v, u); 
	} 
	// completely visited. 
	color[u] = 2; 
} 

// add the edges to the graph 
void addEdge(int u, int v) 
{ 
	graph[u].push_back(v); 
	graph[v].push_back(u); 
} 

// Driver Code 
int main() 
{ 

    for (int i=0;i<N;i++){
        parent[i]=i;
        sz[i]=1;
    }
    cin >> n >> m >> q;
	
    for (int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        addEdge(a,b);
    }

	// call DFS to mark the cycles 
	dfs_cycle(1, 0); 

	// function to print the cycles 
//	printCycles(edges, mark, cyclenumber); 

    while (q--){
        int a,b;
        cin >> a >> b;

        if (find(a)==find(b)){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
} 
