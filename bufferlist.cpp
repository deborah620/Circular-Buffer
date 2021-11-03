#include "bufferlist.h"
BufferList::BufferList(int minBufCapacity){
    // **************************************
    // Implement the alternative constructor
    // **************************************
    m_minBufCapacity = minBufCapacity;

    if (m_minBufCapacity < 1)
        m_minBufCapacity = DEFAULT_MIN_CAPACITY;

    m_cursor = new Buffer(m_minBufCapacity);

    m_cursor->m_next = m_cursor;

    m_listSize = 1;

}
BufferList::~BufferList(){
    clear();
}

void BufferList::clear(){
    // *****************************
    // Implement clear() function
    // *****************************
    Buffer* current = m_cursor;
    for (int i = 0; i < m_listSize; i++) {
      m_cursor = current;
      current = current->m_next;
      m_cursor->clear();
      delete m_cursor;
      m_cursor = nullptr;
    }
    m_minBufCapacity = 0;
    m_listSize = 0;
}

void BufferList::enqueue(const int& data) {
    // ****************************************************************************
    // Implement enqueue(...) function
    // we always insert at the back, that would be the cursor
    // if the current cursor is full we create a new node as cursor then we insert
    // ****************************************************************************
    try{
        m_cursor->enqueue(data);
    } catch (overflow_error &e) {
	int size = ((INCREASE_FACTOR * m_cursor->m_capacity) >= (MAX_FACTOR * m_cursor->m_capacity))
	  ? m_minBufCapacity: (INCREASE_FACTOR * m_cursor->m_capacity);
        Buffer *temp = new Buffer(size);

        temp->m_next = m_cursor->m_next;
        m_cursor->m_next = temp;
        m_cursor = temp;


        m_cursor->enqueue(data);

        m_listSize ++;
    }
}

int BufferList::dequeue() {
    // *****************************
    // Implement dequeue() function
    // *****************************
    try{
        return m_cursor->m_next->dequeue();
    } catch (underflow_error &e) {
        if (m_cursor->m_next == nullptr || m_listSize == 1)
            throw underflow_error("one node");

        Buffer *temp = m_cursor->m_next;
        m_cursor->m_next = temp->m_next;
        //might not work
        delete temp;

        m_listSize --;
        return m_cursor->m_next->dequeue();
    }

}

BufferList::BufferList(const BufferList & rhs){
    // *******************************
    // Implement the copy constructor
    // *******************************
    m_minBufCapacity = rhs.m_minBufCapacity;
    m_listSize = rhs.m_listSize;
    m_cursor = nullptr;
    
    m_cursor = new Buffer(*rhs.m_cursor);
    
    Buffer *temp = m_cursor;
    for (int i = 0; i < m_listSize - 1; i++) {
        temp->m_next = new Buffer(*rhs.m_cursor->m_next);
        temp = temp->m_next;
    }
    temp->m_next = m_cursor;
    
}

const BufferList & BufferList::operator=(const BufferList & rhs){
    // ******************************
    // Implement assignment operator
    // ******************************
    if (this != &rhs){
        clear();
        m_minBufCapacity = rhs.m_minBufCapacity;
        m_listSize = rhs.m_listSize;
        m_cursor = new Buffer(*rhs.m_cursor);
        Buffer *temp = m_cursor;
        for (int i = 0; i < m_listSize - 1; i++) {
            temp->m_next = new Buffer(*rhs.m_cursor->m_next);
            temp = temp->m_next;
        }
	temp->m_next = m_cursor;
    }
    return *this;
}

void BufferList::dump(){
    Buffer* temp = m_cursor->m_next;
    for(int i=0;i<m_listSize;i++){
        temp->dump();
        temp = temp->m_next;
        cout << endl;
    }
    cout << endl;
}
