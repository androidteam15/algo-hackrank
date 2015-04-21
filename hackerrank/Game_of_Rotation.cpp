#include <iostream>
#include <cmath>

using namespace std;

int main(){

	int n;
    cin >> n;
    int arr[n];
    long long sum=0;
    long long pmean = 0;
    long long max = 0;
    
    for( int i=0; i<n; i++){
      cin >> arr[i];  
      sum += arr[i];
      pmean += (long long)(i+1)*arr[i];
    } 
    
    max = pmean;

    for(int i=0; i<n; i++){
    	pmean -=  (long long)sum ;
    	pmean += (long long) n* arr[i];
    	if( pmean > max)
    		max = pmean;
    }
   
    cout << max << endl;


	return 0;
}

