#ifndef STACK_H
#define STACK_H
struct Element
{
 Element( int x, Element *y): data(x), next(y) {}
 Element( int x): data(x){}
 Element *next;
 int data;
};
class Stack
{
private:
 Element *first;
public:
 Stack(): first(0) {}
 void Push(int x)
 {
 if(first != 0)
 first = new Element(x, first);
 else
 first = new Element(x);
 }
 int Pop()
 {
 if(first != 0)
 {
 int el = (*first).data;
 first = (*first).next;
 return el;
 }
 return -1;
 }
};

#endif // STACK_H
