#include<iostream>
#include<stack>
using namespace std;

void display_stack(stack<string> st) {

  while(!st.empty()) {
    cout << st.top();
    st.pop();
    if(st.empty())
        cout<<".";
    else
        cout<<", " ;
  }
}

int main(){
    stack <string> colors;
    // adding element in stack
    colors.push("Purple");
    colors.push("Pink");
    colors.push("Black");
    colors.push("Red");
    colors.push("Orange");
    colors.push("Blue");

    cout << "Initial Stack: ";
    // print elements of stack
    display_stack(colors);

    cout<<endl;
    cout<<endl;
    cout << "The size of the stack beforing Poping: "<<colors.size();
    cout<<endl;
    // the blue will be pop out of the stack
    colors.pop();
    cout<<"After poping: ";
    display_stack(colors);

    cout<<endl;
    cout<<"The color at the top is :"<<colors.top();

    cout<<endl;
    
    cout << "the size of the stack after poping: "<<colors.size();
    return 0;
}