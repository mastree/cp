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

const int N = 5e5 + 10;

int n;
string s;
int bit[N][26];

void upd(int pos, int a, int add){
    while (pos < N){
        bit[pos][a] += add;
        pos = pos + (pos & (-pos));
    }
}

int ask(int b, int a){
    int temp[26];
    fill(temp, temp + 26, 0);
    b--;
    while (a > 0){
        for (int i=0;i<26;i++){
            temp[i] += bit[a][i];
        }
        a = a - (a & (-a));
    }
    while (b > 0){
        for (int i=0;i<26;i++){
            temp[i] -= bit[b][i];
        }
        b = b - (b & (-b));
    }
    int ret = 0;
    for (int i=0;i<26;i++) if (temp[i]) ret++;
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> s;
    for (int i=0;i<n;i++){
        int dig = (int)s[i] - (int)'a';
        upd(i + 1, dig, 1);
    }

    int q;
    cin >> q;
    while (q--){
        int tipe;
        cin >> tipe;
        if (tipe == 1){
            int pos;
            char c;
            cin >> pos >> c;
            int dig = (int)c - (int)'a';
            int pref = (int)s[pos - 1] - (int)'a';
            s[pos - 1] = c;
            upd(pos, pref, -1);
            upd(pos, dig, 1);
        } else{
            int l, r;
            cin >> l >> r;
            cout << ask(l, r) << el;
        }
    }

    return 0;
}