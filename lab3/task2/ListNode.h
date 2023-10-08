#include <iostream>

using namespace std;

template <typename T>
class ListNode {
public:
    T val;
    ListNode* next;

    ListNode() : val(T()), next(nullptr) {}
    ListNode(T value) : val(value), next(nullptr) {}
};
