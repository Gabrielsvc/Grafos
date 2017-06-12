#include <iostream>
//#include <cmath>
#include <vector>
//#include <algorithm>
//#include <iomanip>

using std::vector;

class Graph{
	vector<vector<>> graf;

	//Aresta X Vertice
	public Graph (vector<vector<>> g){
		graf = g;
	}

	public int getCompConex(){
		// how?
		/*Busca em Profundidade!*/
		int *cc = new int[g[0].size()];
		int vert;
		for(vert = 0;vert < g[0].size(); ++vert){
			cc[vert] = -1;
		}
		for(vert = 0 ; vert <g[0].size(); ++vert)
			if(cc[vert] == -1)
				atrID(g, cc, v, id++);		
	}
	
	public void atrID(Graph g, int *cc, int v1, int d){
	int adj;
	cc[v1] = d;
	
	
	}
	public int adj(int vert){ 
	// Como pegar vertice adjacente
	}
	

	public int getVSize(){
		return graf[0].size();
	}	

	public int getESize(){
		return graf.size();
	}

	public int getEWeight(int i){
		for(int j = 0; j < g[0].size(); j++){
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

int main(int argc, char const *argv[]) {
	vector<vector<int>> g = {
		{ 1, 0, 0, 1, 0},
		{ 0, 1, 0, 0, 1},
		{ 0, 0, 1, 1, 0},
		{ 0, 1, 1, 0, 0},
		{ 0, 0, 0, 1, 1},
		{ 1, 0, 1, 0, 0}
	};
	Graph grafo1 = new Grafo(g);
	// Etc
}
