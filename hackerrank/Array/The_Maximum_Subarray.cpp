#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
	int testCase;

	cin >> testCase;

	for(int j=0; j<testCase; j++){
		int input;
		cin >> input;
		vector<int> arr;
		int tmp;
		int max=0;
		int innerMax = -1000000000;
		int result1=0;
		int result2=0;

		for(int i=0; i<input; i++) { 
			cin >> tmp; 
			if (tmp > 0)
				result2 += tmp;
			if( tmp > innerMax)
				innerMax = tmp;
			arr.push_back(tmp); 
		}

		

		for(int i=0; i<arr.size(); i++){
			if( arr[i]<0 ){
				if( result1 > max)
					max = result1;

				if( result1 + arr[i] < 0 ) result1 = 0;
				else result1 += arr[i];

			}
			else
				result1 += arr[i];
			
		}
		if( result1 > max)
			max = result1;

		if( innerMax < 0){
			result2 = innerMax;
			max = innerMax;
		}

		cout << max << " " << result2 << endl;

	}


}