#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int N = 1e5 + 10;
const int INF = 1e9;

int n;
string s;

vector<int> pcman, ast;

bool bisa(int mn){
    int i = 0, j = 0;
    while (i < pcman.size() && j < ast.size()){
        int j1 = j, j2 = j;

        if (1){
            int cur = 0;
            if (pcman[i] > ast[j]){
                cur += pcman[i] - ast[j];
            }
            if (cur > mn) return 0;
            while (j1 < ast.size() && ast[j1] < pcman[i]) j1++;
            if (cur * 2 < mn){
                cur *= 2;
                int sisa = mn - cur;
                while (j1 < ast.size() && sisa >= ast[j1] - pcman[i]){
                    j1++;
                }
            }
        }
        if (1){
            int cur = 0;
            if (pcman[i] > ast[j]){
                cur += pcman[i] - ast[j];
            }
            if (cur > mn) return 0;
            while (j2 < ast.size() && ast[j2] < pcman[i]) j2++;
            if (cur < mn){
                int sisa = mn - cur;
                while (j2 < ast.size() && sisa >= 2 * (ast[j2] - pcman[i])){
                    j2++;
                }
            }
        }
        j = max(j1, j2);
        i++;
    }
    if (j == ast.size()) return 1;
    return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    s = "*" + s;

    for (int i=1;i<=n;i++){
        if (s[i] == '*'){
            ast.pb(i);
        } else if (s[i] == 'P'){
            pcman.pb(i);
        }
    }

    int l = 0, r = INF;
    while (l < r){
        int m = (l + r) / 2;
        if (bisa(m)){
            r = m;
        } else{
            l = m + 1;
        }
    }
    cout << r << el;

    return 0;
}
