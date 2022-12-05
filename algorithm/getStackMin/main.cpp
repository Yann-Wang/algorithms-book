#include <iostream>
#include <stack>
#include <stdexcept>

using namespace std;

class Stack{
public:
    Stack() = default;
    void push(int newNum);
    int pop();
    int getMin();
private:
    stack<int> stackData;
    stack<int> stackMin;
};

void Stack::push(int newNum){
    stackData.push(newNum);
    if(stackMin.empty()){
        stackMin.push(newNum);
    }
    else if(newNum <= getMin()){
        stackMin.push(newNum);
    }
}

int Stack::pop(){
    int data = stackData.top();
    int mini = stackMin.top();
    stackData.pop();
    if(data == mini)
        stackMin.pop();

    return data;
}

int Stack::getMin(){
    if(stackMin.empty()){
        throw runtime_error("Your stack is empty.");
    }
    return stackMin.top();
}

int main()
{
    Stack st;
    st.push(3);
    cout<< st.getMin() << endl;
    st.push(2);
    cout<< st.getMin() << endl;
    st.push(4);
    cout<< st.getMin() << endl;
    st.push(1);
    cout<< st.getMin() << endl;

    return 0;
}
