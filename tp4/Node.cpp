#include "Node.h"

template <typename T>
Node<T>::Node(const T& data) : data(data), next(nullptr) {}

template <typename T>
T Node<T>::getData() const {
    return data;
}

template <typename T>
void Node<T>::setData(const T& newData) {
    data = newData;
}

template <typename T>
Node<T>* Node<T>::getNext() const {
    return next;
}

template <typename T>
void Node<T>::setNext(Node* newNext) {
    next = newNext;
}