#ifndef DIGRAFO_H
#define	DIGRAFO_H

#include <list>
#include <iterator>
#include <iostream>

using std::list;
using std::cout;
using std::endl;

class Digrafo {
	private:
		int vertices;
		int aristas;
		list<int> *adyascentes;
	public:
		Digrafo();
		Digrafo(const Digrafo &otro);
		~Digrafo();
		int getVertices() const;
		void setVertices(int vertices);
		int getAristas() const;
		list<int> getAdyascentes(int v) const;
		void agregarArista(int v, int w);
		void imprimir();		
};

Digrafo::Digrafo() : vertices(0), aristas(0), adyascentes(nullptr){
	
}

Digrafo::Digrafo(const Digrafo &otro){
	vertices = otro.vertices;
	aristas = otro.aristas;
	if(vertices == 0){
		adyascentes = nullptr;
	}
	else{
		adyascentes = new list<int>[vertices];
		for(int i=0; i<vertices; i++){
			list<int>::iterator it;
			for(it = otro.adyascentes[i].begin(); it != otro.adyascentes[i].end(); it++)
				adyascentes[i].push_back(*it);
		}
	}
}

Digrafo::~Digrafo() {
	if(adyascentes != nullptr){
		delete[] adyascentes;
	}
}

int Digrafo::getVertices() const{
	return vertices;
}

void Digrafo::setVertices(int vertices) {
	if(this->vertices == 0){
		this->vertices = vertices;
		adyascentes = new list<int>[vertices];
	}
}

int Digrafo::getAristas() const{
	return aristas;
}

void Digrafo::agregarArista(int v, int w){
	adyascentes[v].push_front(w);
	aristas++;
}

void Digrafo::imprimir() {
	for(int i=0; i<vertices; i++){
		cout << i << ": ";
		list<int>::iterator it;
		for (it = adyascentes[i].begin(); it!=adyascentes[i].end(); it++)
			cout << *it << " ";
		cout << endl;	
	}
}

#endif //!DIGRAFO_H
