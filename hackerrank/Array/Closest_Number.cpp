#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>


using namespace std;
int main(){

	int N;
	vector<int> arr;
	vector< pair<int, int> > solution;
	cin >> N;
	int min=INT_MAX;

	for(int i=0; i<N; i++){
		int k;
		cin >> k;
		arr.push_back(k);
	}
	sort(arr.begin(), arr.end());

	

	for(int i=1; i<N; i++){
		int tmp = arr[i]-arr[i-1];
		if(tmp < min){
			solution.erase( solution.begin(), solution.end() );
			min = tmp;

			solution.push_back( make_pair(arr[i-1],arr[i]) );
		}
		else if( min == tmp){
			solution.push_back( make_pair(arr[i-1], arr[i]));
		}
	}

	for(int i=0; i< solution.size(); i++){
		cout << solution[i].first << " " << solution[i].second << " ";
	}


	return 0;
}