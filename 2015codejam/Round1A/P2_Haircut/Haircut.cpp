#include <iostream>
#include <vector>
using namespace std;
void solve(int testNum);
long getCustomer(long T, vector<int>& minute);
int main(){
	int testCase;
	cin >> testCase;

	for(int i=1; i<= testCase; i++){
		solve(i);
	}
	return 0;
}
void solve(int testNum){
	int result;
	long B, N;
	int tmp;
	vector<int> minute;

	cin >> B >> N;
	for(int i=0; i<B; i++){
		cin >> tmp;
		minute.push_back(tmp);
	}
	
	long low = -1, high = 100000L*N;
	
	while( low+1 < high ){
		long mid = (low + high) /2;
		if( getCustomer(mid, minute) < N )
			low = mid;
		else 
			high = mid;
	}
	long T = high;
	int customers_served_before = getCustomer( T-1 , minute);
	int customers_to_be_served = N - customers_served_before;
	for( int barber = 0; barber<B; barber++){
		if( T % minute[barber] == 0 ){
			customers_to_be_served--;
			if( customers_to_be_served == 0){
				result =  barber+1;
				break;
			}
		}
	}
	
	


	cout << "Case #" << testNum << ": " << result << endl;
}
long getCustomer(long T, vector<int>& minute){
	long customer = 0;
	if( T < 0 ) return 0;
	for( int i=0; i<minute.size(); i++){
		customer +=  T / minute[i] + 1;
	}
	return customer;
}
