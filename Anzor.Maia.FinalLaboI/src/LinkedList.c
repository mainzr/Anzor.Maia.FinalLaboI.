/*
 * LinkedList.c
 *
 *  Created on: 8 jul. 2022
 *      Author: maiam
 */

#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this->size = 0;
    	this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this) //funciona parecido a un geter
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNodo = NULL;

    if(this!=NULL && nodeIndex>=0 && nodeIndex < ll_len(this))
    {
        pNodo = this->pFirstNode;
        for(int i = nodeIndex; i > 0;  i--)
        {
            pNodo = pNodo->pNextNode;
        }
    }

    return pNodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* nuevoNodo;
    Node* anterior = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
    	nuevoNodo = (Node*) malloc(sizeof(Node)); //consigo espacio para estrucutra nodo

    	if(nuevoNodo != NULL)
    	{
    		nuevoNodo->pElement = pElement;
    		nuevoNodo->pNextNode = getNode(this, nodeIndex);

    		if(nodeIndex == 0)
    		{
    			this->pFirstNode = nuevoNodo;
    		}
    		else
    		{
    			anterior = getNode(this, nodeIndex - 1);
    			anterior->pNextNode = nuevoNodo;
    		}
    		this->size++;
        	returnAux = 0;

    	}
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	return addNode(this, ll_len(this), pElement); //crea agrega y carga pelement en linkedlist que se pase como primer parametro, agrga elemento pasdo en 3er parametro
    }

    return returnAux;
}

/** \brief Permite obtener un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNodo;


    if(this != NULL && index >= 0 && index < ll_len(this))   //ES MENOR(<) PORQUE INDICE FUNCIONA COMO ARRAY,  COMIENZA EN 0
    {
    	pNodo =  getNode(this, index);
        returnAux = pNodo->pElement;
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNodo = NULL;


    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	/*addNode(this, index, pElement);
    	returnAux = 0;*/
    	pNodo = getNode(this, index);

    	if(pNodo != NULL)
    	{
        	pNodo->pElement = pElement;
        	returnAux = 0;
    	}

    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
/*
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNodoAnterior;
    Node* pNodoSig;
    Node* pNodoActual;
    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	//pNodo = getNode(this, index);
    	//escenario 1 = con incdice 0, en primer vagon primer escenario, lado izq esta el motor lador derecho
    	// escenario 2 : izq nodos derecha nodos
    	//estando en indice 0 el valor del motor tiene que ser NULL,
    	// si se borra nodo con nodos a ambos lados, se tiene que lograr que indice 2 apunte al 3
    	pNodoAnterior = getNode(this, index - 1); //indice del nodo anterior
    	pNodoSig = getNode(this, index + 1);
    	pNodoActual = getNode(this, index);
    	if(index == 0)
    	{
    		this->pFirstNode = pNodoSig; //apunto la locomotora al nodo siguiente del que se borro.
    		free(pNodoActual); //elimino el nodo seleccionado
    		this->size--; //resto size, ya que al eliminar elemento de la lista cambio el tamaño
    	}
    	else
    	{
    		if(index >= 1)
    		{
    			pNodoAnterior->pNextNode = pNodoSig; //apunto el nodo anterior al nodo siguiente
    			free(pNodoActual); //elimino nodo seleccionado
    			this->size--; //cambio valor del tamaño de la lista
    		}
    	}
    	returnAux = 0;
    }
    return returnAux;
}*/

int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* auxFirstNode = NULL;
    Node* auxSecondNode  =NULL;
    if(this != NULL && index >=0 && index < ll_len(this) )
    {
    	auxFirstNode = getNode(this, index);

    	if (auxFirstNode != NULL)
    	{
    		if(index == 0)
    		{
    			this -> pFirstNode = auxFirstNode->pNextNode;
    			free(auxFirstNode);
    			this -> size--;
    			returnAux=0;
    		}
    		else
    		{
    			auxSecondNode = getNode (this , index - 1);

    			if(auxSecondNode != NULL)
    			{
    				auxSecondNode -> pNextNode = auxFirstNode;
    				free(auxFirstNode);
    				this -> size--;
    				returnAux=0; //repito porque funciona solo si entra aca.
    			}
    		}
    	}

    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        while(ll_len(this))
        {
           returnAux = ll_remove(this, 0);

           if(returnAux)
           {
               break;
           }
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        if(!ll_clear(this))
        {
            free(this);
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    //Node* elemento;

    if(this != NULL)
    {
    	for(int i = 0; ll_len(this); i++)
    	{
			if(ll_get(this, i) == pElement)
			{
			  returnAux = i;
			  break;
			}

    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_len(this) > 0)
    	{
    		returnAux = 0;
    	}
    	else
    		if(ll_len(this) == 0)
    		{
    			returnAux = 1;
    		}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    return addNode(this, index, pElement);
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	returnAux = ll_get(this, index);
    	ll_remove(this, index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = 0;
    	if(ll_indexOf(this, pElement) != -1)
    	{
    		returnAux = 1;
    	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* aux;

    if(this != NULL && this2 != NULL)
    {
    	returnAux = 1;
    	for(int i = 0; i < ll_len(this2); i++)
    	{
    		aux = ll_get(this2, i);

    		if(!ll_contains(this, aux))
    		{
    			returnAux = 0;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL && from < to && from >= 0 && to <= ll_len(this))
    {
    	cloneArray = ll_newLinkedList();

    	if(this != NULL)
    	{
    		for(int i = from; i < to; i++)
    		{
    			ll_add(cloneArray, ll_get(this, i));
    		}
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    //LinkedList* cloneArray = NULL;

    return ll_subList(this, 0, ll_len(this));
    //return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* aux = NULL;

    if(this != NULL && pFunc != NULL && order >= 0 && order <= 1)
    {
    	for(int i = 0; i < ll_len(this) - 1; i++)
    	{
    		for(int j =  i + 1; j < ll_len(this); j++)
    		{
    			if( (pFunc( ll_get( this, i), ll_get(this, j) ) > 0 && order) ||
    					(pFunc(ll_get(this, i), ll_get(this, j)) < 0 && !order))
    			{
    				aux = ll_get(this, i);
    				ll_set(this, i, ll_get(this, j));
    				ll_set(this, j, aux);
    			}
    		}
    	}

    	returnAux = 0;
    }


    return returnAux;

}



//funciones
LinkedList* ll_filter(LinkedList* this, int (*pFunc) (void*) )
{
	LinkedList* filterArray = NULL;
	void* aux = NULL;

	if(this != NULL && pFunc != NULL)
	{
		filterArray = ll_newLinkedList();

		if(filterArray != NULL)
		{
			for(int i = 0; i < ll_len(this); i++)
			{
				aux = ll_get(this, i);

				if(pFunc(aux ) )
				{
					if(ll_add(filterArray,aux))
					{
						ll_deleteLinkedList(filterArray);
						filterArray = NULL;
						break;
					}
				}
			}
		}
	}

	return filterArray;
}


LinkedList* ll_map(LinkedList* this, void*(*pFunc)(void* element))
{
	LinkedList* arrayList = NULL;
	void* elemento;


	if(this != NULL && pFunc != NULL)
	{
		//arrayList = ll_newLinkedList();
		//if(arrayList != NULL)
		//{
			for(int i = 0; i < ll_len(this); i++)
			{
				elemento = ll_get(this, i);

				if(elemento != NULL)
				{
					elemento = pFunc(elemento);

					if(elemento != NULL)
					{
						ll_set(this, i, elemento);
					}
				}

			}
		//}
	}

	return arrayList;

}
