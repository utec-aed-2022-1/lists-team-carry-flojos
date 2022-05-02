#ifndef CIRCULAR_H
#define CIRCULAR_H
#include <iostream>
#include "list.h"

// TODO: Implement all methods
template <typename T>
class CircularList : public List<T> {  
    private:
        Node<T>* head;//sentinel
        int nodes; 
    public:
        CircularList() : List<T>() { }

        ~CircularList(){
           // TODO
        }
        
        T front(){
            return head->next->data;
        }

        T back(){
            return head->prev->data;
        }            

        void push_front(T data){
            Node<T> *nuevo = new Node<T>{data};
            if (is_empty()) {
                nuevo->prev = head;
                nuevo->next = head;
                head->next = nuevo;
                head->prev = nuevo;
                head->next->data = nuevo->data;
            } else{
                Node<T>* temp = head->prev;
                nuevo->next = head->next;
                nuevo->prev = head;
                head->next->prev = nuevo;
                head->next = nuevo;

                temp->prev = head;
                head->prev = temp;
                } 
            }

        void push_back(T data){
            throw ("sin definir");
        }

        T pop_front(){
            throw ("sin definir");
        }

        T pop_back(){
            throw ("sin definir");
        }

        T insert(T data, int pos){
            throw ("sin definir");
        }

        bool remove(int pos){
            throw ("sin definir");
        }

        T& operator[](int pos){
            throw ("sin definir");
        }

        bool is_empty(){
            return (head->prev == head);
        }

        int size(){
            throw ("sin definir");
        }

        void clear(){
            throw ("sin definir");
        }
        
        void sort(){
            throw ("sin definir");
        }

        bool is_sorted(){
            throw ("sin definir");
        }

        void reverse(){
            throw ("sin definir");
        }

        std::string name(){
            return "CircularList";
        }

};

#endif