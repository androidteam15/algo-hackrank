#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

	int n;
	int tmp,tmp2,tmp1;
	int sol;
	cin >> n;
	vector<int> arr;
	for(int i=0; i<n; i++) { 
		cin >> tmp;
		arr.push_back(tmp);
	};

	int p,q;
	cin >> p >> q;

	sort(arr.begin(), arr.end());

	int start=0;
	int end=n-1;

	for( int i=0; i<n; i++){
		if(arr[i]<=p)
			start = i;
		if(arr[i]>=q){
			end = i;
			break;
		}
	}
	
	if( arr[0] >= p ) {
		start = 0;
		tmp1 = arr[start]-p;
	}
	else {
		tmp1 = min( arr[start+1]-p, p-arr[start] );
	}

	if( arr[n-1] <= q) {
		end = n-1;
		tmp2 = q-arr[n-1];
	}
	else {
        if( ((arr[end]-arr[end-1])/2) > q-arr[end-1] ){
            end--;
            tmp2 = q-arr[end];
        }
        else{
        	tmp2 = min(q-arr[end], arr[end+1]-q);
        }
		
	}

	int maxVal=0;
	int maxIndex=0;
	for(int i=start; i<end; i++){
		if( maxVal < ((arr[i+1]-arr[i])/2) ){
			maxVal = (arr[i+1]-arr[i])/2;
			maxIndex = i;
		}
	}



	if( tmp1 < tmp2 && maxVal < tmp2)
		sol = q;
	else if( tmp1 < maxVal)
		sol = arr[maxIndex] + maxVal;
	else
		sol = p;
    

	cout << sol << endl;


	return 0;
}