#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

struct nodoS{
    int data;
    nodoS *next = nullptr;

    nodoS(int data) {
        this->data = data;
    }
};

class ListaSimple{

    int length = 0;
    nodoS *primero;

public :
    ListaSimple(){
        primero = nullptr;
    }

    void add(int p_data){
        nodoS *nuevo = new nodoS(p_data);
        if (this->primero == nullptr){
            primero = nuevo;
        }
        else{
            nodoS *temp;
            temp = primero;
            while(temp->next){
                temp = temp->next;
            }
            temp->next = nuevo;
        }
        this->length ++;
    }

    void addinPos(int dato, int pos){
        nodoS *nuevo = new nodoS(dato);
        nodoS *temp = primero;
        if(pos == 0){
            nuevo->next = primero;
            primero = nuevo;
        }
        else{
            for(int i = 0; i < pos-1; i++){
               temp = temp->next;
            }
            nuevo->next = temp->next;
            temp->next = nuevo;
        }
        this->length ++;
    }

    int* getData(int pos){
        nodoS *temp = primero;
        for(int i = 0; i < pos; i++){
            temp = temp->next;
        }
        return &temp->data;
    }

    void setData(int pos, int newData) {
        nodoS *temp = primero;
        for(int i = 0; i < pos; i++){
            temp = temp->next;
        }
        temp->data = newData;
    }

    int getLength(){
        return this->length;
    }

    bool isEmpty(){
        return this->length == 0;
    }

    void deleteNode(int pos){
        nodoS *aux = primero;
        if(pos == 0){
            primero = aux->next;
            delete(aux);
        } else {
            nodoS * prev = aux;
            for (int i = 0; i < this->length; i++) {
                if (i == pos) {
                    prev->next = aux->next;
                    delete(aux);
                    break;
                }
                prev = aux;
                aux = aux->next;
            }
        }
        this->length--;
    }
};

#endif // LISTASIMPLE_H
