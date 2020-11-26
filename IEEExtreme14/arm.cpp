#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using uint = unsigned int;

int q;
uint n;
vector<string> ans;

void MOV(int a, int b, int sh){
    string temp = "MOV R" + to_string(a) + ", R" + to_string(b) + ", ";
    if (sh < 0) temp += "LSR #" + to_string(-sh);
    else temp += "LSL #" + to_string(sh);
    ans.pb(temp);
}
void QUER(string op, int a, int b, int c, int sh){
    string temp = op + " R" + to_string(a) + ", R" + to_string(b) + ", R" + to_string(c) + ", ";
    if (sh < 0) temp += "LSR #" + to_string(-sh);
    else temp += "LSL #" + to_string(sh);
    ans.pb(temp);
}
void ADD(int a, int b, int c, int sh){ QUER("ADD", a, b, c, sh); }
void SUB(int a, int b, int c, int sh){ QUER("SUB", a, b, c, sh); }
void RSB(int a, int b, int c, int sh){ QUER("RSB", a, b, c, sh); }

uint bit_cnt(uint x, uint len, bool flip){
    uint n = (x & ((1 << len) - 1));
    if (flip) return ((uint)32) - (uint)__builtin_popcountl(n);
    return (uint)__builtin_popcountl(n);
}

void solve(){
    cin >> n;
    uint bcnt = __builtin_popcountl(n);

    bool flip = 0;
    if (bcnt > 16){
        SUB(1, 1, 0, 0);
        flip = 1;
    }

    for (uint i=31;i>=0;i--){
        if (!flip && (n & (((uint)1) << i))){
            ADD(1, 1, 0, i);
        } else if (flip && (n & (((uint)1) << i)) == 0){
            SUB(1, 1, 0, i);
        }
        if (i == 0) break;
        if (bit_cnt(n, i, flip) * 2 > i + 1){
            RSB(1, 1, 0, i);
            flip = !flip;
        }
    }
    MOV(0, 1, 0);

    for (auto x : ans){
        cout << x << el;
    }
    cout << "END\n";
    ans.clear();
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        solve();
    }

    return 0;
}