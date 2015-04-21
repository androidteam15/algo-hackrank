#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;
int modMult(int a, int b){
	return (a * (long long)b) % MOD;
}
int modAdd(int a, int b){
	return (a + (long long)b) % MOD;
}
int main(){
	int t;
	cin >> t;

	for(int j=0; j<t; j++){
		int n,m;
		int xc,yc;
        int tmp;
        int sol = 0;
		cin >> n;
		cin >> m;
		vector<int> ar1;
		vector<int> ar2;
        for(int i=0; i<n; i++) { cin >> tmp; ar1.push_back(tmp);}
		for(int i=0; i<m; i++) { cin >> tmp; ar2.push_back(tmp);}

		sort(ar1.begin(), ar1.end(), greater<int>());
		sort(ar2.begin(), ar2.end(), greater<int>());

		int xIndex=0;
		int yIndex=0;
		for(int i=0; i<m+n; i++){
			if(xIndex == m){
				sol = modAdd(sol, modMult(ar2[yIndex],xc));
				yc++;
			}
			else if(yIndex == n){
				sol = modAdd(sol, modMult(ar1[xIndex],yc));
				xc++;

			}
			else{
				if( ar1[xIndex] > ar2[yIndex]) {
					sol = modAdd(sol, modMult(ar1[xIndex++],yc));
					xc++;
				}
				else{
					sol = modAdd(sol, modMult(ar2[yIndex++],xc));
					yc++;
				}
			}

		}
		cout << sol << endl;
		
	}
	return 0;

}