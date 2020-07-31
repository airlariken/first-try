//  main.cpp
//  draft
//  Copyright © 2020 awsl. All rights reserved.
#include <iostream>
#include <string>
using namespace std;

struct Lnode
{
    int data;
    Lnode* next;
};
using Link = Lnode *;

Link& l_insert(Link& s,int n_data, int pos)
{
    Link p = s;
    for (int i = 0; i<pos; ++i)
    {
        p = p->next;
    }
    Link n_link = new Lnode;
    n_link->data = n_data;
    n_link->next = p->next;
    p->next = n_link;
    return s;
}

Link& l_delete(Link& s, int pos)
{
    Link p = s;
    for (int i = 0; i<pos-1; ++i)
        p = p->next;
    Link temp = p->next;
    p->next = temp->next;
    delete temp;
    return s;
}

int getlength(const Link& s)
{
    Link p = s;
    int count = 0;
    
    while (p->next != nullptr)
    {
        ++count;
        p = p->next;
    }
 
    return count;
}

int l_search(const Link& s,int s_data)
{
    Link p = s;
    for(int i = 0;i<getlength(s);++i)
    {
        p = p->next;
        if (p->data == s_data)
            return i+1;
    }
    return 0;
}



int main(int argc, const char * argv[])
{
    Link m_link = new Lnode;
    m_link->next = nullptr;
    l_insert(m_link, 23, 0);
    l_insert(m_link, 58, 1);
    l_insert(m_link, 99, 2);
    cout<<getlength(m_link)<<endl;
    cout<<l_search(m_link,58)<<endl;
    
    return 0;
}
