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

	int plate;
	int cake;
	int max=0;
	int result=0;

	cin >> plate;

	for(int i=0; i<plate; i++){
		cin >> cake;
		if( max < cake)
			max=cake;
	}

	while( max!=0 ){
		if( max%2 == 1){
			result++;
			max--;
		}
		else{
			result++;
			max /= 2;
		}
	}

	cout << "Case #" << caseNum << ": " << result << endl;

}