#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct link_list{
    char c;
    link_list* bef = 0, next = 0;

    link_list() : c(0), next(0), bef(0) {}
    link_list(char c) : c(c), next(0), bef(0) {}
    link_list(char c, link_list* bef, link_list* next) : c(c), next(next), bef(bef) {}
};

typedef link_list* plist;

void solve(){
    string s;
    cin >> s;
    plist head = new link_list();
    plist p = head;
    for (auto x : s){
        if ()
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}