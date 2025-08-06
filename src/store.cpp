#include "../headers/store.hpp"

// Здесь определения методов класса Store

template <typename T>
Store<T>::Store() { }

template <typename T>
Store<T>::Store(Node* front_, Node* end_, int size_) {
    front_ = nullptr;
    end_ = nullptr;
    size_ = nullptr;
}

template <typename T>
inline Token<T> Store<T>::get_front() { return front->token; }

template <typename T>
inline int Store<T>::get_size() { return size; }

template <typename T>
void Store<T>::push_front(Token<T> token_) {
    Node node;
    node.token = token_;

    if (get_size() == 0) {
        front = &node;
        end = &node;
    }
    else {
        Node* tmp = front;
        front = &node;
        front->next = tmp;
        tmp->prev = front;
        tmp = nullptr;
    }
    ++get_size();
}

template <typename T>
void Store<T>::push_back(Token<T> token_) {
    Node node;
    node.token = token_;

    if (get_size() == 0) {
        front = &node;
        end = &node;
    }
    else {
        Node* tmp = end;
        end = &node;
        end->prev = tmp;
        tmp->next = end;
        tmp = nullptr;
    }
    ++get_size();
}

template <typename T>
int Store<T>::pop_front() {
    Node* tmp = front;

    if (get_size() == 0) {
        error("[ERROR] There is no element to delete!\n");
        delete tmp;
        return -1;
    }
    else if (get_size() == 1) {
        front = nullptr;
        end = nullptr;
    }
    else {
        front = front->next;
        front->prev = nullptr;
    }
    delete tmp;
    --get_size();
    return 0;
}

