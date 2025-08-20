#include "help_funcs.hpp"

// Здесь реализуется класс Store

class Store {
private:
    struct Node {
        Token token;
        Node* prev;
        Node* next;
    };

    Node* front;
    Node* end;
    int size;

public:
    Store();
    
    inline void push_front(Token& token_);
    inline void push_back(Token& token_);
    inline void pop_front();
    inline Token get_front();
    inline int get_size();
    inline void inc_size();
    inline void dec_size();
};

Store::Store() {
    front = nullptr;
    end = nullptr;
    size = 0;
}

inline Token Store::get_front() { return front->token; }

inline int Store::get_size() { return size; }

inline void Store::inc_size() { ++size; }

inline void Store::dec_size() { --size; }

void Store::push_front(Token& token_) {
    Node* node = new Node;
    node->token = token_;

    if (get_size() == 0) {
        front = node;
        end = node;
    }
    else {
        Node* tmp = front;
        front = node;
        front->next = tmp;
        tmp->prev = front;
        tmp = nullptr;
    }
    inc_size();
}

void Store::push_back(Token& token_) {
    Node* node = new Node;
    node->token = token_;

    if (get_size() == 0) {
        front = node;
        end = node;
    }
    else {
        Node* tmp = end;
        end = node;
        end->prev = tmp;
        tmp->next = end;
        tmp = nullptr;
    }
    inc_size();
}

void Store::pop_front() {
    Node* tmp = front;

    if (get_size() == 0) {
        error("[ERROR] There is no element to delete!\n");
        delete tmp;
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
    dec_size();
}

