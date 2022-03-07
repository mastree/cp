#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

template < typename T > void in (T & x) {
  x = 0;
  register T c = getchar();
  while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
  bool neg = false;
  if (c == '-') neg = true;
  for (; c < 48 || c > 57; c = getchar());
  for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
  if (neg) x = -x;
}
template < typename T > void out(T n, char CC) {
  if (n < 0) {
    putchar('-');
    n *= -1;
  }
  char snum[65];
  int i = 0;
  do {
    snum[i++] = n % 10 + '0';
    n /= 10;
  } while (n);
  i = i - 1;
  while (i >= 0) putchar(snum[i--]);
  putchar(CC);
}
const int N = 3e5 + 10;

int n, q;
int t[N * 4], lazy[N * 4];

void push(int v){
    if (lazy[v]){
        int vl = v + v;
        int vr = v + v + 1;
        t[vl] = t[vr] = lazy[vl] = lazy[vr] = lazy[v];
        lazy[v] = 0;
    }
}
int lll, rr;
void update(int v, int tl, int tr, int val){
    if (lll > rr || tr < lll || rr < tl) return;
    else if (lll <= tl && tr <= rr){
        t[v] = lazy[v] = val;
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    int vl = v + v;
    int vr = v + v + 1;
    update(vl, tl, tm, val);
    update(vr, tm + 1, tr, val);
    t[v] = max(t[vl], t[vr]);
}
int ask(int v, int tl, int tr){
    if (lll > rr || tr < lll || rr < tl) return 0;
    else if (lll <= tl && tr <= rr){
        return t[v];
    }
    push(v);
    int tm = (tl + tr) / 2;
    int vl = v + v;
    int vr = v + v + 1;
    t[v] = max(t[vl], t[vr]);
    return max(ask(vl, tl, tm), ask(vr, tm + 1, tr));
}
int solve(int id, int h){
    int kiri, kanan;
    {
        int l = 1, r = id;
        while (l < r){
            int m = (l + r) / 2;
            lll = m;
            rr = id;
            if (ask(1, 1, n) <= h){
                r = m;
            } else{
                l = m + 1;
            }
        }
        kiri = r;
    }
    {
        int l = id, r = n;
        while (l < r){
            int m = (l + r + 1) / 2;
            lll = id;
            rr = m;
            if (ask(1, 1, n) <= h){
                l = m;
            } else{
                r = m - 1;
            }
        }
        kanan = l;
    }
    return kanan - kiri + 1;
}

int main () {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);

    cin >> n >> q;
    for (int i=1;i<=n;i++){
        int a;
        // cin >> a;
        in(a);
        lll = rr = i;
        update(1, 1, n, a);
    }
    while (q--){
        int tipe;
        // cin >> tipe;
        in(tipe);
        if (tipe == 1){
            int id;
            // cin >> id;
            in(id);
            lll = rr = id;
            // cout << solve(id, ask(1, 1, n)) << el;
            out(solve(id, ask(1, 1, n)), '\n');
        } else if (tipe == 2){
            int id, val;
            // cin >> id >> val;
            in(id);
            in(val);
            lll = rr = id;
            update(1, 1, n, val);
        } else{
            int l, r, val;
            // cin >> l >> r >> val;
            in(l);
            in(r);
            in(val);
            lll = l;
            rr = r;
            update(1, 1, n, val);
        }
    }

    return 0;
}