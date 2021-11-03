#include "buffer.h"

Buffer::Buffer(int capacity){
    // **************************************
    // Implement the alternative constructor
    // No need to set m_next to nullptr, 
    // it will be handled by linked list,
    // because it is used by linked list
    // **************************************
    m_capacity = 0;

    if (capacity > 0) {
        m_buffer = new int[capacity];
        m_capacity = capacity;
    }
    m_count = 0;
    m_start = 0;
    m_end = 0;
}

void Buffer::clear(){
    // ***********************************
    // Implement clear() function
    // No need to set m_next to nullptr, 
    // it will be handled by linked list,
    // because it is used by linked list
    // ***********************************
    if (m_capacity > 0) {
        delete [] m_buffer;
        m_buffer = nullptr;
    }
    m_capacity = 0;
    m_count = 0;
    m_start = 0;
    m_end = 0;
}

Buffer::~Buffer(){
    clear();
}

int Buffer::count(){return m_count;}

int Buffer::capacity(){return m_capacity;}

bool Buffer::full(){
    // **************************
    // Implement full() function
    // **************************
    if (m_start == 0 && m_end == m_capacity) {
        return true;
    }
    return false;
}

bool Buffer::empty(){
    // **************************
    // Implement empty() function
    // **************************
    if (m_start == m_end)
        return true;
    return false;
}

void Buffer::enqueue(int data){
    // ********************************
    // Implement enqueue(...) function
    // ********************************
    if (full())
        throw overflow_error("full");

    else{
        m_buffer[m_end] = data;
        m_end++;
        m_count++;
    }
}

int Buffer::dequeue(){
    // *****************************
    // Implement dequeue() function
    // *****************************
    if (empty())
        throw underflow_error("empty");
    else {
        m_start ++;
        m_count--;
        return  m_buffer[m_start - 1];
    }
}

Buffer::Buffer(const Buffer & rhs){
    // *******************************
    // Implement the copy constructor
    // *******************************
    m_capacity = rhs.m_capacity;
    m_count = rhs.m_count;
    m_start = rhs.m_start;
    m_end = rhs.m_end;

    if (m_capacity > 0) {
	m_buffer = new int[m_capacity];

        for (int i = 0; i < m_count; i++) {
            m_buffer[i] = rhs.m_buffer[i];
        }
    }
}

const Buffer & Buffer::operator=(const Buffer & rhs){
    // ******************************
    // Implement assignment operator
    // ******************************
    if (this != &rhs){
      if (m_capacity > 0)
        clear();

      m_capacity = rhs.m_capacity;
      m_count = rhs.m_count;
      m_start = rhs.m_start;
      m_end = rhs.m_end;

      if (m_capacity > 0){
        m_buffer = new int[m_capacity];
	//m_buffer = rhs.m_buffer;

        for (int i = 0; i < m_count; i++) {
	  m_buffer[i] = rhs.m_buffer[i];
        }
      }

    }
  return *this;
}

void Buffer::dump(){
    int start = m_start;
    //int end = m_end;
    int counter = 0;
    cout << "Buffer size: " << m_capacity << " : ";
    if (!empty()){
        while(counter < m_count){
            cout << m_buffer[start] << "[" << start << "]" << " ";
            start = (start + 1) % m_capacity;
            counter++;
        }
        cout << endl;
    }
    else cout << "Buffer is empty!" << endl;
}
