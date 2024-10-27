void inesrtAtbottom(stack<int> &s, int x)
{

    if (s.empty())
    {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    inesrtAtbottom(s, x);

    s.push(num);
}

void reverseStack(stack<int> &stack)
{

    if (stack.empty())
    {
        return;
    }

    int num = stack.top();
    stack.pop();

    reverseStack(stack);

    inesrtAtbottom(stack, num);
}