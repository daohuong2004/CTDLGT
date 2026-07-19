#include <iostream>
#include <string>
using namespace std;

//===================== BAI 1 =====================

void bai1() {
    int n;
    cin >> n;

    int a[1000];

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int dem = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j])
                dem++;
        }
    }

    cout << dem;
}

//===================== BAI 2 =====================

struct Node {
    int data;
    Node *next;
};

Node* taoNode(int x) {
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

void insert(Node* &head, int pos, int x) {
    Node *p = taoNode(x);

    if (pos == 0) {
        p->next = head;
        head = p;
        return;
    }

    Node *cur = head;

    for (int i = 0; i < pos - 1; i++)
        cur = cur->next;

    p->next = cur->next;
    cur->next = p;
}

void deleteNode(Node* &head, int pos) {

    if (head == NULL) return;

    if (pos == 0) {
        Node *tmp = head;
        head = head->next;
        delete tmp;
        return;
    }

    Node *cur = head;

    for (int i = 0; i < pos - 1; i++)
        cur = cur->next;

    Node *tmp = cur->next;
    cur->next = tmp->next;
    delete tmp;
}

void bai2() {

    int n;
    cin >> n;

    Node *head = NULL;

    while (n--) {

        string s;
        cin >> s;

        if (s == "insert") {

            int p, x;
            cin >> p >> x;
            insert(head, p, x);

        } else {

            int p;
            cin >> p;
            deleteNode(head, p);

        }
    }

    Node *cur = head;

    while (cur != NULL) {
        cout << cur->data;
        if (cur->next != NULL)
            cout << " ";
        cur = cur->next;
    }
}

//===================== BAI 3 =====================

struct DNode {
    int data;
    DNode *prev;
    DNode *next;
};

void bai3() {

    int n;
    cin >> n;

    DNode *head = NULL;
    DNode *tail = NULL;

    for (int i = 0; i < n; i++) {

        DNode *p = new DNode;
        cin >> p->data;

        p->next = NULL;
        p->prev = tail;

        if (head == NULL)
            head = p;
        else
            tail->next = p;

        tail = p;
    }

    int dem = 0;

    DNode *cur = head;

    while (cur != NULL) {

        if (cur->prev != NULL && cur->next != NULL) {

            if (cur->prev->data + cur->data + cur->next->data == 0)
                dem++;

        }

        cur = cur->next;
    }

    cout << dem;
}


//===================== BAI 4 =====================

struct QNode {
    int data;
    QNode *next;
};

void bai4() {

    int n;
    cin >> n;

    QNode *front = NULL;
    QNode *rear = NULL;

    while (n--) {

        string s;
        cin >> s;

        if (s == "enqueue") {

            int x;
            cin >> x;

            QNode *p = new QNode;
            p->data = x;
            p->next = NULL;

            if (front == NULL) {
                front = rear = p;
            }
            else {
                rear->next = p;
                rear = p;
            }

        } else {

            if (front != NULL) {

                QNode *tmp = front;
                front = front->next;

                if (front == NULL)
                    rear = NULL;

                delete tmp;
            }
        }
    }

    QNode *cur = front;

    while (cur != NULL) {
        cout << cur->data;
        if (cur->next != NULL)
            cout << " ";
        cur = cur->next;
    }
}

//===================== BAI 5 =====================

struct SNode {
    int data;
    SNode *next;
};

void push(SNode *&top, int x) {

    SNode *p = new SNode;
    p->data = x;
    p->next = top;
    top = p;
}

void pop(SNode *&top) {

    if (top != NULL) {

        SNode *tmp = top;
        top = top->next;
        delete tmp;
    }
}

void bai5() {

    int n;
    cin >> n;

    SNode *top = NULL;

    while (n--) {

        string s;
        cin >> s;

        if (s == "push") {

            int x;
            cin >> x;
            push(top, x);

        } else {

            pop(top);

        }
    }

    if (top == NULL)
        return;

    int a[1000];
    int cnt = 0;

    while (top != NULL) {

        a[cnt++] = top->data;

        SNode *tmp = top;
        top = top->next;
        delete tmp;
    }

    for (int i = cnt - 1; i >= 0; i--) {

        cout << a[i];

        if (i != 0)
            cout << " ";
    }
}


int main() {

    int choice;
    cout << "Nhap bai (1-5): ";
    cin >> choice;

    switch (choice) {

    case 1:
        bai1();
        break;

    case 2:
        bai2();
        break;

    case 3:
        bai3();
        break;
            case 4:
        bai4();
        break;

    case 5:
        bai5();
        break;
    }

    return 0;
}
