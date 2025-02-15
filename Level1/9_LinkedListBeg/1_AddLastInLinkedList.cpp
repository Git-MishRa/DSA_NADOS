#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *next;
};

class linked_list
{
public:
    node *head, *tail;
    int size = 0;

public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void addLast(int n)
    {
        // Write your code here
        if (head == NULL)
        {
            head = new node();
            head->data = n;
            head->next = NULL;
            tail = head;
            size++;
        }
        else
        {
            node *last = head;
            node *nnode = new node();
            while (last->next != NULL)
            {
                last = last->next;
            }
            last->next = nnode;
            tail = nnode;
            nnode->data = n;
            nnode->next = NULL;
            size++;
        }
    }
    void display()
    {
        for (node *tmp = head; tmp != NULL; tmp = tmp->next)
        {
            cout << tmp->data << " ";
        }
    }

    void testList()
    {
        for (node *temp = head; temp != NULL; temp = temp->next)
        {
            cout << temp->data << endl;
        }
        cout << size << endl;

        if (size > 0)
        {
            cout << tail->data << endl;
        }
    }
};

int main()
{

    string str;
    linked_list l;
    while (true)
    {
        getline(cin, str);
        if (str[0] == 'q')
        {
            break;
        }
        if (str[0] == 'a')
        {
            string ss = str.substr(8, 2);
            int n = stoi(ss);
            l.addLast(n);
        }
    }

    l.testList();
    return 0;
}