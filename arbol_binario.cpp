#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct node{
     int nro;
     struct node *left, *right;
};

typedef struct node *leaf;
/* es un puntero de tipo node que hemos llamado leaf, que ulitizare
   para mayor facilidad de creacion de variables */

leaf crearnode(int x)
{
     leaf nuevonode = new(struct node);
     nuevonode->nro = x;
     nuevonode->left = NULL;
     nuevonode->right = NULL;

     return nuevonode;
}
void insertar(leaf &arbol, int x)
{
     if(arbol==NULL)
     {
           arbol = crearnode(x);
     }
     else if(x < arbol->nro)
          insertar(arbol->left, x);
     else if(x > arbol->nro)
          insertar(arbol->right, x);
}


void verArbol(leaf arbol, int n)
{
     if(arbol==NULL)
          return;
     verArbol(arbol->right, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< arbol->nro <<endl;

     verArbol(arbol->left, n+1);
}

int main()
{
    leaf arbol = NULL;   // creado Arbol

    int n;  // numero de nodos del arbol
    int x; // elemento a insertar en cada nodo

    cout << "\n\t\t  ..[ ARBOL BINARIO ]..  \n\n";

    cout << " Numero de nodos del arbol:  ";
    cin >> n;
    cout << endl;

    for(int i=0; i<n; i++)
    {
        cout << " Numero del Nodo " << i+1 << ": ";
        cin >> x;
        insertar( arbol, x);
    }

    cout << "\n Mostrando ARBOL \n\n";
    verArbol( arbol, 0);


    cout << endl << endl;

    system("pause");
    return 0;
}
