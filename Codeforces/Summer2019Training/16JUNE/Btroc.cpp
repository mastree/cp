#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

string s,t;
int cnts[26],cntt[26];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> t;
    for (int i=0;i<26;i++){
        cnts[i]=0;
        cntt[i]=0;
    }

    int lens=s.length(),lent=t.length();
    for (int i=0;i<lens;i++){
        cnts[s[i]-'a']++;
    }

    for (int i=0;i<lent;i++){
        cntt[t[i]-'a']++;
    }

    vector <int> jenis;
    for (int i=0;i<26;i++){
        if (cntt[i]>0) jenis.pb(i);
    }

    int sz=jenis.size();
    if (sz>1){
        cout << 0 << el;
        return 0;
    }
    
    if (cntt[jenis[0]]==1){
        cout << cnts[jenis[0]] << el;
        return 0;
    }

    int tot=0;
    for (int i=0;i<26;i++){
        if (i!=jenis[0]){
            tot+=cnts[i];
        }
    }

    int butuh=(cnts[jenis[0]])/(cntt[jenis[0]]-1);
    int sisa=butuh-tot;
    
    if (sisa<=0){
        cout << 0 << el;
        return 0;
    }

    sisa=sisa*(cntt[jenis[0]]-1)+cnts[jenis[0]]%(cntt[jenis[0]]-1);
    cout << sisa-lent+1 << el;

    return 0;
}