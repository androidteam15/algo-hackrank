#include <iostream>
#include <vector>

using namespace std;
void solve(int testNum);
int gcd(int x, int y);
int getlcm(vector<int> cuttime);
int main(){

	int testCase;

	cin >> testCase;

	for( int i=0; i<testCase; i++){
		solve(testCase-1);
	}

	return 0;
}
void solve(int testNum){
	int B, N;
	int tmp;
	int result=0;
	int shortener;
	vector<int> cuttime;
	
	cin >> B >> N;


	for(int i=0; i<B; i++){
		cin >> tmp;
		cuttime.push_back(tmp);
	}

	shortener = getlcm(cuttime);
	N = N % shortener ;

	for(int i=0; i<shortener; i++){
		int emptyBarber = 0;
		vector<int> tmp;
		vector<int> tmp2;
		if(i == 0){
			emptyBarber=cuttime.size();
		}
		else{
			for(int j=0; j<cuttime.size(); i++){
				if(cuttime.at(j)%i ==0 ){
					tmp.push_back(cuttime.at(j));
					tmp2.push_back(cuttime.at(j));
					emptyBarber++;
				}
			}
		}
		if( N < emptyBarber ){
			sort(tmp.begin(),tmp.end());
			for( int i=0; i<tmp2.size();i++){

				if(tmp2.at(i) == tmp.at(N-1)){
					result = i;
					break;
				}
			}
			break;

		}
		else
			N -= emptyBarber;

		tmp.empty();
	}


	cout << "Case #" << testNum << ": " << result << endl;


}
int gcd(int x, int y){
	int n;
	while(1){
		n=x%y;
		if (!n) return y;
		x=y;
		y=n;
	}
}
int getlcm(vector<int> cuttime){

	int lcm=cuttime.at(0);
	for(int i=1; i<cuttime.size(); i++)
		lcm = (cuttime.at(i)*lcm)/gcd(cuttime.at(i), lcm);
	return lcm;
}