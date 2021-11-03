#include "bufferlist.h"
class Tester{
    public:
    bool BufferEnqueueDequeue(Buffer &buffer, int dataCount);
    bool BufferEnqueueFull(int size);
    bool BufferCopyConstructor(const Buffer &buffer);
    bool BufferConstructor(const Buffer &buffer, int size);
    bool BufferAssignmentOperator(const Buffer &buffer, int size);
    bool BufferDequeueEmpty(int size);

    void BufListEnqueuePerformance(int numTrials, int N);
    bool BufferListEnqueueDequeue(BufferList &buffer, int dataCount);
    bool BufferListCopyConstructor(BufferList &bufferList, int dataCount);
    bool BufferListAssignmentOperator(const BufferList &bufferList, int size);
    bool BufferListDeleteLastNode(int size);
};
int main(){
    Tester tester;
    int bufferSize = 1000;
    Buffer buffer(bufferSize);
    {
        //testing insertion/removal for 1 data item
        //Buffer aBuffer(bufferSize);
        cout << "\nTest case: Buffer class: Inserting/removing 1 data item:\n";
        if (tester.BufferEnqueueDequeue(buffer, 1))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }	    
    {
        //testing insertion/removal for half data size
        //Buffer bBuffer(bufferSize);
        cout << "\nTest case: Buffer class: Inserting/removing half data size:\n";
        if (tester.BufferEnqueueDequeue(buffer, bufferSize/2))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    {
        //testing insertion/removal for full data size
      //when I remove this line of code, whole program crashes
        Buffer cBuffer(bufferSize);
        cout << "\nTest case: Buffer class: Inserting/removing full data size:\n";
        if (tester.BufferEnqueueDequeue(cBuffer, bufferSize))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    {
        //testing insertion in a full buffer
        cout << "\nTest case: Buffer class: Throwing exception while inserting in full buffer:\n";
        if (tester.BufferEnqueueFull(1000))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    {
        //testing removing in an empty buffer
        cout << "\nTest case: Buffer class: Throwing exception while removing in an empty buffer:\n";
        if (tester.BufferDequeueEmpty(1000))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    {
        //testing Buffer constructor, 0
        cout << "\nTest case: Buffer class: Constructor, buffer size 0:\n";
        Buffer buffer(0);
        if (tester.BufferConstructor(buffer, 0))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    {
        //testing Buffer constructor, neg num
        cout << "\nTest case: Buffer class: Constructor, negative buffer size:\n";
        Buffer buffer(-10);
        if (tester.BufferConstructor(buffer, -10))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    {
        //testing Buffer class copy constructor with buffer size less than zero
        cout << "\nTest case: Buffer class: Copy constructor, negative buffer size:\n";
        Buffer buffer(-10);
        if (tester.BufferCopyConstructor(buffer))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n"; 
    }
    {
        //testing Buffer class copy constructor with regular buffer size
        cout << "\nTest case: Buffer class: Copy constructor, normal buffer size:\n";
        Buffer buffer(100);
        if (tester.BufferCopyConstructor(buffer))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    {
        //testing Buffer class copy constructor with buffer size 0
        cout << "\nTest case: Buffer class: Copy constructor, buffer size 0:\n";
        Buffer buffer(0);
        if (tester.BufferCopyConstructor(buffer))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    {
        //testing Buffer class assignment operator with buffer size less than zero
        cout << "\nTest case: Buffer class: Assignment operator, negative buffer size:\n";
        Buffer buffer(-10);
        if (tester.BufferAssignmentOperator(buffer, 5))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    {
        //testing Buffer class assignment operator with regular buffer size
        cout << "\nTest case: Buffer class: Assignment operator, normal buffer size:\n";
        Buffer buffer(100);
        if (tester.BufferAssignmentOperator(buffer, 5))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    {
        //testing Buffer class assignment operator with buffer size 0
        cout << "\nTest case: Buffer class: Assignment operator, buffer size 0:\n";
        Buffer buffer(0);
        if (tester.BufferAssignmentOperator(buffer, 5))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    int bufferListSize = 5;
    {
        //testing insertion/removal for 1 node of data (so one full buffer)
        BufferList bufferList(bufferListSize);
        cout << "\nTest case: Buffer List class: Inserting/removing 1 node of data:\n";
        if (tester.BufferListEnqueueDequeue(bufferList, 1))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    {
        //testing insertion/removal for half data size
        BufferList aBufferList(bufferListSize);
        cout << "\nTest case: Buffer List class: Inserting/removing half data size:\n";
        if (tester.BufferListEnqueueDequeue(aBufferList, bufferListSize/2))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    {
        //testing insertion/removal for full data size
        BufferList bBufferList(bufferListSize);
        cout << "\nTest case: Buffer List class: Inserting/removing full data size:\n";
        if (tester.BufferListEnqueueDequeue(bBufferList, bufferListSize))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    {
        //testing insertion/removal for 2 arrays worth of data
        BufferList cBufferList(bufferListSize);
        cout << "\nTest case: Buffer List class: Inserting/removing 2 arrays worth of data:\n";
        if (tester.BufferListEnqueueDequeue(cBufferList, bufferListSize * 2))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    {
        //testing insertion/removal for 1 node of data with 0 buffer list capacity
        BufferList bufferList(0);
        cout << "\nTest case: Buffer List class: Inserting/removing 1 node of data with 0 buffer list capacity:\n";
        if (tester.BufferListEnqueueDequeue(bufferList, 1))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    {
        //testing removal last node
        BufferList bufferList(0);
        cout << "\nTest case: Buffer List class: Try to remove last node:\n";
        if (tester.BufferListDeleteLastNode(1))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    {
        //testing Buffer List class copy constructor with buffer size less than zero, one node
        cout << "\nTest case: Buffer List class: copy constructor with buffer size less than zero:\n";
        BufferList bufferList(1);
        if (tester.BufferListCopyConstructor(bufferList, 1))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    {
        //testing Buffer List class copy constructor with 0 buffer size, one node
        cout << "\nTest case: Buffer List class: copy constructor with 0 buffer size:\n";
        BufferList bufferList(0);
        if (tester.BufferListCopyConstructor(bufferList, 1))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
	    }
    {
        //testing Buffer List class copy constructor with regular buffer size, one node
        cout << "\nTest case: Buffer List class: copy constructor with regular buffer size:\n";
        BufferList bufferList(10);
        if (tester.BufferListCopyConstructor(bufferList, 1))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    {
        //testing Buffer List class copy constructor with 2 two nodes
        cout << "\nTest case: Buffer List class: copy constructor with buffer size less than zero:\n";
        BufferList bufferList(5);
        if (tester.BufferListCopyConstructor(bufferList, 10))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    {
        //testing Buffer list class assignment operator with buffer size less than zero
        cout << "\nTest case: Buffer list class: Assignment operator, negative buffer size:\n";
        BufferList bufferList(-10);
        if (tester.BufferListAssignmentOperator(bufferList, 5))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    {
        //testing Buffer list class assignment operator with regular buffer size
        cout << "\nTest case: Buffer list class: Assignment operator, normal buffer size:\n";
        BufferList bufferList(0);
        if (tester.BufferListAssignmentOperator(bufferList, 0))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    {
        //testing Buffer list class assignment operator with buffer size 0
        cout << "\nTest case: Buffer list class: Assignment operator, buffer size 0:\n";
        BufferList bufferList(0);
        if (tester.BufferListAssignmentOperator(bufferList, 5))
            cout << "\tTest passed!\n";
        else
            cout << "\tTest failed!\n";
    }
    {
        //Measuring the efficiency of insertion functionality
        cout << "\nMeasuring the efficiency of insertion functionality:" << endl;
        int M = 5;//number of trials
        int N = 10000;//original input size
        tester.BufListEnqueuePerformance(M, N);
    }
    {
        //an example of BufferList::dump()
        cout << "\nHere is an example of a linked list:" << endl;
        BufferList bufferList(5);
        for (int i = 40; i > 0; i--)
            bufferList.enqueue(i);
        bufferList.dump();
    }
     
    return 0;
}

bool Tester::BufferEnqueueFull(int size){
    Buffer aBuffer(size);
    aBuffer.m_next = nullptr;
    for (int i = 1; i < size + 1; i++)
        aBuffer.enqueue(i);
    try{
        //trying to insert in a full buffer
        aBuffer.enqueue(size + 2);
    }
    catch(overflow_error &e){
        //the exception that we expect
        return true;
    }
    catch(...){
        //any other exception, this case is not acceptable
        return false;
    }
    //no exception thrown, this case is not acceptable
    return false;
}

bool Tester::BufferDequeueEmpty(int size){
    Buffer aBuffer(size);
    try{
        //trying to dequeue in an empty buffer
        aBuffer.dequeue();
    }
    catch(underflow_error &e){
        //the exception that we expect
        return true;
    }
    catch(...){
        //any other exception, this case is not acceptable
        return false;
    }
    //no exception thrown, this case is not acceptable
    return false;
}

bool Tester::BufferEnqueueDequeue(Buffer &buffer, int dataCount) {
    //fill array with numbers until desired amount
    for (int i = 0; i < dataCount; i++) {
        buffer.enqueue(i);
    }
    //when dequeue array should match up with i
    for (int i = 0; i < dataCount ; i++) {
        if (buffer.dequeue() != i)
            return false;
    }
    return true;

}

bool Tester::BufferConstructor(const Buffer &buffer, int size) {
    if (size < 1) {
        if (buffer.m_capacity == 0)
            return true;
    }
    else if (buffer.m_capacity == size)
        return true;
    return false;
}

bool Tester::BufferCopyConstructor(const Buffer &buffer) {
    Buffer copyBuffer(buffer);

    //the case of 0 capacity
    if (buffer.m_capacity == 0 && copyBuffer.m_capacity == 0)
        return true;

    /*//the case of 0 numbers in buffer, should never happen
    if (buffer.m_count == 0 && copyBuffer.m_count == 0)
        return false;*/

    //the case that sizes are the same (and start and end values are the same)
    //and all the array values are the same
    //and the buffer pointers are not the same
    else if (buffer.m_capacity == copyBuffer.m_capacity &&
             buffer.m_start == copyBuffer.m_start &&
             buffer.m_end == copyBuffer.m_end &&
             buffer.m_buffer != copyBuffer.m_buffer) {
        for (int i = 0; i < buffer.m_count; i++) {
            if ((buffer.m_buffer[i] != copyBuffer.m_buffer[i]) || //check each value
                (&buffer.m_buffer == &copyBuffer.m_buffer)) {  //check pointer values
                return false;
            }
        }
        return true;
    }
    else return false;
}

bool Tester::BufferAssignmentOperator(const Buffer &buffer, int size) {
    Buffer assignmentBuffer(size);
    assignmentBuffer = buffer;

    //the case of 0 capacity
    if (buffer.m_capacity == 0 && assignmentBuffer.m_capacity == 0) return true;

    //the case that sizes are the same (and start and end values are the same)
    //and all the array values are the same
    //and the buffer pointers are not the same
    else if (buffer.m_capacity == assignmentBuffer.m_capacity &&
             buffer.m_count == assignmentBuffer.m_count &&
             buffer.m_start == assignmentBuffer.m_start &&
             buffer.m_end == assignmentBuffer.m_end &&
             buffer.m_buffer != assignmentBuffer.m_buffer){
        for (int i = 0; i < buffer.m_count; i++) {
            //buffer[i] might be empty see if that works without a sep if
            if ((buffer.m_buffer[i] != assignmentBuffer.m_buffer[i]) || //check each value
                (&buffer.m_buffer == &assignmentBuffer.m_buffer)) {  //check pointer values
                return false;
            }
        }
        return true;
    }
    else return false;
}

bool Tester::BufferListEnqueueDequeue(BufferList &bufferList, int dataCount) {
    for (int i = 0; i < dataCount; i++) {
        bufferList.enqueue(i);
    }
    for (int i = 0; i < dataCount; i++) {
        int out = bufferList.dequeue();
        if (out != i)
            return false;
    }

    return true;
}

bool Tester::BufferListCopyConstructor(BufferList &bufferList, int dataCount) {
    for (int i = 0; i < dataCount; i++) {
        bufferList.enqueue(i);
    }

    BufferList copy(bufferList);

    //the case of 0 capacity
    if (bufferList.m_cursor->m_capacity == 0 && copy.m_cursor->m_capacity == 0)
        return true;

        //the case that sizes are the same (and start and end values are the same)
        //and all the array values are the same
        //and the buffer pointers are not the same
    else if (bufferList.m_cursor->m_capacity == copy.m_cursor->m_capacity &&
            bufferList.m_cursor->m_start == copy.m_cursor->m_start &&
            bufferList.m_cursor->m_end == copy.m_cursor->m_end &&
            bufferList.m_cursor->m_buffer != copy.m_cursor->m_buffer) {
        for (int i = 0; i < bufferList.m_cursor->m_count; i++) {
            if ((bufferList.m_cursor->m_buffer[i] != copy.m_cursor->m_buffer[i]) || //check each value
                (&bufferList.m_cursor->m_buffer == &copy.m_cursor->m_buffer)) {  //check pointer values
                return false;
            }
        }
        return true;
    }
    else return false;
}

bool Tester::BufferListAssignmentOperator(const BufferList &bufferList, int size) {
    BufferList assignmentBufferList(size);
    assignmentBufferList = bufferList;

    //the case of 0 capacity
    if (bufferList.m_cursor->m_capacity == 0 && assignmentBufferList.m_cursor->m_capacity == 0) return true;

        //the case that sizes are the same (and start and end values are the same)
        //and all the array values are the same
        //and the buffer pointers are not the same
    else if (bufferList.m_cursor->m_capacity == assignmentBufferList.m_cursor->m_capacity &&
            bufferList.m_cursor->m_count == assignmentBufferList.m_cursor->m_count &&
            bufferList.m_cursor->m_start == assignmentBufferList.m_cursor->m_start &&
            bufferList.m_cursor->m_end == assignmentBufferList.m_cursor->m_end &&
            bufferList.m_cursor->m_buffer != assignmentBufferList.m_cursor->m_buffer){
        for (int i = 0; i < bufferList.m_cursor->m_count; i++) {
            //buffer[i] might be empty see if that works without a sep if
            if ((bufferList.m_cursor->m_buffer[i] != assignmentBufferList.m_cursor->m_buffer[i]) || //check each value
                (&bufferList.m_cursor->m_buffer == &assignmentBufferList.m_cursor->m_buffer)) {  //check pointer values
                return false;
            }
        }
        return true;
    }
    else return false;
}

bool Tester::BufferListDeleteLastNode(int size) {
    BufferList bufferList(size);
    try {
        bufferList.dequeue();
    } catch (underflow_error &e) {
        //the exception that we expect
        return true;
    }
    catch (...) {
        //any other exception, this case is not acceptable
        return false;
    }
    //no exception thrown, this case is not acceptable
    return false;
}

void Tester::BufListEnqueuePerformance(int numTrials, int N) {
  BufferList buffer(N);

  //int enq = 10000;

  //scaling factor for input size
  const int a = 2;

  //to store running times
  double T = 0.0;

  //stores the clock ticks while running the program
  clock_t start, stop;
  for (int k = 0; k < numTrials; k++)
    {
      //start = 0;
      start = clock();
      for (int i = 0; i < N; i++) {
	//the algorithm to be analyzed for efficiency
	buffer.enqueue(1);
      }
      stop = clock();

      //number of clock ticks the algorithm took
      T = stop - start;
      cout << "Inserting " << N << " members took " << T << " clock ticks ("<< T/CLOCKS_PER_SEC << " seconds)!" << endl;
      //increase the input size by the scaling factor
      N = N * a;
    }
}
