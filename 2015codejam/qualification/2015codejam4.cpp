#include <iostream>

using namespace std;

void resolve(int caseNum);
int main(){

	int testCase;

	cin >> testCase;

	for(int i=0; i<testCase; i++)
		resolve(i+1);

	return 0;
}

void resolve(int caseNum){

	int X,R,C;
	int result=0;
	cin >> X >> R >> C;

	if( R==X ){
		if( C==2 )
			result = 1;
	}
	else if( C==X ){
		if( R==2)
			result = 1;
	}

	
	if( result == 0)
		cout << "Case #" << caseNum << ": RICHARD" << endl;
	else
		cout << "Case #" << caseNum << ": GABRIEL" << endl;



}