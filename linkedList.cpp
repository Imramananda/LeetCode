#include<iostream>
using namespace std;
struct node
{
    int val;
    node* next;
    node() : val = 0 , next = nullptr {}
    node(int x) : val =x, next

    ~node() { delete next ;}
}