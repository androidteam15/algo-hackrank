#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void solve(int testNum);
int getDigit(long N);
long getDigitCount(int digit);
int main(){

	int testCase;
	cin >> testCase;
	
	for(int i=1; i<=testCase; i++){

		solve(i);
	}


	return 0;
}
void solve(int testNum){

	long N;
	long tmp;
	int digit;
	int tmpDigit;
	long sol;
	long sol1=0;

	cin >> N;

	tmp = N;

	digit = getDigit(N);
	sol = getDigitCount(getDigit(N));

	if( (N%10 == 0) && (getDigit(N-1)==digit) ){
		tmp = N-1;
		sol++;
	}

	if( digit ==1 ){
		sol --;
	}

	for(int i=0; i< (digit+1)/2; i++){
		sol += (tmp%10) * pow(10.0, double(i)) ;
		tmp /= 10;
	}
	
	

	if( tmp > pow(10.0, double( ((digit)/2) -1 )) ){
		while( tmp > 0 ){
			sol1 *=10;
			sol1 += (tmp%10);
			tmp /=10;
		}
	}
	sol += sol1;
	cout << "Case #" << testNum << ": " << sol << endl;



}
int getDigit(long N){

	int sol=0;
	while( 1 ){
		if( N > 0 ){
			N=N/10;
			sol++;
		}
		else
			return sol;
	}
}
long getDigitCount(int digit){
	long result=0;

	for(int i=1; i<=digit; i++){
		if(i==1) result +=1;
		else if(i==2) result += 9;
		else{
			if( (i-1)%2 == 1 ){
				result += pow(10.0, double( (i/2) -1 )) * 9;
			}
			for(int j=1; j<=( (i-1)/2); j++ ){
				result += (pow(10.0, double(j-1)) * 9 * 2);
				
			}
					

			result ++;
		}
	}
	return result;
}
