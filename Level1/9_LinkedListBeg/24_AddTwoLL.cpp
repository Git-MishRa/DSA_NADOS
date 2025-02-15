#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data = 0;
    Node *next = nullptr;

    Node(int data)
    {
        this->data = data;
    }
};

class linkedlist
{

public:
    Node *head = nullptr;
    Node *tail = nullptr;
    int size = 0;

    // basic->============================================

    int size_()
    {
        return this->size;
    }

    bool isEmpty()
    {
        return this->size == 0;
    }

    string toString()
    {
        Node *curr = this->head;
        string sb = "";

        while (curr != nullptr)
        {
            sb += to_string(curr->data);
            if (curr->next != nullptr)
                sb += " ";
            curr = curr->next;
        }
        return sb;
    }

    // add->===============================================
private:
    void addFirstNode(Node *node)
    {
        if (this->head == nullptr)
        {
            this->head = node;
            this->tail = node;
        }
        else
        {
            node->next = this->head;
            this->head = node;
        }

        this->size++;
    }

public:
    void addFirst(int val)
    {
        Node *node = new Node(val);
        addFirstNode(node);
    }

public:
    void addLastNode(Node *node)
    {
        if (this->head == nullptr)
        {
            this->head = node;
            this->tail = node;
        }
        else
        {
            this->tail->next = node;
            this->tail = node;
        }

        this->size++;
    }

    void addLast(int val)
    {
        Node *node = new Node(val);
        addLastNode(node);
    }

    void addNodeAt(Node *node, int idx)
    {
        if (idx == 0)
            addFirstNode(node);
        else if (idx == this->size)
            addLastNode(node);
        else
        {
            Node *prev = getNodeAt(idx - 1);
            Node *curr = prev->next;

            prev->next = node;
            curr->next = node;

            this->size++;
        }
    }

    void addAt(int data, int idx)
    {
        if (idx < 0 || idx > this->size)
        {
            throw("invalidLocation: " + to_string(idx));
        }

        Node *node = new Node(data);
        addNodeAt(node, idx);
    }

    // remove->============================================
    Node *removeFirstNode()
    {
        Node *node = this->head;
        if (this->size == 1)
        {
            this->head = nullptr;
            this->tail = nullptr;
        }
        else
        {
            this->head = this->head->next;
            node->next = nullptr;
        }

        this->size--;
        return node;
    }

    int removeFirst(int val)
    {
        if (this->size == 0)
        {
            throw("nullptrPointerException: -1");
        }

        Node *node = removeFirstNode();
        int rv = node->data;
        delete node;
        return rv;
    }

    Node *removeLastNode()
    {
        Node *node = this->tail;
        if (this->size == 1)
        {
            this->head = nullptr;
            this->tail = nullptr;
        }
        else
        {
            Node *prev = getNodeAt(this->size - 2);
            this->tail = prev;
            prev->next = nullptr;
        }

        this->size--;
        return node;
    }

    int removeLast(int val)
    {
        if (this->size == 0)
        {
            throw("nullptrPointerException: -1");
        }

        Node *node = new Node(val);
        int rv = node->data;
        delete node;
        return rv;
    }

    Node *removeNodeAt(int idx)
    {
        if (idx == 0)
            return removeFirstNode();
        else if (idx == this->size - 1)
            return removeLastNode();
        else
        {

            Node *prev = getNodeAt(idx - 1);
            Node *curr = prev->next;

            prev->next = curr->next;
            curr->next = nullptr;

            this->size--;
            return curr;
        }
    }

    int removeAt(int idx)
    {
        if (idx < 0 || idx >= this->size)
        {
            throw("invalidLocation: " + idx);
        }

        Node *node = removeNodeAt(idx);
        int rv = node->data;
        delete node;
        return rv;
    }

    // get->================================================
    Node *getFirstNode()
    {
        return this->head;
    }

    int getFirst()
    {
        if (this->size == 0)
        {
            throw("nullptrPointerException: -1");
        }

        Node *node = getFirstNode();
        return node->data;
    }

    Node *getLastNode()
    {
        return this->tail;
    }

    int getLast()
    {
        if (this->size == 0)
        {
            throw("nullptrPointerException");
        }

        Node *node = getLastNode();
        return node->data;
    }

    Node *getNodeAt(int idx)
    {
        Node *curr = this->head;

        while (idx-- > 0)
        {
            curr = curr->next;
        }

        return curr;
    }

    int getAt(int idx)
    {
        if (idx < 0 || idx >= this->size)
        {
            throw("invalidLocation: " + idx);
        }

        Node *node = getNodeAt(idx);
        return node->data;
    }
};

Node *getMid(Node *head, Node *tail)
{
    Node *slow = head, *fast = head;
    while (fast->next != tail && fast->next->next != tail)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

// merge two sorted linkedlist
linkedlist mergeTwoSortedLists(linkedlist l1, linkedlist l2)
{
    linkedlist ans;
    Node *one = l1.head;
    Node *two = l2.head;

    while (one != nullptr && two != nullptr)
    {
        if (one->data < two->data)
        {
            ans.addLast(one->data);
            one = one->next;
        }
        else
        {
            ans.addLast(two->data);
            two = two->next;
        }
    }
    while (one != nullptr)
    {
        ans.addLast(one->data);
        one = one->next;
    }
    while (two != nullptr)
    {
        ans.addLast(two->data);
        two = two->next;
    }

    return ans;
}

linkedlist mergeSort(Node *head, Node *tail)
{
    if (head == tail)
    {
        linkedlist base;
        base.addLast(head->data);
        return base;
    }

    Node *mid = getMid(head, tail);
    linkedlist fsh = mergeSort(head, mid);
    linkedlist ssh = mergeSort(mid->next, tail);

    return mergeTwoSortedLists(fsh, ssh);
}
int addTwoListsHelper(Node *one, int pv1, Node *two, int pv2, linkedlist *res)
{
    if (one == NULL && two == NULL)
    {
        return 0;
    }

    // vars
    int data;

    // if place value is not same, no addition, just adding the extra elements to the list
    if (pv1 > pv2)
    {
        int oc = addTwoListsHelper(one->next, pv1 - 1, two, pv2, res);
        data = one->data + oc;
    }
    else if (pv2 > pv1)
    {
        int oc = addTwoListsHelper(one, pv1, two->next, pv2 - 1, res);
        data = two->data + oc;
    }

    // only in the same pv's we can actually add
    else
    {
        int oc = addTwoListsHelper(one->next, pv1 - 1, two->next, pv2 - 1, res);
        data = one->data + two->data + oc;
    }

    // setting up the data to be inserted and to be carried forward
    int ndata = data % 10;
    int nc = data / 10;

    // adding to the linkedlist
    res->addFirst(ndata);
    return nc;
}

linkedlist addTwoLists(linkedlist one, linkedlist two)
{
    // write your code here
    // result linkedlist
    linkedlist res;

    int oc = addTwoListsHelper(one.head, one.size, two.head, two.size, &res);
    // edge case if the carry results in a number greater than either list
    // eg 999+1==1000
    if (oc > 0)
    {
        res.addFirst(oc);
    }

    return res;
}

linkedlist makeList()
{
    linkedlist l;
    int n1;
    cin >> n1;

    for (int i = 0; i < n1; i++)
    {
        int val;
        cin >> val;
        l.addLast(val);
    }
    return l;
}

int main()
{
    linkedlist l = makeList();
    linkedlist m = makeList();
    int a;
    cin >> a;
    int b;
    cin >> b;
    linkedlist res = addTwoLists(l, m);
    cout << l.toString() << endl;
    cout << m.toString() << endl;
    cout << res.toString() << endl;
    res.addFirst(a);
    res.addLast(b);
    cout << res.toString() << endl;
    return 0;
}