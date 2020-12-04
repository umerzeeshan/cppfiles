#include "pch.h"
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;

class PQ {
private:
	int max = 5;
	int size = 0;
	int* pq;
public:
	PQ() {
		pq = new int[max];
	}
	~PQ() {}
	void doubleMax() {
		int* tmp = new int[max*2];
		std::memcpy(tmp, pq, max*sizeof(int));
		delete [] pq;
		pq = tmp;
		max = max * 2;
	}
	bool less(int i, int j) {
		return (pq[i] < pq[j]);
	}
	void swap(int i, int j) {
		int tmp = pq[i];
		pq[i] = pq[j];
		pq[j] = tmp;
		
	}
	void swim(int k) {
		while (k > 1 && less(k / 2, k))
		{
			swap(k / 2, k);
			k = k / 2;
		}
	}
	void sink(int k) {
		while (2*k <= size) {
			int j = 2 * k;
			if (j<size && less(j, j+1)) j++;
			if (!less(k, j)) break;
			swap(k, j);
			k = j;
		}
	}
	void insert(int v) {
		if (size == max)
			doubleMax();
		pq[++size] = v;
		swim(size);
	}
	int deleteMaxPq() {
		int maxp = pq[1];
		swap(1, size--);
		pq[size + 1] = NULL;
		sink(1);
		return maxp;

	}
	void displayPQ(){
		for (auto k = 1; k <= size; k++)
		{
			cout << "Priority queue size ="<<size<<" max = "<<max<<" position k " << k << " value" << pq[k] << endl;
		}
	}
    int* merge(int A[], int m, int B[], int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
    
        while (k >= 0) {
            if (j < 0 || (i >= 0 && A[i] > B[j]))
                A[k--] = A[i--];
            else
                A[k--] = B[j--];
        }
    return A;
    }
    

};

int main() {
	PQ q1;
	q1.insert(100);
	q1.insert(20);
	q1.insert(50);
	q1.insert(80);
	q1.insert(-2);
	q1.displayPQ();
	cout << "deleteMaxPq " << q1.deleteMaxPq()<<endl<<"deletedIdx";
	q1.displayPQ();

    const int m = 5;
    const int n = 5;
    const int T = m+n;
    
    int A[T] = {2, 5, 10, 12, 15, 0, 0, 0, 0, 0};
    int * p_A = A;
    int B[n] = {7,12,13,14,15};
    p_A = q1.merge(A, m, B, n);
    for (int i =0;i<T; i++)
    {
        cout<<"A["<<i<<"] = "<<A[i]<<endl;
    }
    
	
	return 0;
}