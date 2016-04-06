#ifndef LIST_H_INCLUDE
#define LIST_H_INCLUDE

#include <iostream>

template <typename elem> 
class list {
private:
	void operator =(const list&) {}
	list (const list&) {}
public:
	list() {}
	virtual ~list() {}
	virtual void clear() = 0;
	virtual bool insert(const elem&) =0;
	virtual bool append (const elem&) = 0;
	virtual elem remove_first() = 0;
	virtual void move_to_start() = 0;
	virtual void move_to_end() = 0;
	virtual void prev() = 0;
	virtual void next() = 0;
	virtual int left_lengh() const = 0;
	virtual int right_length() const = 0;
	virtual void move_to(int pos) = 0;
	virtual const elem& get() const = 0;
};

template <typename elem>
class node {
public:
	elem element;
	node* next;
	node(const elem& val, node*next_val = NULL): element(val), next(next_val) {}
	node(node* next_val=NULL):next(next_val) {}
};

template <typenmae elem>
class link_list: public list<elem> {
private:
	node<elem>* head;
	node<elem>* tail;
	node<elem>* fence;
	int left_count;
	int right_count;
	void init() {
		fence = tail = head = new node<elem>;
		left_count = right_count = 0;
	}
	void remove_all() {
		while (head != NULL) {
			fence = head;
			head = head->next;
			delete fence;
		}
	}
public:
	link_list() {init();}
	~link_list() {remove_all();}
	void clear() {remove_all(); init();}
	bool insert(const elem& it) {
		fence->next = new node<elem>(it, fence->next);
		if (tail == fence) tail = fence->next;
		right_count++;
		return true;
	}
	bool append(const elem& it) {
		tail = tail->next = new node<elem>(it);
		right_count++;
	}
};
#endif