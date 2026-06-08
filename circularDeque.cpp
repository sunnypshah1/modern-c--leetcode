/*
 * Data Structure - defined by a collection of data, the relationships among
 * them, and the functions and operations that can be applied to them
 *
 * Deque - linear data structure (aka double ended queue) that allows for
 * efficient additions and removals at both sides of the container
 *
 * Interface to provide
 *  - push_front (push elements to the front of container)
 *  - pop_front (pops elements from the front of container)
 *  - push_back (push elements to the back of the container)
 *  - pop_back (pops elememts from the back of the container)
 *  - isEmpty or isFull (checks if container is empty or full)
 *  - Peek (look at element at the beginning of the container)
 *  - Rear (look at elemet at the back of the container)
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
 * - Doubly Linked List - stores elements as Node struct with the specific
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

#include <optional>
#include <stdexcept>
#include <vector>

template <typename T> class CircularDeque {
public:
  CircularDeque(size_t capacity) : data_(capacity), head_(0), size_(0) {
    if (capacity == 0) {
      throw std::invalid_argument("Capacity must be greater than 0");
    }
  }

  bool pushFront(const T &value) {
    if (isFull()) {
      return false;
    }
    head_ = (head_ + capacity() - 1) % capacity();
    data_[head_] = value;
    ++size_;
    return true;
  }

  bool pushBack(const T &value) {
    if (isFull()) {
      return false;
    }
    size_t tail = (head_ + size_) % capacity();
    data_[tail] = value;
    ++size_;
    return true;
  }

  std::optional<T> popFront() {
    if (isEmpty()) {
      return std::nullopt;
    }
    T value = data_[head_];
    head_ = (head_ + 1) % capacity();
    --size_;
    return value;
  }

  std::optional<T> popBack() {
    if (isEmpty()) {
      return std::nullopt;
    }
    size_t tailIndex = (head_ + size_ - 1) % capacity();
    T value = data_[tailIndex];
    --size_;
    return value;
  }

  std::optional<T> peekFront() const {
    if (isEmpty()) {
      return std::nullopt;
    }
    return data_[head_];
  }

  std::optional<T> peekBack() const {
    if (isEmpty()) {
      return std::nullopt;
    }
    size_t tailIndex = (head_ + size_ - 1) % capacity();
    return data_[tailIndex];
  }

  bool isEmpty() const { return size_ == 0; }

  bool isFull() const { return size_ == capacity(); }

  size_t size() const { return size_; }

  size_t capacity() const { return data_.size(); }

private:
  std::vector<T> data_;
  size_t head_; // index of the front element
  size_t size_; // number of stored elements
};
