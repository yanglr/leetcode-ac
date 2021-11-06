#include <iostream>
#include <queue>
#include <vector>
#include <assert.h>
#include <algorithm>
using namespace std;

class Iterator {
    const vector<int>* nums;
    int index;
public:
    Iterator(const vector<int>& nums) {
        this->nums = &nums;
        this->index = 0;
    }
    Iterator(const Iterator& iter);
    
    // Returns the next element in the iteration.
    int next() {
        return (*nums)[index++];
    }
    
    // Returns true if the iteration has more elements.
    bool hasNext() const {
        return index < (*nums).size();
    }
};

class PeekingIterator : public Iterator {
private:
    int nextElement;
    bool flag;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
        flag = Iterator::hasNext();
        if (flag) {
            nextElement = Iterator::next();
        }
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        return nextElement;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        int ret = nextElement;
        flag = Iterator::hasNext();
        if (flag) {
            nextElement = Iterator::next();
        }
        return ret;
	}
	
	bool hasNext() const {
        return flag;
	}
};

// Test
int main()
{
    /** 用gcc/g++编译, 需要用这种方式初始化vector:
    */
    int a[3] = {1, 2, 3};
    vector<int> nums(a, a + 3);

    PeekingIterator peekingIterator(nums);
    assert(1 == peekingIterator.next());
    assert(2 == peekingIterator.peek());
    assert(2 == peekingIterator.next());
    assert(3 == peekingIterator.next());
    assert(!peekingIterator.hasNext());
    
    cout << "OK~" << endl;
    
    return 0;
}