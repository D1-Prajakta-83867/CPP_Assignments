#include <iostream>
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> elements;
    size_t capacity;

public:
    // Constructor
    Stack(size_t capacity) : capacity(capacity) {}

    // Push element onto the stack
    void push(const T& item) {
        if (isFull()) {
            std::cerr << "Stack overflow!\n";
            return;
        }
        elements.push_back(item);
    }

    // Pop element from the stack
    T pop() {
        if (isEmpty()) {
            std::cerr << "Stack underflow!\n";
            exit(1);
        }
        T popped = elements.back();
        elements.pop_back();
        return popped;
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return elements.empty();
    }

    // Check if the stack is full
    bool isFull() const {
        return elements.size() == capacity;
    }
};

// Example class for demonstration
class Box {
private:
    double length, width, height;

public:
    Box(double l, double w, double h) : length(l), width(w), height(h) {}
    
    double volume() const {
        return length * width * height;
    }
};

int main() {
    // Testing Stack<int>
    Stack<int> intStack(5);
    for (int i = 1; i <= 5; ++i) {
        intStack.push(i * 10);
    }
    while (!intStack.isEmpty()) {
        std::cout << "Popped: " << intStack.pop() << std::endl;
    }

    // Testing Stack<double>
    Stack<double> doubleStack(3);
    doubleStack.push(3.14);
    doubleStack.push(6.28);
    doubleStack.push(9.42);
    while (!doubleStack.isEmpty()) {
        std::cout << "Popped: " << doubleStack.pop() << std::endl;
    }

    // Testing Stack<Box>
    Stack<Box> boxStack(2);
    Box box1(1.0, 2.0, 3.0);
    Box box2(2.0, 3.0, 4.0);
    boxStack.push(box1);
    boxStack.push(box2);
    while (!boxStack.isEmpty()) {
        Box poppedBox = boxStack.pop();
        std::cout << "Popped Box Volume: " << poppedBox.volume() << std::endl;
    }

    return 0;
}
