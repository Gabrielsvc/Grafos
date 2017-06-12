#include <iostream>
//#include <cmath>
#include <vector>
//#include <algorithm>
//#include <iomanip>

using std::vector;



int getCompConex(vector<vector<int>> g, vector<int> comm){
	/*Busca em Profundidade!*/
	int vert, id = 0;
	for(vert = 0; vert < g[0].size(); vert++){
		comm.push_back(-1);
	}
	for(vert = 0; vert < g[0].size(); vert++)
		if(comm[vert] == -1)
			atrID(g, comm, vert, id++);		
}

void atrID(vector<vector<int>> g, vector<int> comm, int v, int id){
	int adj;
	comm[v] = id;
	for(int i = 0; i < g.size(); i++){
		if(g[i][v] == 1){
			for(int j = 0; j < g[0].size(); j++){
				if(g[i][j] == 1 and j != v){
					if(comm[j] == -1){
						atrID(g, comm, j, id);
					}
				}
			}
		}
	}
}


int gNewman(vector<vector<int>> g, vector<int> betw, int k){
	int conex = 1;
	do{
		calcBetw(g, betw);
		removeBridge(g, betw);	// reseta a betweeness?
		conex = g.getCompConex();
	}while(conex < k)
	return g;
	// ou retorna modif?
}


//compara cada vértice (coluna)
void calcBetw(vector<vector<int>> g, vector<int> betw){
	vector<int> path;

	for(int i =0; i < g[0].size(); i++){

		for(int j = i+1; j < g[0].size(); j++){
			path = shortestPath(g, i, j);
			// is this O(n log n)?
		}

		for(int k = 0; k < path.size(); k++){
			betw[path[k]]++;
		}
	}
}

vector<int> shortestPath(vector<vector<int>> g, int vert1, int vert2){
	// Dijkstra
}

void removeBridge(vector<vector<int>> g, vector<int> betw){
	int great = 0;
	int idx = 0;
	for(int i = 0; i < betw.size(); i++){
		if(betw[i] > great){
			great = betw[i];
			idx = i;
		}
	}
	g.erase(g.begin() + idx);
	betw.erase(betw.begin() + idx);
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
	vector<int> betw = {0,0,0,0,0,0};
}
