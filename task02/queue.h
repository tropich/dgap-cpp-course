typedef int data;

class BasicQueue
{
public:

    // Add element to the end
    virtual void enqueue(data &) = 0;

    // Return first element
    virtual data dequeue() = 0;

    // Get total count of elements
    virtual unsigned getLength() = 0;

};

class ListQueue: public BasicQueue
{
public:
    void enqueue(data &data) override;
	data dequeue() override;
	unsigned getLength() override;
	void ListQueue::dellist(List*l);
	ListQueue();
    void dellist(Node* l);
private:
    struct Node{
        Node* next
        data Data
        };
    Node* last;
    Node* first;
    /*
     * Fully implement class:
     * - declarations here
     * - definitions in queue.cpp
     * Could have infinite size
     */
};

class ArrayQueue: public BasicQueue
{
public:
    ArrayQueue(unsigned max_size = 64);
    void enqueue(data &data) override;
	data dequeue() override;
	unsigned getLength() override;
	unsigned maxlen;
private:
    data *x;
    unsigned first;
    unsigned last;

    /*
     * Fully implement class:
     * - declarations here
     * - definitions in queue.cpp
     * Only finite size implementation is required
     */
};

