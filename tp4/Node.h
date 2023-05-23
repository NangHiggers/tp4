#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
private:
    T data;
    Node* next;

public:
    Node(const T& data);

    T getData() const;
    void setData(const T& newData);

    Node* getNext() const;
    void setNext(Node* newNext);
};

#endif  // NODE_H