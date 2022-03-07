// #include <bits/stdc++.h>


// #define fi first
// #define se second
// #define pb(a) push_back(a)
// #define mp(a, b) make_pair(a, b)
// #define el '\n'

// using namespace std;
// using ll = long long;
// using pii = pair<int, int>;

// void trim(string& s){
//     while (s.back() == ' ' || s.back() == '\n') s.pop_back();
//     reverse(s.begin(), s.end());
//     while (s.back() == ' ' || s.back() == '\n') s.pop_back();
//     reverse(s.begin(), s.end());
// }

// int main () {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     cout << "{";
//     for (int i=0;i<50;i++){
//         int a;
//         cin >> a;
//         string s;
//         getline(cin, s);
//         trim(s);
//         cout << '"';
//         if (s != "No solution") cout << s;
//         else cout << 0;
//         cout << '"';
//         if (i != 49) cout << ", ";
//     }
//     cout << "}" << el;

//     return 0;
// }
#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;

vector<string> ans = {"0 0 0", "0 0 1", "0 1 1", "1 1 1", "0", "0", "-1 -1 2", "0 -1 2", "0 0 2", "0 1 2", "1 1 2", "-2 -2 3", "7 10 -11", "0", "0", "-1 2 2", "-511 -1609 1626", "1 2 2", "-1 -2 3", "0 -2 3", "1 -2 3", "-11 -14 16", "0", "0", "-2901096694 -15550555555 15584139827", "-1 -1 3", "0 -1 3", "0 0 3", "0 1 3", "1 1 3", "-283059965 -2218888517 2220422932", "0", "0", "8866128975287528 -8778405442862239 -2736111468807040", "-1 2 3", "0 2 3", "1 2 3", "0 -3 4", "1 -3 4", "117367 134476 -159380", "0", "0", "-80538738812075974 80435758145817515 12602123297335631", "2 2 3", "-5 -7 8", "2 -3 4", "-2 3 3", "6 7 -8", "-23 -26 31", "0"};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    cout << ans[n] << el;

    return 0;
}