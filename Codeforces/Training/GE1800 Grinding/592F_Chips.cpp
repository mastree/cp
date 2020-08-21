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

const int N = 200007;

int n,k;
string s;
bool immortal[N];
int jarak[N];

int bef(int a){
    a--;
    if (a<0) return n-1;
    return a;
}

int aft(int a){
    a++;
    if (a>n-1) return 0;
    return a;
}

int skipl(int a, int x){
    a-=x;
    if (a<0) return n+a;
    return a;
}

int skipr(int a, int x){
    a+=x;
    if (a>n-1) return a-n;
    return a;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    cin >> s;
    for(int i=0;i<n;i++){
        int beff=bef(i), aftt=aft(i);

        if (s[i]==s[beff] || s[i]==s[aftt]) immortal[i]=1; 
    }

    for (int i=0;i<n;i++){
        if (immortal[i] && !immortal[aft(i)]){
            int cur=aft(i);
            while (!immortal[cur]){
                jarak[cur]=jarak[bef(cur)]+1;
                cur=aft(cur);
            }
        }
    }

    for (int i=0;i<n;i++){
        if (immortal[i] && !immortal[bef(i)]){
            int cur=bef(i);
            while (!immortal[cur]){
                jarak[cur]=min(jarak[cur],jarak[aft(cur)]+1);
                cur=bef(cur);
            }
        }
    } 

    bool alter=k&1;
    for (int i=0;i<n;i++){
        if (immortal[i]) continue;

        int tm=jarak[i];
        if (tm>k){
            if (alter){
                if (s[i]=='B') s[i]='W';
                else s[i]='B';
            } 
        } else{
            if (immortal[skipl(i,tm)]){
                s[i]=s[skipl(i,tm)];
            } else{
                s[i]=s[skipr(i,tm)];
            }
        }
    }

    cout << s << el;

    return 0;
}