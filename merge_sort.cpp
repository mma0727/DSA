#include <iostream>
#include <vector>

template <class T>
std::vector<T> merge(const std::vector<T>& left, const std::vector<T>& right) {
	std::vector<T> res;
	int i = 0, j = 0;
	while (i < left.size() && j < right.size()) {
		if (left[i] <= right[j])	
			res.push_back(left[i++]);
		else 						
			res.push_back(right[j++]);
	}
	while (i < left.size()) 		
		res.push_back(left[i++]);
	while (j < right.size()) 		
		res.push_back(right[j++]);
	return res;

}
template <class T>
std::vector<T> merge_sort(std::vector<T>& vec) {
	if (vec.size() <= 1) return vec;
	typename std::vector<T>::iterator mid = vec.begin() + vec.size()/2;
	std::vector<T> left(vec.begin(), mid);
	std::vector<T> right(mid, vec.end());
	left = merge_sort(left);
	right = merge_sort(right);
	return merge(left, right);
}
int main() {
	std::vector<int> arr;
	int nsize; 
	std::cin >> nsize;
	for (int i = 0; i < nsize; i++) {
		int val;
		std::cin >> val;
		arr.push_back(val);
	}
	arr = merge_sort(arr);
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	return 0;
}