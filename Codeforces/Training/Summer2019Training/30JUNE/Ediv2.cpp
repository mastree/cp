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

vector <int> adlist[200008];
map <int,ll> nil[200008];
int n;
map <int,bool> cek[200008];
ll nilt[200008];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<n;i++){
        int a,b;
        cin >> a >> b;
        adlist[a].pb(b);
        adlist[b].pb(a);
    }

    queue <int> q;
    for (int i=1;i<=n;i++){
        nilt[i]=1;
        if (adlist[i].size()==1){
        //    nil[adlist[0]][i]++;
            q.push(i);
        }
    }

    while (!q.empty()){
        int cur=q.front();
        q.pop();

        for (auto x : adlist[cur]){
            if (cek[cur][x]) continue;

            cek[cur][x]=1;
            nil[adlist][cur]+=nilt[cur];
        }
    }

    return 0;
}