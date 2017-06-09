
	//de acordo com o pseudo não precisa recalcular o num de caminhos novamente
	//é assim mesmo?
int gNewman(Graph g, int k){
	int conex = 1;
	do{
	countPaths(g);
	removeBridge(g);	//reseta os pesos tbm?
	conex = g.getCompConex();
	}while(conex < k)
	return g; 	//ou a gente cria um grafo q é cópia do inicial
				// e retorna ele modificado?
}

void countPaths(Graph g){
	for(int i =0; i < g.vSize(); i++){
		for(int j = i+1; j < g.vSize(); j++){
			shortestPath(g, i, j);	//adiciona às arestas internamente ou aqui fora?
			//is this O(n log n)?
		}
	}
}

//Ao criar o graph tem q settar todos pesos pra 0
void removeBridge(Graph g){
	int great = 0;
	int idx = 0;
	for(int i = 0; i < g.eSize(); i++){
		eWeight = g.edg(i).weight();
		if(eWeight > great){
			great = eWeight;
			idx = i;
		}
	}
	g.remEdg(idx);
}
//Em algumas implementações ele remove arestas de pesos iguais ao mesmo tempo.