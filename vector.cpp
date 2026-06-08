/*
 * Data Structure - defined by a collection of data, the relationships among
 * them, and the functions and operations that can be applied to them
 *
 * Queue - FIFO linear data structure that allows for reterival elements in the
 * same order as they are inserted
 *
 * Interface to provide
 *  - Push (enqueues elements to the back of the queue)
 *  - Pop (dequeues elements from the front of the queue)
 *  - isEmpty or isFull (checks if queue is empty or full)
 *  - Peek (look at element at the beginning of the queue)
 *  - Rear (look at elemet at the back of the queue)
 *  - Size (stored as count in the container)
 *
 * API Design:
 * - When trying to return when empty can return bool or value, or could throw
 *   an error
 * - std::optional to check if value was given
 * - depends if want to handle gracefull or want to halt program if this happens
 *
 *
 * Ways to Implement a Queue
 * - Circular Buffer - allow elements to loop off the end of the array to the
 * beginning, and can support efficient operations on the front and end of the
 * queue Memory: O(n) for the capacity of elements Time: O(1) for enqueue and
 * dequeue, O(n) for enqueue if reallocation is necessary Amortized: O(1) Memory
 * Locality: Array or Vector as underlying backing for the structure holds
 * elements in contingous memory so with memory accesses it can pull in
 * additional data surrounding it and store it in cache
 *
 * - Singly Linked List - stores elements as Node struct with the specific
 * element and pointer to the next Node - element are added to the tail and
 * removed from the head Memory: O(n) for capacity of elements as Node - has
 * additional metadata (has to store next pointer) Time: O(1) for insertion and
 * removal (for insertion if we store tail pointer) Memory Locality: Nodes are
 * stores in differnt locations of memory, so the Nodes aren't stored
 *   contingously, and to access the next pointer you require an additional
 * memory access
 *
 * - Two Stacks - treat one stack as front of the queue and another stack as the
 * back of the queue, Memory: O(n) but uses two stacks to store all elements
 *   Time: O(1) for insertion and size, O(n) for removal and Peek in worst case,
 * O(n) for resizing Amortized: O(1) Memory Locality: Touches more memory than a
 * circular buffer because on dequeues may have to touch another stack that may
 * not be stored contingously, and requires another memory access
 *
 * Edge Cases:
 * - Empty queue operations
 * - Full queue behavior
 * - Circular Buffer wraparound
 * - Zero or one capacity
 *
 * Concurrency:
 * - Should protect around the queue using a lock not thread safe
 *   Conditional variable if want blocking/waiting behavior
 *   SPSC, MPSC, SPMC, MPMC
 * - Producer - consumer if full - and trying to enqueue either block until
 * somthing is removed or reject request
 * - If trying to dequeue when full - either block until something is added or
 * reject request
 * - Best for low latency - SPSC ring buffer, using atomics for head and tail
 *   Current implementations are not thread-safe.
 *   Concurrent enqueue/dequeue require synchronization to avoid data races.
 *   Design depends on whether the queue is SPSC, MPSC, SPMC, or MPMC.
 *   For a simple correct implementation, use a mutex.
 *   For low-latency systems, an SPSC bounded ring buffer with atomics is often
 * preferred. Ring buffers are attractive because they avoid allocation and have
 * strong cache locality. Need to think about acquire/release ordering,
 * contention, and false sharing. Linked-list lock-free queues are harder due to
 * memory reclamation.
 *
 * Unbounded vs Bounded:
 * - When it becomes full, allocate a larger array, copy elements, then reset
 * head and tail
 *   - double size
 * - Can also deallocate when less than a quarter of elements occupy the array
 * - Use the linked list approach and can just keep enqueuing to the tail
 * pointer
 *
 */

#include <algorithm> // Required for std::copy
#include <iostream>
#include <memory> // Required for std::unique_ptr

template <typename T> class MyVector {
private:
  std::unique_ptr<T[]> arr; // Smart pointer manages the heap array
  size_t capacity;
  size_t current;

  // Internal helper to handle reallocations
  void grow() {
    capacity = (capacity == 0) ? 1 : capacity * 2;
    auto new_arr = std::make_unique<T[]>(capacity);

    // Move or copy existing elements to the new block
    for (size_t i = 0; i < current; ++i) {
      new_arr[i] = std::move(arr[i]);
    }

    arr = std::move(new_arr); // Transfer ownership to the member pointer
  }

public:
  MyVector() : capacity(0), current(0), arr(nullptr) {}

  // Add element
  void push_back(const T &value) {
    if (current == capacity) {
      grow();
    }
    arr[current++] = value;
  }

  // Access elements
  T &operator[](size_t index) { return arr[index]; }
  const T &operator[](size_t index) const { return arr[index]; }

  size_t size() const { return current; }
  size_t get_capacity() const { return capacity; }

  // Rule of Three (Modern Style)
  // 1. Destructor: Implicitly handled by unique_ptr!

  // 2. Copy Constructor: Must perform a deep copy
  MyVector(const MyVector &other)
      : capacity(other.capacity), current(other.current) {
    arr = std::make_unique<T[]>(capacity);
    std::copy(other.arr.get(), other.arr.get() + current, arr.get());
  }

  // 3. Copy Assignment
  MyVector &operator=(MyVector other) {
    std::swap(arr, other.arr);
    std::swap(capacity, other.capacity);
    std::swap(current, other.current);
    return *this;
  }
};
