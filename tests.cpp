#include <gtest/gtest.h>
#include "Stack.h"

TEST(StackTest, PushAndTop) {
    Stack<int> stack;
    stack.push(42);
    EXPECT_EQ(stack.top(), 42);
    EXPECT_EQ(stack.size(), 1);
    
    stack.push(100);
    EXPECT_EQ(stack.top(), 100);
    EXPECT_EQ(stack.size(), 2);
}

TEST(StackTest, PopReducesSize) {
    Stack<std::string> stack;
    stack.push("first");
    stack.push("second");
    EXPECT_EQ(stack.size(), 2);
    
    stack.pop();
    EXPECT_EQ(stack.size(), 1);
    EXPECT_EQ(stack.top(), "first");
    
    stack.pop();
    EXPECT_EQ(stack.size(), 0);
    EXPECT_TRUE(stack.empty());
}

TEST(StackTest, TopOnEmptyThrows) {
    Stack<double> stack;
    EXPECT_THROW(stack.top(), std::underflow_error);
    
    stack.push(3.14);
    EXPECT_NO_THROW(stack.top());
    stack.pop();
    EXPECT_THROW(stack.top(), std::underflow_error);
}

TEST(StackTest, PopOnEmptyThrows) {
    Stack<char> stack;
    EXPECT_THROW(stack.pop(), std::underflow_error);
    
    stack.push('A');
    EXPECT_NO_THROW(stack.pop());
    EXPECT_THROW(stack.pop(), std::underflow_error);
}

TEST(StackTest, EmptyOnNewStack) {
    Stack<int> stack;
    EXPECT_TRUE(stack.empty());
    EXPECT_EQ(stack.size(), 0);
    
    stack.push(1);
    EXPECT_FALSE(stack.empty());
    
    stack.pop();
    EXPECT_TRUE(stack.empty());
}

TEST(StackTest, ConstTop) {
    Stack<int> stack;
    stack.push(5);
    const Stack<int>& constRef = stack;
    EXPECT_EQ(constRef.top(), 5);
}

TEST(StackTest, MultipleTypes) {
    Stack<int> intStack;
    intStack.push(10);
    EXPECT_EQ(intStack.top(), 10);
    
    Stack<std::string> strStack;
    strStack.push("hello");
    EXPECT_EQ(strStack.top(), "hello");
}

TEST(StackTest, ConstTopOnEmptyThrows) {
    Stack<int> stack;
    const Stack<int>& constRef = stack;
    EXPECT_THROW(constRef.top(), std::underflow_error);
}

TEST(StackTest, DoubleType) {
    Stack<double> stack;
    stack.push(3.14);
    stack.push(2.71);
    EXPECT_EQ(stack.top(), 2.71);
    stack.pop();
    EXPECT_EQ(stack.top(), 3.14);
}
