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

string s, t;
pair <char, int> ar[5005];
int n, q;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--){
        cin >> s >> t;
        n = s.length();

        vector <int> ch[26];
        for (int i=0;i<n;i++){
            ar[i] = mp(s[i],i);
            ch[s[i]-'A'].pb(i);
        }

        sort(ar, ar + n);
        int id = -1, cur;
        for (int i=0;i<n;i++){
            if (ar[i].se != i){
                id = ch[ar[i].fi-'A'][ch[ar[i].fi-'A'].size()-1];
                cur = i;
                break;
            }
        }
        if (id != -1) swap(s[id], s[cur]);
        if (s<t){
            cout << s << el;
        } else{
            cout << "---" << el;
        }
    }

    return 0;
}