#ifndef FORWARD_H
#define FORWARD_H
#include <iostream>
#include "list.h"

// TODO: Implement all methods
template <typename T>
class ForwardList : public List<T> {
    private:
        Node<T>* head;
        int nodes;

    public:
        ForwardList() : List<T>() {}

        ~ForwardList(){

        }

        T front(){
            return head->data;
        }

        T back(){
            Node<T>* temp = head;
            while (temp->next!=nullptr){
                temp=temp->next;
            }
            return temp->data;
        }

        void push_front(T data){
            Node<T>* nuevo= new Node<T>; //creamos un nuevo nodo
            nuevo->data = data;
            nuevo->next = head;             // almacenamos el nuevo dato
            head = nuevo;                   // actualizamos -> el nuevo dato apunta a la cabeza
        }

        void push_back(T data){
            Node<T>* nuevo = new Node<T>{data}; //creamos un nuevo nodo
            nuevo->next = nullptr;
            if (head == nullptr){ //verifica si está vacío
                head = nuevo;
            } else {
                Node<T> *temp = head;
                while (temp->next != nullptr)
                    temp = temp->next;
                temp->next = nuevo; // apunta al nuevo nodo
            }
        }

        T pop_front(){
            if (head== nullptr) exit(0);
            Node<T>* temp = head;
            int valor = temp->data;
            head = head->next;
            delete temp;
            temp= nullptr;
            return valor;
        }

        T pop_back(){
            Node<T>* nuevo = new Node<T>; //creamos un nuevo nodo
            nuevo->next = nullptr;
            if (head->next == nullptr){ //verifica si está vacío
                delete head;
                head = nullptr;
            } else {
                Node<T> *temp = head;
                while (temp->next->next != nullptr) // me ubico 2 posiciones antes de NULL
                    temp = temp->next;
                int valor = temp->next->data;
                delete temp->next; // apunta a nullptr
                temp->next = nullptr;
                return valor;
            }
            return 0;
        }

        T insert(T data, int pos){
            if (pos==0){
                push_front(data);
            } else{
                Node<T>* nuevo= new Node<T>{data};
                Node<T>* temp= head;
                int i=0;
                while (i++<pos-1){
                    temp= temp->next;
                }
                nuevo->next = temp->next;
                temp->next = nuevo;
                return nuevo->data;
            }
            return 0;
        }

        bool remove(int pos){
            throw ("sin definir");
        }

        T& operator[](int pos){
            Node<T>* iter = head;

            for (int i = 0; i < pos; i++){
                iter = iter->next;
                }
            
            return iter->data;
        }

        bool is_empty(){
            return (head == nullptr);
        }

        int size(){
            int tamanio=0;
            while (head != nullptr){
                head = head->next;
                tamanio+=1;
            }
            return tamanio;
        }

        void clear(){
            while (head!=nullptr){
                Node<T>* temp = head; // gurado la cabecera
                head = head->next; // actualizo la cabecera
                delete temp;       // libero el nodo inicial
            }
        }

        void sort(){
            Node<T>* i, *j;
            for(i = head; i!= nullptr; i = i->next){
                for (j = i->next; j != nullptr ; j = j->next) {
                    if (i->data > j->data){
                        int temp = i->data;
                        i->data = j->data;
                        j->data = temp;
                    }
                }
            }
        }

        bool is_sorted(){
            Node<T>* temp = head;
            bool veri=true;
            if (size()==0){
                return veri;
            }else{
                for (int i = 0; i < size(); i++){
                    if (temp->next->data<temp->data){
                        veri = false;
                        break;
                    }
                }
            }
            return !veri;
        }

        void reverse(){
            throw ("sin definir");
        }

        std::string name(){
            return "ForwardList";
        }
};

#endif