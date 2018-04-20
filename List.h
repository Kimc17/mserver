//Recuperado de http://mygnet.net/codigos/cplusplus/apis/lista_dinamica_generica_utilizando_templates.766

#if !defined Nodo_h
#define Nodo_h
#include <iostream>


using namespace std;

template<class t_data>
class Nodo
{
    t_data data;
    Nodo *nextNodo;

public:
    Nodo() { nextNodo = NULL; }
    Nodo(t_data data);
    t_data element() { return data; }
    Nodo *next() { return nextNodo; }
    void setElement(t_data data) { this->data = data; }
    void insert(Nodo *element) { nextNodo = element; }
};


template<class t_data>
Nodo<t_data>::Nodo(t_data data)
{
    this->data = data;
    nextNodo = NULL;
}

#endif

#if !defined Lista_h
#define Lista_h

template<class t_data>
class List
{
    Nodo<t_data> *list;
    int size;

public:

    List() { list = NULL; size = 0; }
    List(t_data data);
    void Add(int ncells);
    int isEmpty() { return (list == NULL); }
    void Insert(t_data data);
    t_data Get(int index);
    void addAt(t_data data, int index);
    void Delete(int index);
    long length() { return size; }
    ~List();
};

#endif

template<class t_data>
List<t_data>::List(t_data data)
{
    list = new Nodo<t_data>(data);
    size++;
}
//Reserva espacio en la list para tantos elementos
//como indique el parametro nceldas, y acutaliza la
//variable size
template<class t_data>
void List<t_data>::Add(int nceldas)
{
    Nodo<t_data> *temp;
    int i = 0;

    if(isEmpty())
    {//si la list esta vacia inserto el nodo vacio en la primera posicion
        Nodo<t_data> *nodo = new Nodo<t_data>();
        list = nodo;
        i++;
        size++;
    }
    for(; i<nceldas; i++)
    {
        Nodo<t_data> *nodo = new Nodo<t_data>();
        temp = list;
        //como la list no esta vacia avanzo hasta la ultima posicion e inserto el nodo vacio
        while(temp->next())
            temp = temp->next();
        temp->insert(nodo);
        size++;
    }
}

template<class t_data>
void List<t_data>::Insert(t_data data)
{
    Nodo<t_data> *nodo = new Nodo<t_data>(data);
    Nodo<t_data> *temp = list;

    if(isEmpty())
    {
        cout << "Empty list" << endl;
        list = nodo;
    }
    else
    {
        while(temp->next())
            temp = temp->next();
        temp->insert(nodo);
    }
    size++;
}

template<class t_data>
t_data List<t_data>::Get(int index)
{
    int i=0;
    Nodo<t_data> *nodo = list;

    if(!isEmpty())
    {
        if(size < index)
        {
            cout << "ERROR: Index is major than the size of list";

        }
        while((i<index) && (nodo))
        {
            nodo = nodo->next();
            i++;
        }
        return (nodo->element());

    }
    cout << "Empty list" << endl;

}

template<class t_data>
void List<t_data>::Delete(int index)
{
    int i=0;
    Nodo<t_data> *nodo = list,*prev=list;

    if(!isEmpty())
    {
        if(index == 0)
            list = list->next();
        while((i<index) && (nodo))
        {
            prev = nodo;
            nodo = nodo->next();
        }
        if(nodo)
            prev->insert(nodo->next());
        delete(nodo);
        size--;
    }
}
template<class t_data>
void List<t_data>::addAt(t_data data, int index) {
    Nodo<t_data> *temp = list;
    if(isEmpty()) {
        cout << "Empty list" << endl;
    }else {
        for (int i = 0; i < index; ++i) {
            temp = temp->next();
        }
        temp->setElement(data);
    }
}

template<class t_data>
List<t_data>::~List()
{
    while(!isEmpty())
        Delete(0);
    size = 0;
}

