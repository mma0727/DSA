#ifndef GENERAL_TREE_H
#define GENERAL_TREE_H

#include <iostream>

template<typename elem> class gtree_node {
public:
	elem value();
	bool is_leaf();
	gtree_node* parent();
	gtree_node* left_most_child();
	gtree_node* right_sibling();
	void set_value(elem&);
	void insert_first(gtree_node<elem>* );
	void insert_next(gtree_node<elem>* );
	void remove_first();
	void remove_next();
};

template<typename elem> class gtree {
private:
	void print_help(gtree_node<elem*> root) {
		if (root->is_leaf()) std::cout << "leaf: ";
		else std::cout << "internal: ";
		std::cout << root->value() << "\n";
		for (gtree_node<elem*> temp = root->left_most_child(); 
			temp != NULL; temp = temp->right_sibling())
			print_help(temp);
	}
public:
	void clear();
	gtree<elem*> root();
	void combine(elem&, gtree_node<elem*>, gtree_node<elem*>);
	void print() {
		
	}
};
#endif