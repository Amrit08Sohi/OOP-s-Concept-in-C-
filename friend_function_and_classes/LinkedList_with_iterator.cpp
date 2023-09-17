// Using friend class
#include<bits/stdc++.h>
using namespace std;
class List; // Forward declaration of class List
class Node; // Forward declaration of class Node
class Iterator {
    List* list;  // current list
    Node* node; // currend node
    public:
        Iterator() : node(0),list(0) {}
        void begin(List *);
        bool end();
        void next();
        int data();
};



class List {
    Node *head, *tail;
    public:
        List(Node* h=0) : head(h),tail(h) {}
        void append(Node *);
        friend class Iterator; // so that it can access private members of class List
};

class Node {
    Node *next;
    int info;
    public:
        Node(int i) : info(i), next(0) {}
        friend class List; // so that it can access private members of class Node
        friend class Iterator; // so that it can access private members of class Node
};

void Iterator::begin(List *l) {
    list = l;
    node = l->head;
}

bool Iterator::end() {
    return node == 0;
}

void Iterator::next() {
    node = node->next;
}

int Iterator::data() {
    return node->info;
}
void List::append(Node *newNode)  {
    if(!head) {
        head = tail = newNode;
        return;
    } else {
        tail->next = newNode;
        tail = tail->next;
    }
}
int main()
{
    List l;
    Node n1(1), n2(2), n3(3);
    l.append(&n1);
    l.append(&n2);
    l.append(&n3);
    Iterator i;
    for(i.begin(&l); !i.end(); i.next()) {
        cout << i.data() << " ";
    }
    return 0;
}

// Without using friend class
// #include<bits/stdc++.h>
// using namespace std;
// class List; // Forward declaration of class List
// class Node; // Forward declaration of class Node
// class Iterator {
//     List* list;  // current list
//     Node* node; // currend node
//     public:
//         Iterator() : node(0),list(0) {}
//         void begin(List *);
//         bool end();
//         void next();
//         int data();
// };
// class List {
//     Node *head, *tail;
//     public:
//         List(Node* h=0) : head(h),tail(h) {}
//         void append(Node *);
//         Node* getHead() {
//             return head;
//         }
//         Node* getTail() {
//             return tail;
//         }

// };

// class Node {
//     Node *next;
//     int info;
//     public:
//         Node(int i) : info(i), next(0) {}
//         Node* getNext() {
//             return next;
//         }
//         int getData() {
//             return info;
//         }
//         void setNext(Node* t) {
//            this->next = t;   
//         }
// };

// void Iterator::begin(List *l) {
//     list = l;
//     node = l->getHead();
// }

// bool Iterator::end() {
//     return node == 0;
// }

// void Iterator::next() {
//     node = node->getNext();
// }

// int Iterator::data() {
//     return node->getData();
// }
// void List::append(Node *newNode)  {
//     if(!head) {
//         head = tail = newNode;
//         return;
//     } else {
//         tail->setNext(newNode);
//         tail = tail->getNext();
//     }
// }
// int main()
// {
//     List l;
//     Node n1(1), n2(2), n3(3);
//     l.append(&n1);
//     l.append(&n2);
//     l.append(&n3);
//     Iterator i;
//     for(i.begin(&l); !i.end(); i.next()) {
//         cout << i.data() << " ";
//     }
//     return 0;
// }