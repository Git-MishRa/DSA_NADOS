#include <iostream>
#include <string>
#include <stack>

using namespace std;

class MinStack
{
    stack<int> data;
    int minVal;

public:
    int size()
    {
        // write your code here
        if (!data.empty())
        {
            return data.size();
        }
        else
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
    }

public:
    void push(int val)
    {
        // write your code here
        if (data.empty())
        {
            minVal = val;
            data.push(val);
        }
        else if (val >= minVal)
        {
            data.push(val);
        }
        else
        {
            data.push(val + val - minVal);
            minVal = val;
        }
    }

public:
    int pop()
    {
        // write your code here
        if (data.empty())
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        else
        {
            int val = data.top();
            if (val >= minVal)
            {
                data.pop();
                return val;
            }
            else
            {
                int mval = minVal;
                minVal = 2 * mval - val;
                data.pop();
                return mval;
            }
        }
    }

public:
    int top()
    {
        // write your code here
        if (data.empty())
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        else
        {
            if (data.top() >= minVal)
            {
                return data.top();
            }
            else
            {
                return minVal;
            }
        }
    }

public:
    int min()
    {
        // write your code here
        if (data.empty())
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        else
        {
            return minVal;
        }
    }
};

int main()
{
    MinStack st;

    string str;
    cin >> str;

    while (str != "quit")
    {

        if (str == "push")
        {
            int val;
            cin >> val;
            st.push(val);
        }
        else if (str == "pop")
        {
            int val = st.pop();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if (str == "top")
        {
            int val = st.top();
            if (val != -1)
            {
                cout << val << endl;
            }
        }
        else if (str == "size")
        {
            cout << st.size() << endl;
        }
        else if (str == "min")
        {
            int val = st.min();
            if (val != -1)
            {
                cout << val << endl;
            }
        }

        cin >> str;
    }
}