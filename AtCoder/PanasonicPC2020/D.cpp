#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define pli pair<long long,int>
#define pil pair<int,long long>
#define ll long long
#define el '\n'

using namespace std;

int n;
string s;
bool ada[10];

void sol(int cur, int byk){
    if (cur == n){
        cout << s << el;
        // cnt++;
        // s.pop_back();
        return;
    }
    int ncur = cur+1;
    for (int i=0;i<=byk;i++){
        s.pb(char(i + 'a'));
        if (i == byk) sol(ncur, byk + 1);
        else sol(ncur, byk);
        s.pop_back();
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    sol(0, 0);
    // cout << cnt << el;

    return 0;
}