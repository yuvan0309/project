class Stack {
    int[] items;
    int top;
  
    Stack() {
      items = new int[10];
      top = -1;
    }
  
    boolean isEmpty() {
      return top == -1;
    }
  
    boolean isFull() {
      return top == items.length - 1;
    }
  
    void push(int item) {
      if (isFull()) {
        System.out.println("Stack overflow!");
        return;
      }
      items[++top] = item;
    }
  
    int pop() {
      if (isEmpty()) {
        System.out.println("Stack underflow!");
        return -1;
      }
      return items[top--];
    }
  
    int peek() {
      if (isEmpty()) {
        System.out.println("Stack underflow!");
        return -1;
      }
      return items[top];
    }
  
    public static void main(String[] args) {
      Stack stack = new Stack();
      stack.push(10);
      stack.push(20);
      stack.push(30);
  
      System.out.println("Popped element: " + stack.pop());
      System.out.println("Top element: " + stack.peek());
  
      stack.pop();
      stack.pop();
  
      if (stack.isEmpty()) {
        System.out.println("Stack is empty.");
      }
    }
  }
  