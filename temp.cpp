#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
struct arrStack{
    int top;
    int capacity;
    int * arr;
};
arrStack * make_stack(int cap){
    arrStack * stack = new arrStack;
    stack->top = -1;
    stack->capacity = cap;
    stack->arr = new int[stack->capacity];
    cout<<"Stack has been created of size "<<cap<<endl;
    return stack;
}
bool isFull(arrStack * stack){
    if (stack->top == stack->capacity -1)
    {
        return 1;
    }
    return 0;
}
bool isEmpty(arrStack * stack){
    if (stack->top == -1)
    {
         return 1;
    }
    return 0;
    
}
void push( arrStack * stack , int value){
    if (isFull(stack))
    {
           cout<<"Stack Overflow"<<endl;
    }
    else{
        stack->top++;
        stack->arr[stack->top] = value;
    }
    
}
int pop (arrStack * stack){
    if (isEmpty(stack))
    {
        cout<<"Stack Underflow"<<endl;
        return -1;
    }
    else{
        int i = stack->arr[stack->top];
        stack->top--;
        return i;
    }
    
}
int main()
{
    arrStack * s;
    int a;
    cout<<"Enter the size of the stack"<<endl;
    cin>>a;
    s = make_stack (a);
    for (int i = 0; i < s->capacity ; i++)
    {
        cout<<"Enter the value of the "<<i<<" element"<<endl;
        cin>>a;
        push(s , a);
    }
    cout<<endl;
    for (int i = s->capacity-1; i >= 0 ; i--)
    {
        cout<<pop(s)<<endl;
    }
    
    
    
    
    return 0;
}