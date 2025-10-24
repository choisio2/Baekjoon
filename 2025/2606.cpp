#include <iostream>
#include <vector>
using namespace std; 

vector<int> v[105]; 
int virus[105]; 
int result; 

void dfs(int x) {
	for (int i = 0; i < v[x].size(); i++) {
		int k = v[x][i]; 

		if (virus[k] == 0) {
			virus[k] = 1; 
			result++; 
			dfs(k); 
		}
	}

	return; 
}


int main() {
	int n, m; // 컴퓨터 수, 간선 수 
	int a, b; 

	cin >> n >> m; 

	for (int i = 0; i < m; i++) {
		cin >> a >> b; 

		v[a].push_back(b); 
		v[b].push_back(a); 
	}

	virus[1] = 1; 
	dfs(1); 

	cout << result << endl; 

	return 0; 
}
