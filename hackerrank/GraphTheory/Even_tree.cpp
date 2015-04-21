#include <iostream>
#include <vector>
#include <queue>

using namespace std;
void init(vector<vector<int> >& adj,int E);
void prt(vector<vector<int> > adj);
int solve(vector<vector<int> >& adj, vector<bool>& confirm,int here);
int result=0;
int main(){

    int V,E;
	int solution = 0;
	cin >> V >> E;
	vector<vector<int> > adj(V, vector<int>(V,0));
	vector<bool> confirm(V,false);
	init(adj,E);

	
	int count;
	count = solve(adj,confirm,0);
//	cout << count << endl;
	cout << result-1 << endl;

//	prt(adj);
	return 0;
}
void init(vector<vector<int> >& adj, int E){
	
	int t1,t2;
	for(int i=0; i<E; i++){
		cin >> t1 >> t2;
		adj[t1-1][t2-1]=1;
		adj[t2-1][t1-1]=1;
	}	
}
void prt(vector<vector<int> > adj){
	for( int i=0; i<adj.size(); i++){

		for( int j=0; j<adj[i].size(); j++){
			cout << adj[i][j] << " " ;
		}
		cout<<endl;
	}
}

int solve(vector<vector<int> >& adj, vector<bool>& confirm,int here){

	confirm[here] = true;
	int boop=0;
	for( int i=0; i<adj[here].size(); i++){

		if( (!confirm[i]) && (adj[here][i])){
//			cout << "here " << here << " i " << i <<endl;
			boop += solve(adj,confirm,i);
		}
	}
	if ( (boop+1) % 2==0 ){
		result++;
//		cout << "boop: "<< boop << endl;
	}
//				cout << boop << endl;
	return boop+1;
}
