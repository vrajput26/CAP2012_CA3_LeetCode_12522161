class MyLinkedList {
    struct Node {
        int val;
        Node* next;

        Node(int x) {
            val = x;
            next = NULL;
        }
    };

    Node* head;
    int size;

public:
    MyLinkedList() {
        head = NULL;
        size = 0;
    }

    int get(int index) {
        if(index < 0 || index >= size)
            return -1;

        Node* temp = head;

        for(int i = 0; i < index; i++)
            temp = temp->next;

        return temp->val;
    }

    void addAtHead(int val) {
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
        size++;
    }

    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val) {
        if(index < 0)
            index = 0;

        if(index > size)
            return;

        if(index == 0) {
            addAtHead(val);
            return;
        }

        Node* temp = head;

        for(int i = 0; i < index-1; i++)
            temp = temp->next;

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }

    void deleteAtIndex(int index) {
        if(index < 0 || index >= size)
            return;

        Node* temp = head;

        if(index == 0) {
            head = head->next;
            delete temp;
        }
        else {
            for(int i = 0; i < index-1; i++)
                temp = temp->next;

            Node* del = temp->next;
            temp->next = del->next;
            delete del;
        }

        size--;
    }
};
