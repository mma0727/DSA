#ifndef BIN_TREE_H
#define BIN_TREE_H

#include <iostream>

template <typename elem>
class node {
public:
	virtual ~node() {}
	virtual void set_val(const elem&) = 0;
	// why I cannot have these three pure virtual functions? 
//	virtual elem& get_val() = 0;
//	virtual node* get_left() const = 0;
//	virtual node* get_right() const = 0;
	virtual void set_left(node*) = 0;
	virtual void set_right(node*) = 0;
	virtual bool is_leaf() = 0;
};

template <typename key, typename elem>
class bin_node: public node<elem> {
private:
	key k;
	elem it;
	bin_node* lc;
	bin_node* lr;
public:
	bin_node(): lc(NULL), lr(NULL) {}
	bin_node(key kval, elem itval, 
			 bin_node* l=NULL, bin_node* r=NULL):k(kval), it(itval), lc(l), lr(r) {}
	
	~bin_node() {}
	// return the value, key, left, and right child.
	elem& get_elem() {return it;}
	key& get_key() {return k;}
	bin_node* get_left() {return lc;}
	bin_node* get_right() {return lr;}

	// set the value, key, left, and right child.
	void set_val(const elem& e) {it = e;}
	void set_key(const key& k_val) {k = k_val;}
	void set_left(node<elem>* b) {lc = (bin_node*)b;}
	void set_right(node<elem>* b) {lr = (bin_node*)b;}
	
	bool is_leaf() {return (lc == NULL) && (lr == NULL);}
};

#endif 