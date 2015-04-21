#include<iostream>
#include<queue>
#include<list>
#include<vector>
using namespace std;

void solve(int adj[][],int start,int *result);
int main(){
	int V,E;

	cin >> V >> E;
	int adj[V][V];
	int t1, t2;
	int * result;
	*result =  0;
	for(int i=0; i<V; i++)
		for(int j=0; j<V; j++)
			adj[i][j]=0;
	
	for(int i=0; i<E; i++){
		cin >> t1 >> t2;
		adj[t1-1][t2-1] = 1;
		adj[t2-1][t1-1] = 1;
	}
	solve(adj, 0,result);

	return 0;
}
void solve(int adj[][],int start,int *result){
	cout << sizeof(adj[start])<<endl;
}

