#include <iostream>

using namespace std;

int main(){

	int N;
	int K;
	int cnt=0;
	string a;

	cin >> N;
	cin >> K;
	cin >> a;

	int sol[N];
	//48
	int x=0;
	for(int i=0; i<N; i++){
		sol[i] = x^(a[i]-48);
		x ^= sol[i];

		if( cnt >= K-1){
			x ^= sol[i-K+1];
		}
		cnt++;
		
	}	

	for(int i=0; i<N; i++){
		cout << sol[i];
	}

	cout << endl;

	return 0;
}
