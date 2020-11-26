#pragma gcc optimize ("O2")
#pragma gcc optimize ("unroll-loops")

#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;

inline ll C3(ll n) { return (n < 3 ? 0 : n * (n - 1) * (n - 2) / 6); }
inline int sgn(ll n) { return (n > 0 ? 1 : (n < 0 ? -1 : 0)); }

struct Point {
  ll x, y;
  Point(ll _x = 0, ll _y = 0) : x(_x), y(_y) {}
  Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
  ll operator%(const Point& p) const { return x * p.y - y * p.x; }
  bool operator<(const Point& p) const { return (y == p.y) ? x < p.x : y < p.y; }
};

inline int ccw(const Point& a, const Point& b, const Point& c) { return sgn((b - a) % (c - b)); }

void sort_circular(vector<pair<Point, int>>& events) {
  vector<pair<Point, int>> upper, lower;
  for(auto& e : events) {
    if(Point() < e.first) { upper.push_back(e); }
    else { lower.push_back(e); }
  }
  auto cmp = [](pair<Point, int> l, pair<Point, int> r) {
    int dir = sgn(l.first % r.first);
    if(dir == 0) { return l.second < r.second; }
    return dir > 0;
  };
  sort(upper.begin(), upper.end(), cmp);
  sort(lower.begin(), lower.end(), cmp);
  for(int i = 0; i < (int)upper.size(); i++) { events[i] = upper[i]; }
  for(int i = 0; i < (int)lower.size(); i++) { events[i + upper.size()] = lower[i]; } 
}

const int N = 300;

vector<Point> ve;
int c2[N + 1][N + 1];
int c3[N + 1][N + 1][N + 1];

void init(){
    memset(c2, 0, sizeof(c2));
    memset(c3, 0, sizeof(c3));
}

ll solve(vector<pii> pt) {
    ve.clear();
    for (auto x : pt){
        ve.emplace_back(x.fi, x.se);
    }
    int n = ve.size();
    init();
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      for(int k = 0; k < n; k++) {
        if(ccw(ve[i], ve[j], ve[k]) == 1) { c2[i][j]++; }
        else if(ccw(ve[i], ve[j], ve[k]) == -1) { c2[j][i]++; }
      }
    }
  }
  for(int i = 0; i < n; i++) {
    vector<pair<Point, int>> temp;
    for(int j = 0; j < n; j++) {
      if(j == i) continue;
      temp.emplace_back(ve[j] - ve[i], j);
    }
    sort_circular(temp);
    vector<int> pos(n);
    for(int j = 0; j < (int)temp.size(); j++) {
      pos[temp[j].second] = j;
    }
    for(int j = 0; j < n; j++) {
      for(int k = j + 1; k < n; k++) {
        if(j == i || k == i) continue;
        int nj = pos[j], nk = pos[k];
        if(nj > nk) swap(nj, nk);
        Point pj = temp[nj].first, pk = temp[nk].first;
        if(ccw(0, pj, pk) == 1) { c3[i][j][k] = c3[i][k][j] = nk - nj - 1; }
        else { c3[i][j][k] = c3[i][k][j] = n - nk + nj - 2; }
      }
    }
  }
  ll ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      for(int k = j + 1; k < n; k++) {
        int ni = i, nj = j, nk = k;
        if(ccw(ve[ni], ve[nj], ve[nk]) == -1) swap(nj, nk);
        ll temp = n;
        temp += (c3[ni][nj][nk] + c3[nj][nk][ni] + c3[nk][ni][nj]);
        temp -= (c2[ni][nj] + c2[nj][nk] + c2[nk][ni]);
        ans += C3(1LL * temp);
      }
    }
  }
  return ans;
}

int n;
vector<pii> pt;

ll area(pii a, pii b, pii c){
    ll ret = 0;
    vector<pii> v{a, b, c};
    for (int i=0;i<3;i++){
        int ni = (i + 1) % 3;
        ret += v[i].fi * v[ni].se - v[i].se * v[ni].fi;
    }
    return abs(ret);
}
ll solve2(vector<pii> const& pt){
    int n = pt.size();
    ll ans = 0;
    for (int i=0;i<n;i++){
        for (int j=i + 1;j<n;j++){
            for (int k=j + 1;k<n;k++){
                ll temp = area(pt[i], pt[j], pt[k]);
                ll cnt = 0;
                for (int pos=0;pos<n;pos++){
                    if (pos == i || pos == j || pos == k) continue;
                    ll cur = 0;
                    cur += area(pt[i], pt[j], pt[pos]);
                    cur += area(pt[i], pt[k], pt[pos]);
                    cur += area(pt[k], pt[j], pt[pos]);
                    if (temp == cur){
                        cnt++;
                    }
                }
                ans += cnt * (cnt - 1) * (cnt - 2) / 6;
            }
        }
    }
    return ans;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // cin >> n;
    // for (int i=1;i<=n;i++){
    //     pii temp;
    //     cin >> temp.fi >> temp.se;
    //     pt.pb(temp);
    // }
    // cout << solve(pt) << el;

    for (int i=1;i<=100;i++){
        int n = rand() % 20 + 1;
        vector<pii> pt;
        for (int j=0;j<n;j++){
            pii temp = mp(rand() % 10000 + 1, rand() % 10000 + 1);
            pt.pb(temp);
        }
        ll ans1 = solve(pt);
        ll ans2 = solve2(pt);
        cout << ans1 << " " << ans2 << " " << (ans1 == ans2) << el;
    }

    return 0;
}