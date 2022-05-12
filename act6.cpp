/******************************************************************************
CS 325 Activity 6 Babyface & Heels
Sample Test Case
Input:
4
4
1 2
1 3
4 2
4 3
Output:
Possible
Save file as act6.cpp before submitting to Gradescope
*******************************************************************************/

#include <iostream>
#include <fstream>
#include <queue>

int G[100][100];   // if you want to use an adjacency matrix

bool babyfaceHeel(int matrix[100][100], int n) {
	int array[n];
	for (int i = 0; i < n; i++)
		array[i] = -1;
	
	array[0] = 1;
	
	std::queue<int> que;
	que.push(0);
	
	while (!que.empty()) {
		int u = que.front();
		que.pop();
		
		if (G[u][u] == 1)
			return false;
		
		for (int i = 0; i < n; i++) {
			if (G[u][i] == 1 && array[i] == -1) {
				array[i] = 1 - array[u];
				que.push(i);
			}
			
			else if (G[u][i] == 1 && array[i] == array[u])
				return false;
		}
	}
	
	return true;
}

int main () {
  // Create a graph given in the above diagram

	int n;      	// number of wrestlers numbered 1..n
	int m;		    // number of rivalries
	int w1, w2;
  
	std::cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			G[i][j]=0;

	std::cin >> m;
  
	for (int j = 0; j < m; j++) {
		// 1st wrestler
		std::cin >> w1;
		// 2nd wrestler
		std::cin >> w2;
		w1--;
		w2--;
		// Add edges to adjacency matrix optional
		G[w1][w2] = 1;
		G[w2][w1] = 1;
	}
 
	if (babyfaceHeel(G,n))
		std::cout << "Possible" << std::endl;
	else
		std::cout << "Impossible" << std::endl;
		
	return 0;
}
