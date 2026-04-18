#pragma once
#include <stdexcept>
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> data;

public:
    void push(const T& value) {
        data.push_back(value);
    }

    void pop() {
        if (empty()) {
            throw std::underflow_error("Stack is empty: cannot pop");
        }
        data.pop_back();
    }

    T top() const {
        if (empty()) {
            throw std::underflow_error("Stack is empty: cannot top");
        }
        return data.back();
    }

    bool empty() const {
        return data.empty();
    }

    
    size_t size() const {
        return data.size();
    }
};
