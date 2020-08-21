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

string s,t;
int n;
int cnt[26],ans;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> s >> t;
    for (int alp=0;alp<26;alp++){
        char c=('a'+alp);
        for (int i=0;i<n;i++){
            if (s[i]==c || t[i]==c){
                cnt[alp]++;
            }
        }
        ans=max(ans,cnt[alp]);
    }

    cout << ans << el;

    return 0;
}