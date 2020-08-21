#include <bits/stdc++.h>


#define fi first
#define se second
#define pb push_back
#define pf push_front
#define mp make_pair
#define MOD 1000000007
#define pii pair<int,int>
#define ll long long
#define el '\n'

using namespace std;

int n,k;
deque <bool> deq;

deque <bool> sol (int a){
    
    if (a==0){
        deque <bool> d;
        d.pf(1);
        return d;
    }

    deque <bool> d,tm;
    tm=sol(a-1);
    d.pf(1);
    while(!tm.empty()){
        d.pb(tm.front());
        d.pf(tm.front());
        tm.pop_front();
    }
    d.pf(0);
    d.pb(0);
    return d;
} 

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    deq=sol(n);
    int tot=0;
    for (int i=0;i<k;i++){
    //    cerr << deq.front();
        tot+=deq.front();
        deq.pop_front();
    }// cerr << el;

    cout << tot << el;

    return 0;
}