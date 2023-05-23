#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    int size; // Добавлено поле size для хранения размера списка

public:
    LinkedList() : head(nullptr), size(0) {}

    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        size++; // Увеличиваем размер списка при добавлении элемента
    }

    T& operator[](int index) {
        Node* current = head;
        int i = 0;
        while (current) {
            if (i == index) {
                return current->data;
            }
            current = current->next;
            i++;
        }
        throw std::out_of_range("Index out of range");
    }

    LinkedList<T> operator+(const LinkedList<T>& other) const {
        LinkedList<T> result = *this;

        Node* current = other.head;
        while (current) {
            result.insert(current->data);
            current = current->next;
        }

        return result;
    }

    int getSize() const {
        return size;
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const LinkedList<U>& list);

    template <typename U>
    friend std::istream& operator>>(std::istream& is, LinkedList<U>& list);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list) {
    typename LinkedList<T>::Node* current = list.head;
    while (current) {
        os << current->data << " ";
        current = current->next;
    }
    return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, LinkedList<T>& list) {
    T value;
    while (is >> value) {
        list.insert(value);
    }
    return is;
}

#endif  // LINKLIST_H