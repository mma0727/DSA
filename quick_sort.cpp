#include <iostream>
#include <vector>
#include <algorithm> //swap
template <class T>
int partition(std::vector<T>& vec, const int& left, const int& right) {
	T pivot = vec[left];
	int i = left + 1, j = right;
	while (i <= j) {
		while (i <= j && vec[i] <= pivot) {
			i++;
		}
		while (i <= j && vec[j] > pivot) {
			j--;
		}
		if (i < j) {
			std::swap(vec[i],vec[j]);
		}
	}
	std::swap(vec[left],vec[j]);
	return j;
}
template <class T>
void quick_sort(std::vector<T>& vec, const int left, const int right) {
	if (left >= right) {
		return;
	}
	int pivot_index = partition(vec, left, right);
	std::cout << pivot_index << " ";
	quick_sort(vec,left, pivot_index-1);
	quick_sort(vec, pivot_index+1, right);
}
int main() {
	std::vector<int> vec;
	int nsize;
	std::cin >> nsize;
	for (int i = 0; i < nsize;i ++) {
		int input;
		std::cin >> input;
		vec.push_back(input);
	}
	quick_sort(vec, 0, nsize-1);
	for (int i = 0; i < nsize; i ++) {
		std::cout << vec[i] << " ";
	}
	return 0;
}