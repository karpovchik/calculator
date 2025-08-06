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
    inline int pop_front();
    inline Token<T> get_front();
    inline int get_size();
};
