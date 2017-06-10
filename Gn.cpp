#include <iostream>
//#include <cmath>
#include <vector>
//#include <algorithm>
//#include <iomanip>

using std::vector;

class Graph{
	vector<vector<>> graf;

	public Graph (vector<vector<>> g){
		graf = g;
	}

	public int getCompConex(){
		// how?
	}

	public int getVSize(){
		return graf.size();
	}	

	public int getESize(){
		return graf[0].size();
	}

	public int getEWeight(int j){
		for(int i = 0; i < g.size(); i++){
			if(g[i][j] >= 0){
				return g[i][j];
			}
		}
	}

	public void removeEdg(){
		// how?
	}
};


int gNewman(Graph g, int k){
	int conex = 1;
	do{
	countPaths(g);
	removeBridge(g);	// reseta os pesos tbm?
	conex = g.getCompConex();
	}while(conex < k)
	return g;
	// ou retorna modif?
}

void countPaths(Graph g){
	vector<int> path;
	for(int i =0; i < g.getVSize(); i++){
		for(int j = i+1; j < g.getVSize(); j++){
			// passa por ref pra não ficar copiando?
			path = shortestPath(g, i, j);
			// is this O(n log n)?
		}
	}
}

vector<int> shortestPath(Graph g, int i, int j){
	// Dijkstra
}

// Ao criar o graph tem q settar todos pesos pra -1 (pq pode ter peso 0)
void removeBridge(Graph g){
	int great = 0;
	int idx = 0;
	int eWeight;
	for(int i = 0; i < g.getESize(); i++){
		eWeight = g.getEWeight(i);
		if(eWeight > great){
			great = eWeight;
			idx = i;
		}
	}
	g.remEdg(idx);
}
// Em algumas implementações ele remove arestas de pesos iguais ao mesmo tempo.