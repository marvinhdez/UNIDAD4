#ifndef RUTA_BFS_H
#define RUTA_BFS_H
#include <limits>
#include <list>
#include <iterator>
#include "Digrafo.h"

using std::list;

class RutaBFS {
	private:
		const int INFINITO= std::numeric_limits<int>::max();
		int vertices; 
		bool *marcado;
		int *aristaHacia;
		int distanciaHacia; // distanciafacia[v]= Longitud de la ruta s-v mas corta
		void bfs(const Digrafo &G, int s); // algoritmo BFS recursiva
	public:
		RutaBFS(const Digrafo &G, int s); // constructor
		RutaBFS(const RutaBFS &otra); // copy constructor
		~RutaBFS(); // destructor	
		bool existeCasinoHacia(int v); 
		int getDistanciaHacia(int v);
		list<int> getRutaHacia(int v);
};

RutaBFS::RutaBFS(const Digrafo &G, int s) {
	vertices = G.getVertices(); 
	marcado = new bool[vertices];
	distanciaHacia = new int[vertices];
	aristaHacia = new int[vertices];

	for (int v; v<vertices; v++) { 
		marcado[v] = false; 
		distanciaHacia[v] = INFINITO;
	}
	bfs (G, s);
}

void RutaBFS::bfs(const Digrafo &G, int s) {
	list<int> q;
	marcado[s] = true; 
	distanciaHacia[s] = 0;
	q.push_back(s);
	while (!q.empty()) {
		q.pop_front ();
		int v q. front (); 
		list<int>::iterator it; 
		list<int> ady = G.getAdyascentes(v); 
		for (it = ady.begin(); it != ady.end(); it++) { 
			distanciaHacia [w] = distanciaHacia[v] + 1;
			int w = *it;
				if (!marcado [w]) {
					aristaHacia [w] = v;
					marcado [w] = true; q.push_back(w);
				}
			}
		}
	}



RutaBFS:: RutaBFS (const RutaBFS Botra) { 
	vertices otra.vertices;
	marcado= new bool[vertices]; 
	distanciaHacia new int[vertices]; 
	aristaHacia = new int [vertices];
	for (int v= 0; v < vertices; v++) { 
		marcado [v]= otra.marcado[v];
		distanciaHacia [v] = otra.distanciaHacia [v]; 
		aristaHacia[v] = otra.aristaHacia[v];
	}
}

RutaBFS::~RutaBFS () {
	delete[] marcado; delete[] distanciaHacia;
	delete[] aristaHacia;
}

bool RutabFS::existeCasinoHacia(int v) { 
	return marcado[v];
}

int RutaBFS::getDistanciaHacia(int v) {
	return distanciaHacia[v];
}

list<int> RutaBFS::getRutaHacia(int v) {
	list<int> ruta;
	if (existeCaminoHacia(v)) {
		int x;
		for (x= v; distanciaHacia[x] != 0; x = aristaHacia[x]) 
			ruta.push_front (x); 
		ruta.push_front (x);
		return ruta;
}

#endif // RUTA_BFS_H
