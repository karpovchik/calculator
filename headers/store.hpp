// Здесь реализуется класс Store

template <typename T>
class Store {
private:
    struct Node {
        Token<T> token;
        Node* prev;
        Node* next;
    };

    Node* front;
    Node* end;
    int size;

public:
    Store();
    Store(Node* front_, Node* end_, int size_);

    inline void push_front(Token<T> token_);
    inline void push_back(Token<T> token_);
    inline void pop_front();
    inline Token<T> get_front();
    inline int get_size();
};

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

