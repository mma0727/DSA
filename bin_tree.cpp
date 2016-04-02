#include "bin_tree.h"

int main() {
	bin_node<int, int> n1(3,4);
	bin_node<int, int> n2(2,5);
	bin_node<int, int> n3(4,6);
	n1.set_left((node <int> *)&n2);
	n1.set_right((node<int> *)&n3);

	std::cout <<"n1= (" << n1.get_key() << ", " << n1.get_elem() << ")\n";
	std::cout << "left= (" << (*n1.get_left()).get_key() << ", " << (*n1.get_left()).get_elem() << ")\n";
	return 0;
}