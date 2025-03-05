// https://atcoder.jp/contests/practice2/tasks/practice2_a

#include <iostream>
#include <vector>
#include<bits/stdc++.h>
#include <cmath>
#include<algorithm>

using namespace std;

vector<int> p(200001);

int getP(int x) {
    if (x == p[x]) return x;
    int k = getP(p[x]);
    p[x] = k;
    return k;
}

void join(int u, int v) {
    int pu = getP(u);
    int pv = getP(v);
    
    if (pu == pv) return;
    
    p[pv] = pu;
}

void check(int u, int v) {
    int pu = getP(u);
    int pv = getP(v);
    
    cout << (pu==pv?1:0) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, q;
	cin >> n >> q;
	
	for (int i=0;i<n;i++) p[i] = i;
	
	int command, u, v;
	while (q--) {
	    cin >> command >> u >> v;
	    switch (command) {
	        case 0:
	            join(u, v);
	            break;
	        case 1:
	            check(u, v);
	            break;
	    }
	}

	return 0;
}
