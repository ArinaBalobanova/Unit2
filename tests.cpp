#include <gtest/gtest.h>
#include "Stack.h"

// Тест 1: push + top возвращает правильное значение
TEST(StackTest, PushAndTopReturnsCorrectValue) {
    Stack<int> stack;
    
    stack.push(42);
    EXPECT_EQ(stack.top(), 42);
    EXPECT_EQ(stack.size(), 1);
    
    stack.push(100);
    EXPECT_EQ(stack.top(), 100);
    EXPECT_EQ(stack.size(), 2);
    
    stack.push(999);
    EXPECT_EQ(stack.top(), 999);
    EXPECT_EQ(stack.size(), 3);
}

// Тест 2: pop уменьшает размер
TEST(StackTest, PopDecreasesSize) {
    Stack<std::string> stack;
    
    stack.push("first");
    stack.push("second");
    stack.push("third");
    
    EXPECT_EQ(stack.size(), 3);
    
    stack.pop();
    EXPECT_EQ(stack.size(), 2);
    EXPECT_EQ(stack.top(), "second");
    
    stack.pop();
    EXPECT_EQ(stack.size(), 1);
    EXPECT_EQ(stack.top(), "first");
    
    stack.pop();
    EXPECT_EQ(stack.size(), 0);
    EXPECT_TRUE(stack.empty());
}

// Тест 3: top на пустом стеке, std::underflow_error
TEST(StackTest, TopOnEmptyStackThrowsUnderflowError) {
    Stack<double> stack;
    
    EXPECT_THROW(stack.top(), std::underflow_error);
    
    stack.push(3.14);
    EXPECT_NO_THROW(stack.top());
    EXPECT_EQ(stack.top(), 3.14);
    
    stack.pop();
    EXPECT_THROW(stack.top(), std::underflow_error);
}

// Тест 4: pop на пустом стеке, std::underflow_error
TEST(StackTest, PopOnEmptyStackThrowsUnderflowError) {
    Stack<char> stack;
    
    EXPECT_THROW(stack.pop(), std::underflow_error);
    
    stack.push('A');
    EXPECT_NO_THROW(stack.pop());
    
    EXPECT_THROW(stack.pop(), std::underflow_error);
}

// Тест 5: empty() = true для нового стека
TEST(StackTest, EmptyReturnsTrueForNewStack) {
    Stack<int> stack;
    
    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.size(), 0);
    
    stack.push(42);
    EXPECT_FALSE(stack.empty());
    EXPECT_EQ(stack.size(), 1);
    
    stack.pop();
    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.size(), 0);
}

// Тест на работу с разными типами данных
TEST(StackTest, WorksWithDifferentDataTypes) {
    
    Stack<bool> boolStack;
    boolStack.push(true);
    EXPECT_TRUE(boolStack.top());
    boolStack.push(false);
    EXPECT_FALSE(boolStack.top());
    
    Stack<double> doubleStack;
    doubleStack.push(3.14159);
    EXPECT_DOUBLE_EQ(doubleStack.top(), 3.14159);
}

// Тест на константный доступ
TEST(StackTest, ConstTopWorksCorrectly) {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    
    const Stack<int>& constStack = stack;
    EXPECT_EQ(constStack.top(), 20);
    EXPECT_EQ(constStack.size(), 2);
    EXPECT_FALSE(constStack.empty());
}

// Тест на последовательные push/pop
TEST(StackTest, MultiplePushPopSequence) {
    Stack<int> stack;
    
    for (int i = 0; i < 100; ++i) {
        stack.push(i);
        EXPECT_EQ(stack.top(), i);
        EXPECT_EQ(stack.size(), i + 1);
    }
    
    for (int i = 99; i >= 0; --i) {
        EXPECT_EQ(stack.top(), i);
        EXPECT_EQ(stack.size(), i + 1);
        stack.pop();
    }
    
    EXPECT_TRUE(stack.empty());
}

// Тест на проверку, что top() не удаляет элемент
TEST(StackTest, TopDoesNotRemoveElement) {
    Stack<int> stack;
    stack.push(42);
    
    EXPECT_EQ(stack.top(), 42);
    EXPECT_EQ(stack.size(), 1);
    
    EXPECT_EQ(stack.top(), 42);
    EXPECT_EQ(stack.size(), 1);
}

