#include <string>
#include <vector>

using namespace std;

struct Node
{
    int val;
    Node *prev;
    Node *next;

    Node(int _val)
    {
        val = _val;
        prev = NULL;
        next = NULL;
    }
};

string solution(int n, int k, vector<string> cmd)
{
    string answer = string(n, 'O');
    vector<Node *> deleted;
    Node *first = new Node(0);
    Node *last = first;
    Node *cur = first;
    for (int i = 1; i < n; i++)
    {
        last->next = new Node(i);
        last->next->prev = last;
        last = last->next;
        if (i == k)
            cur = last;
    }

    for (string s : cmd)
    {
        if (s[0] == 'U')
        {
            int move = stoi(s.substr(2));
            for (int i = 0; i < move; i++)
                cur = cur->prev;
        }
        else if (s[0] == 'D')
        {
            int move = stoi(s.substr(2));
            for (int i = 0; i < move; i++)
                cur = cur->next;
        }
        else if (s[0] == 'C')
        {
            deleted.push_back(cur);
            if (cur->prev != NULL)
                cur->prev->next = cur->next;
            if (cur->next != NULL)
                cur->next->prev = cur->prev;
            cur = cur->next != NULL ? cur->next : cur->prev;
        }
        else if (s[0] == 'Z')
        {
            Node *restored = deleted.back();
            deleted.pop_back();
            if (restored->prev != NULL)
                restored->prev->next = restored;
            if (restored->next != NULL)
                restored->next->prev = restored;
        }
    }

    for (Node *node : deleted)
    {
        answer[node->val] = 'X';
    }
    return answer;
}