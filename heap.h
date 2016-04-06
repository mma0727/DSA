#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <algorithm> // swap
template<typename elem, typename Comp> class heap{
private:
	elem* heap;
	int max_size;
	int n;
	void shift_down(int pos) {
		while (!is_leaf(pos)) {
			int lc = left_child(pos);
			int rc = right_child(pos);
			if (rc < n && Comp::prior(heap[rc], heap[lc])) {
				lc = rc; // set lc to greater child's value
			}
			if (Comp::prior(heap[pos],heap[lc])) return;
			swap(heap[pos], heap[j]);
			pos = lc;
		}
	}
public:
	heap(elem* h, int num, int max): heap(h), num(n), max_size(max) {}
	int size() {
		return n;
	}
	bool is_leaf(const int& pos) {
		return (pos >= n/2) && (pos < n);
	}
	int left_child(const int& pos) {
		return 2*pos + 1;
	}
	int right_child(const int& pos) {
		return 2*pos + 2;
	}
	int parent(const int& pos) {
		Assert(pos > 0, "invalid child index");
		return (pos-1)/2;
	}
	void build_heap() {
		for (int i = n/2-1; i>=0; i--) {
			shift_down(i);
		}
	}
	void insert(const elem& it) {
		Assert (n < max_size, "heap is full");
		int curr = n++;
		heap[curr] = it; // start at end of heap
		while (curr != 0 && (Comp::prior(heap[curr], heap[parent(curr)]))) {
			swap(heap[curr], heap[parent(curr)]);
			curr = parent(curr);
		}
	}
	elem remove_first() {
		Assert (n > 0, "Heap is empty");
		swap(heap[0], heap[--n]);
		if (n != 0) shift_down(0);
		return heap[n];
	}
	elem remove(const int& pos) {
		Assert((pos >= 0) && (pos < n), "invalid position");
		swap(heap[pos], heap[--n]); //swap with the 
		while ((pos != 0) && (Comp::prior(heap[pos], heap[parent(pos)]))) {
			swap(heap[pos], heap[parent(pos)]);
			shift_down(pos);
			return heap[n];
		}
	}
};


template<typename elem, typename Comp>
void heapsort(elem a[], int n) {
	elem maxval;
	heap<elem, Comp> h(a, n, n);
	for (int i = 0; i < n; i ++) {
		maxval = h.remove_first();
	}
}


#endif
