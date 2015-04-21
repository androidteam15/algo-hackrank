#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long int Int;


int main(){

	Int testCase;
	Int Radius, Answer;


	cin >> testCase;

	for(int i=0; i<testCase; i++){
		Int cnt=0;
		cin >> Radius >> Answer;
		for( int i=2; i*i<=Radius; i++ ){
			Int result = sqrt(Radius - pow(i,2));
			Int value = Radius - pow(i,2) - pow(result,2);

			if( (!value) ){
				cnt++;
			}
		}

		if(Radius==1) cnt++;

		if( (cnt*4)== Answer)
			cout << "possible"<<endl;
		else
			cout << "impossible"<<endl;


	}



	return 0;
}
