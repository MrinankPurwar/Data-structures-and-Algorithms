Prefix To Infix Using Stack:

Algorithm:
1. Read the Prefix expression in reverse order (from right to left)
2. If the symbol is an operand, then push it onto the Stack
3. If the symbol is an operator, then pop two operands from the Stack 
4. Create a string by concatenating the two operands and the operator between them. 
5. string = (operand1 + operator + operand2) 
6. And push the resultant string back to Stack
7. Repeat the above steps until end of Prefix expression.

Code:
bool isOperator(char x) {
  switch (x) {
  case '+':
  case '-':
  case '/':
  case '*':
    return true;
  }
  return false;
}
 
// Convert prefix to Infix expression
string preToInfix(string pre_exp) {
  stack<string> s;
 
  // length of expression
  int length = pre_exp.size();
 
  // reading from right to left
  for (int i = length - 1; i >= 0; i--) {
 
    // check if symbol is operator
    if (isOperator(pre_exp[i])) {
 
      // pop two operands from stack
      string op1 = s.top();   s.pop();
      string op2 = s.top();   s.pop();
 
      // concat the operands and operator
      string temp = "(" + op1 + pre_exp[i] + op2 + ")";
 
      // Push string temp back to stack
      s.push(temp);
    }
 
    // if symbol is an operand
    else {
 
      // push the operand to the stack
      s.push(pre_exp[i]);
    }
  }
 
  // Stack now contains the Infix expression
  return s.top();
}
 
int main() {
  string pre_exp = "*-A/BC-/AKL";
  cout << "Infix : " << preToInfix(pre_exp);
  return 0;
}