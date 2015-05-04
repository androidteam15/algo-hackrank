#include <iostream>
#include <vector>
using namespace std;
int main(){

	int data;
	cin >> data;

	vector<int> heap;

	for(int i=0; i<data; i++){
		int tmp;
		cin >> tmp;
		heap.push_back(tmp);
	}
	return 0;
}
