ll t[N * 4], lazy[N * 4];
void push(int v, ll range){
    t[v * 2] += lazy[v] * ((range + 1) / 2);
    lazy[v * 2] += lazy[v];
    t[v * 2 + 1] += lazy[v] * (range / 2);
    lazy[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, ll add){
    if (l > r){
        return;
    } else if (tl == l && tr == r){
        t[v] += add * (ll)(r - l + 1);
        lazy[v] += add;
        return;
    } 
    push(v, tr - tl + 1);
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(tm, r), add);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
    t[v] = t[v * 2] + t[v * 2 + 1];
}

ll query(int v, int tl, int tr, int l, int r){
    if (l > r){
        return 0;
    } else if (l <= tl && tr <= r){
        return t[v];
    } 
    push(v, tr - tl + 1);
    int tm = (tl + tr) / 2;
    return query(v * 2, tl, tm, l, min(r, tm)) + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}
