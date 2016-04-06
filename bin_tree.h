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

template <typename key, typename elem>
class BST {
private:
	bin_node<key,elem>* root;
	int node_count;
	void clear_all(bin_node<key, elem>*);
	bin_node<key, elem>* insert_help(bin_node<key, elem>*, const key&, const elem&);
	bin_node<key, elem>* remove_help(bin_node<key, elem>*, const key&, bin_node<key,elem>*&);
	bin_node<key, elem>* delete_min(bin_node<key, elem>*, bin_node<key, elem>*&);
	bool find_help(bin_node<key, elem>*, const key&, elem&) const;
	void print_help(bin_node<key, elem>*, int) const;
public:
	BST(): root(NULL), node_count(0) {}
	~BST() {clear_all(root);}
	void clear() {
		clear_all(root); root = NULL; node_count = 0;
	}
	void insert(const key& k, const elem& it) {
		root = insert_help(root, k, it);
		node_count++;
	}
	// remove some record with key k and return it in "it".
	// return ture if such exists, false otherwise.
	// if multiple records match, remove an arbitrary one.
	bool remove(const key& k, elem& it) {
		bin_node<key, elem>* temp = NULL;
		root = remove_help(root, k, temp);
		if (temp == NULL) return false;
		it = temp->get_elem();
		node_count --;
		delete temp;
		return true;
	}
	elem remove_min() {
		assert(root != NULL, "empty tree");
		bin_node<key, elem>* temp = NULL;
		root = delete_min(root, temp);
		elem it = temp->get_elem();
		delete temp;
		node_count --;
		return it;
	}
	bool find(const key& k, elem& it) const {
		return find_help(root, k, it);
	}
	int size() {return node_count;}
	void print() const {
		assert(root != NULL, "the BST is empty\n");
		print_help(root, 0);
	}
};

template <typename key, typename elem>
bool BST<key, elem>::find_help(bin_node<key, elem>* root, const key& k, elem& e) const {
	if (root == NULL) return false;
	else if (k < root->get_key())
		return find_help(root->get_left(), k, e);
	else if (k > root->get_key())
		return find_help(root->get_right(), k, e);
	else {
		e = root->get_val(); 
		return true;
	}
}

template<typename key, typename elem>
bin_node<key, elem>* BST<key, elem>::insert_help(
	bin_node<key, elem>* root, const key& k, const elem& it) {
	if (root == NULL) {
		return new bin_node<key, elem>(k, it);
	}
	if (k < root->get_key()) {
		root->set_left(insert_help(root->get_left(), k , it));
	}
	else root->set_right(insert_help(root->get_right(), k, it));
	return root;
}

template <typename key, typename elem>
bin_node<key, elem>* BST<key, elem>::delete_min(bin_node<key, elem>* root, 
												bin_node<key, elem>*& s) {
	if (root->get_left() == NULL) {
		s = root;
		return root->get_right();
	}
	else {
		root->set_left(delete_min(root->get_left(), s));
		return root;
	}
}
#endif 