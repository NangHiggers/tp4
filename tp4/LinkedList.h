#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
private:
    template <typename U>
    class Node {
    private:
        U data;
        Node<U>* next;

    public:
        Node(const U& data) : data(data), next(nullptr) {}
        U getData() const { return data; }
        Node<U>* getNext() const { return next; }
        void setNext(Node<U>* next) { this->next = next; }
    };

    Node<T>* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}
    ~LinkedList();

    void insert(const T& data);
    void clear();
    int getSize() const;

    T operator[](int index) const;

    LinkedList<T> operator+(const LinkedList<T>& other) const;
};

template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

template <typename T>
void LinkedList<T>::insert(const T& data) {
    Node<T>* newNode = new Node<T>(data);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node<T>* current = head;
        while (current->getNext() != nullptr) {
            current = current->getNext();
        }
        current->setNext(newNode);
    }
    size++;
}

template <typename T>
void LinkedList<T>::clear() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* next = current->getNext();
        delete current;
        current = next;
    }
    head = nullptr;
    size = 0;
}

template <typename T>
int LinkedList<T>::getSize() const {
    return size;
}

template <typename T>
T LinkedList<T>::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("Invalid index");
    }
    Node<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->getNext();
    }
    return current->getData();
}

template <typename T>
LinkedList<T> LinkedList<T>::operator+(const LinkedList<T>& other) const {
    LinkedList<T> newList(*this); // Create a copy of the current list

    Node<T>* current = other.head;
    while (current != nullptr) {
        newList.insert(current->getData()); // Insert each element from the other list into the new list
        current = current->getNext();
    }

    return newList;
}

#endif  // LINKEDLIST_H