#include <iostream>
using namespace std;

template <typename T>
class MyDeck {
private:
    class Node {
    public:
        T item;
        Node* next;
        Node* prev;
        Node(T item = T(), Node *next = nullptr, Node* prev = nullptr) {
            this->item = item;
            this->next = next;
            this->prev = prev;
        }
    };
    Node* head;
    Node* tail;
    int Size;
    
public:
    MyDeck() : Size(0), head(nullptr), tail(nullptr) {}
    
    ~MyDeck() {
        while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_back(T item) {
        Node *newNode = new Node(item, nullptr, tail);
        if (tail == nullptr) {
            tail = newNode;
            head = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        Size++;
    }
    
    void pop_back() {
        if (tail != nullptr) {
            Node *temp = tail;
            tail = tail->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            }
            else {
                head = nullptr;
            }
            delete temp;
            Size--;
        }
        else {
            cout << "Fail" << endl;
        }
    }
    
    void push_front(T item) {
        Node *newNode = new Node(item, head);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            head->prev = newNode;
            head = newNode;
        }
        Size++;
    }
    
    void pop_front() {
        if (head != nullptr) {
            Node *temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr;
            }
            delete temp;
            Size--;
        }
        else {
            cout << "Fail" << endl;
        }
    }
    
    int size() {
        return Size;
    }
    
    friend ostream& operator<<(ostream& os, const MyDeck<T>& deck) {
        Node* current = deck.head;
        while (current != nullptr) {
            os << current->item << " ";
            current = current->next;
        }
        return os;
    }
};

int main() {
    MyDeck<int> deck;
    deck.push_back(6);
    deck.push_back(856);
    deck.push_front(65);
    cout << "Size: " << deck.size() << endl;
    cout << "Deck: " << deck << endl;
    deck.pop_back();
    deck.pop_front();
    cout << "Size: " << deck.size() << endl;
    cout << "Deck: " << deck << endl;
    return 0;
}
