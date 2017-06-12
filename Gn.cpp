#include <iostream>
//#include <cmath>
#include <vector>
//#include <algorithm>
//#include <iomanip>

using std::vector;



int getCompConex(){
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

void atrID(vector<vector<int>> g, int *cc, int v1, int d){
int adj;
cc[v1] = d;


}

int adj(int vert){ 
// Como pegar vertice adjacente
}


int getVSize(vector<vector<int>> g){
	return g[0].size();
}	

int getESize(vector<vector<int>> g){
	return g.size();
}

int getEBetween(vector<vector<int>> g, int i){
	for(int j = 0; j < g[0].size(); j++){
		if(g[i][j] >= 0){
			return g[i][j];
		}
	}
}

void removeEdg(){
	// how?
}



int gNewman(vector<vector<int>> g, int k){
	int conex = 1;
	do{
		countPaths(g);
		removeBridge(g);	// reseta a betweeness?
		conex = g.getCompConex();
	}while(conex < k)
	return g;
	// ou retorna modif?
}

//review
void countPaths(vector<vector<int>> g){
	vector<int> path;
	for(int i =0; i < g[0].size(); i++){
		for(int j = i+1; j < g[0].size(); j++){
			// passa por ref pra não ficar copiando?
			path = shortestPath(g, i, j);
			// is this O(n log n)?
		}
	}
}

vector<int> shortestPath(vector<vector<int>> g, int i, int j){
	// Dijkstra
}

void removeBridge(vector<vector<int>> g){
	int great = 0;
	int idx = 0;
	int eBetween;
	for(int i = 0; i < g.size(); i++){
		eWeight = g.getEWeight(i);
		if(eWeight > great){
			great = eWeight;
			idx = i;
		}
	}
	g.remEdg(idx);
}

int main(int argc, char const *argv[]) {

	vector<vector<int>> g = {
		{ 1, 0, 0, 1, 0},
		{ 0, 1, 0, 0, 1},
		{ 0, 0, 1, 1, 0},
		{ 0, 1, 1, 0, 0},
		{ 0, 0, 0, 1, 1},
		{ 1, 0, 1, 0, 0}
	};
	vector<vector<int>> betw = {0,0,0,0,0,0};
}
