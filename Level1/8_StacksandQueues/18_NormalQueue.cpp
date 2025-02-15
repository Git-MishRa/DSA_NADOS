#include <iostream>
#include <exception>
using namespace std;

class CustomQueue
{
public:
    int *arr;
    int sizeQ;
    int front;
    int arrSize;

    CustomQueue(int cap)
    {
        sizeQ = 0;
        front = 0;
        arr = new int[cap];
        arrSize = cap;
    }

    int size()
    {
        // write your code here
        return sizeQ;
    }

    void add(int data)
    {
        // write your code here
        if (sizeQ == arrSize)
        {
            cout << "Queue overflow" << endl;
        }
        else
        {
            int rear = (front + sizeQ) % arrSize; // queue accepts input till its full, so we will be using circular array(not literally)
            arr[rear] = data;
            sizeQ++;
        }
    }

    int peek()
    {
        // write your code here
        if (sizeQ == 0)
        {
            cout << "Queue underflow" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    int remove()
    {
        // write your code here
        if (sizeQ == 0)
        {
            cout << "Queue underflow" << endl;
            return -1;
        }
        else
        {
            int val = arr[front];
            front = (front + 1) % arrSize;
            sizeQ--;
            return val;
        }
    }

    void display()
    {
        // write your code here
        for (int i = 0; i < sizeQ; i++)
        {
            int idx = (front + i) % arrSize;
            cout << arr[idx] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cin >> n;
    CustomQueue q(n);
    string str;
    cin >> str;

    while (str != "quit")
    {
        if (str == "add")
        {
            int val;
            cin >> val;
            q.add(val);
        }
        else if (str == "remove")
        {
            int val = q.remove();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if (str == "peek")
        {
            int val = q.peek();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if (str == "size")
        {
            cout << q.size() << endl;
        }
        else if (str == "display")
        {
            q.display();
        }
        cin >> str;
    }
    return 0;
}