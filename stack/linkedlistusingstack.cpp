class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class stack()
{
private:
    node *top;

public:
    stack()
    {
        top = nullptr;
    }

    void peek()
    {
        if (top != nullptr)
            cout << "Top element is " << top->data << endl;
        else
            cout << "Stack is empty" << endl;
        return;
    }
    bool isempty()
    {
        if (top == nullptr)
        {
            return true;
        }
        return false;
    }

    int size()
    {
        int count = 0;
        node *temp = top;
        while (temp != nullptr)
        {
            count += 1;
            temp = temp->next;
        }
        return count;
    }

    void push(int val)
    {
//insertion at begining
        node *newnode = new node(val);
        if (top == nullptr)
        {
            top = newnode;
            return 0;
        }
        else
        {
            newnode->next = top;
            top = newnode;
        }
    }

    void pop()
    {
//deletion at begining
        if (top == nullptr)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        else
        {
            node *temp = top;
            top = top->next;
            delete temp;
        }
    }
}

main()
{
}