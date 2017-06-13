#include <iostream>
//#include <cmath>
#include <vector>
//#include <algorithm>
//#include <iomanip>
using namespace std;
using std::vector;


void atrID(vector<vector<int> > &g, vector<int> &comm, int v, int id){

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

int getCompConex(vector<vector<int> > &g, vector<int> &comm){
	/*Busca em Profundidade!*/
	int vert, id = 0;
	for(vert = 0; vert < g[0].size(); vert++){
		comm.push_back(-1);
	}
	for(vert = 0; vert < g[0].size(); vert++)
		if(comm[vert] == -1)
			atrID(g, comm, vert, id++);		
}

vector<int> shortestPath(vector<vector<int> > g, int vert1, int vert2){
	// Dijkstra
	vector<int> dist, prev, Q;

	for(int i = 0; i < g[0].size(); i++){
		dist.push_back(-1);
		Q.push_back(i);
	}
	dist[vert1] = 0;

	int u, d = 0;
	while (Q.size() != 0){
		d = -1;
		for(int i = 0; i< Q.size(); i++){
			if((dist[i] <= d and dist[i] != -1) or d ==-1){
				d = dist[i];
				u = Q[i];
			}
		}

		for(int i = 0; i < Q.size(); i++){
			if(Q[i] == u){
				Q.erase(Q.begin() + i);
			}
		}

		//Procura adjacentes
		int alt;
		cout << Q.size() << endl;
	
		//Arestas de u
		for(int i = 0; i < g.size(); i++){
			if(g[i][u] == 1){
				for(int j = 0; j < g[0].size(); j++){
					//Outra ponta da aresta
					if(g[i][j] == 1 and j != u){
						//Ainda está em Q
						for(int k = 0; k < Q.size(); k++){
							if(j == Q[k]){
								alt = dist[u] + 1;
								if(alt < dist[j]){
									dist[j] = alt;
									prev.push_back(i);
								}
								break;
							}
						}

					}
					break;
				}
			}
		}
	}
	return prev;
}

void removeBridge(vector<vector<int> > g, vector<int> betw){
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


//compara cada vértice (coluna)
void calcBetw(vector<vector<int> > g, vector<int> betw){
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
void rec_friends(vector <int> cc, vector<vector<int> > g){
	for(int i = 0; i < cc.size(); i ++)
		for(int j = i+1; j < cc.size(); j++)
			if(cc[i] == cc[j])
				for(int k = 0 ; k < g.size;()k++){
					if(g[k][i]==g[k][j]){
						break;
					}
					else{
						cout <<"Pessoa " << i << " e pessoa " << j << " poderiam se tornar boas amigas!" << endl;
					}
				}
}

vector<vector<int> >  gNewman(vector<vector<int> > g, vector<int> betw, int k, vector<int> comm){
	int conex = 1;
	do{
		calcBetw(g, betw);
		removeBridge(g, betw);	// reseta a betweeness?
		conex = getCompConex(g,comm);
	}while(conex < k);
	return g;
	// ou retorna modif?
}
int main(int argc, char const *argv[]) {
	vector<int> cc;
	int blah[][5] = {
		{ 1, 0, 0, 1, 0},
		{ 0, 0, 1, 0, 1},
		{ 0, 1, 1, 0, 0},
		{ 1, 0, 0, 0, 1},
		}; 

	vector<vector<int> > g ;
	for(int i = 0; i < 4; i++){
		vector<int> temp;
		for(int j = 0; j < 5; j++){
			temp.push_back(blah[i][j]);
		}
		g.push_back(temp);
	}
	vector <int> dist = shortestPath(g,1,2);
	for(int i = 0;i < dist.size();i++){
		cout << dist[i] << endl;
	}
}
