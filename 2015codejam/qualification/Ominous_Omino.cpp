#include <iostream>
using namespace std;
void solve(int testNum);
int main(){

	int testCase;

	cin >> testCase;

	for(int i=1; i<=testCase; i++){
		solve(i);
	}

	return 0;
}
void solve(int testNum){


	int X, R, C;
	int S,L;
	bool result = true;

	cin >> X >> R >> C;

	if( R > C) {
		S = C;
		L = R;
	}
	else{
		S = R;
		L = C;
	}
		
	if( (S*L)%X != 0 ) result = false;
	//if( ((S*L)/X) < 2 ) result = false;
	if( X==3 && S<2 ) result = false;
	if( X==4 && S<=2 ) result = false;
	if( X==5 && (S<=2 || (S==3 && L==5)) ) result = false;
	if( X==6 && S<=3 ) result = false;
	if( X>=7 ) result = false;

	if(  result )
		cout << "Case #" << testNum << ": GABRIEL" << endl;
	else
		cout << "Case #" << testNum << ": RICHARD" << endl;

}