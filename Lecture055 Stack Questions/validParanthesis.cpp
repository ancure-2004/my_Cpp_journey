bool isValidParenthesis(string s)
{
    stack<int> check;

    for (int i = 0; i < s.length(); i++)
    {

        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            check.push(ch);
        }

        else
        {

            if (!check.empty())
            {
                char top = check.top();
                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '['))
                {
                    check.pop();
                }
                else
                {
                    return false;
                }
            }

            else
            {

                return false;
            }
        }
    }

    if (check.empty())
        return true;

    else
        return false;
}