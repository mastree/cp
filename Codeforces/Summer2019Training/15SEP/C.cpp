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

int n,ca,cb;
string s,t;
int cntab,cntba;
vector <int> vab,vba;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s >> t;

    for (int i=0;i<n;i++){
        if (s[i]=='a') ca++;
        else cb++;

        if (t[i]=='a') ca++;
        else cb++;
    }

    if ((ca%2) || (cb%2)){
        cout << -1 << el;
        return 0;
    }

    for (int i=0;i<n;i++){
        if (s[i]==t[i]) continue;
        if (s[i]=='a'){
            cntab++;
            vab.pb(i);
        }
        else {
            cntba++;
            vba.pb(i);
        }
    }

    int ans=0;
    ans+=cntba/2;
    cntba%=2;
    ans+=cntab/2;
    cntab%=2;

    if (cntab&&cntba) ans+=2;

    cout << ans << el;
    int len1=vab.size(),len2=vba.size();
    for (int i=0;i<len1-1;i+=2){
        cout << vab[i]+1 << " " << vab[i+1]+1 << el;
    }
    for (int i=0;i<len2-1;i+=2){
        cout << vba[i]+1 << " " << vba[i+1]+1 << el;
    }

    if (cntab&&cntba){
        cout << vab[len1-1]+1 << " " << vab[len1-1]+1 << el;
        cout << vab[len1-1]+1 << " " << vba[len2-1]+1 << el;
    }

    return 0;
}