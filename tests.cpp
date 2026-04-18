#include <gtest/gtest.h>
#include "Stack.h"

TEST(StackTest, PushAndTop) {
    Stack<int> stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    EXPECT_EQ(stack.top(), 30);
    EXPECT_EQ(stack.size(), 3);
}

TEST(StackTest, PopDecreasesSize) {
    Stack<std::string> stack;
    stack.push("first");
    stack.push("second");
    stack.push("third");
    
    EXPECT_EQ(stack.size(), 3);
    
    stack.pop();
    EXPECT_EQ(stack.size(), 2);
    
    stack.pop();
    EXPECT_EQ(stack.size(), 1);
    
    EXPECT_EQ(stack.top(), "first");
}

TEST(StackTest, TopOnEmptyThrowsUnderflowError) {
    Stack<double> stack;
    
    EXPECT_THROW(stack.top(), std::underflow_error);
    
    // Добавим и удалим, чтобы убедиться, что после этого снова ошибка
    stack.push(3.14);
    stack.pop();
    
    EXPECT_THROW(stack.top(), std::underflow_error);
}


TEST(StackTest, PopOnEmptyThrowsUnderflowError) {
    Stack<char> stack;
    
    EXPECT_THROW(stack.pop(), std::underflow_error);
    
    stack.push('A');
    stack.pop();
    
    EXPECT_THROW(stack.pop(), std::underflow_error);
}

TEST(StackTest, EmptyReturnsTrueForNewStack) {
    Stack<int> stack;
    
    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.size(), 0);
    
    stack.push(42);
    EXPECT_FALSE(stack.empty());
    
    stack.pop();
    EXPECT_TRUE(stack.empty());
}

TEST(StackTest, WorksWithDifferentTypes) {
    Stack<bool> boolStack;
    boolStack.push(true);
    EXPECT_TRUE(boolStack.top());
    
    Stack<int*> ptrStack;
    int x = 5;
    ptrStack.push(&x);
    EXPECT_EQ(*ptrStack.top(), 5);
}
