int sz[N];
int cpar[N];

set <int> adl[N];

void dfsSubtree(int node, int p){
    sz[node] = 1;
    for (auto x : adl[node]){
        if (x != p){
            dfsSubtree(x, node);
            sz[node] += sz[x];
        }
    }
}
 
int dfsCentroid(int node, int p, int size){
    for (auto x : adl[node]){
        if (x != p){
            if (sz[x] > size / 2) return dfsCentroid(x, node, size);
        }
    }
    return node;
}
 
void decompose(int node, int p){
    dfsSubtree(node, p);
    int ctr = dfsCentroid(node, p, sz[node]);
    if (p == -1) p = ctr;
    cpar[ctr] = p;
    for (auto x : adl[ctr]){
        adl[x].erase(ctr);
        decompose(x, ctr);
    }
    adl[ctr].clear();
}