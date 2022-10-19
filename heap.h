#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <iostream>



template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> heapvec;
  size_t size_; 
	int m_;
	PComparator c_;
  void trickleUp(unsigned int loc, PComparator c);
	void trickleDown(unsigned int loc, PComparator c);
	void swap( T& a, T& b );
};

// Add implementation of member functions here
template <typename T, typename PComparator>
void Heap<T,PComparator>::swap (T& a,T& b ){
	T d(a);
	a=b;
	b=d;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c){
	m_=m;
	size_=0;
	c_=c;
	std::vector<T> heapvec;
}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(unsigned int loc,PComparator c_){
	int parent = (loc)/m_;
	// if the heap is implementing in correct sequence
	if(c_(heapvec[loc],heapvec[parent])){
		// cout<<"entering UPwhileloop"<<endl;
		// trickle up the newly inserted node to its proper location
		while(parent>=0 && c_(heapvec[loc],heapvec[parent])){
			// cout<<"Loc before swap: "<<heapvec[loc]<<endl;
			// cout<<"Parent before swap: "<<heapvec[parent]<<endl;
			swap(heapvec[loc], heapvec[parent]);
			// cout<<"Loc after swap: "<<heapvec[loc]<<endl;
			// cout<<"Parent after swap: "<<heapvec[parent]<<endl;
			loc = parent;
			if(loc==0){return;}
			parent = (loc)/m_;
		}
	}
	return;
}
template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleDown(unsigned int loc,PComparator c_){
	// set child 
	unsigned int smallerchild = m_*(loc);
	unsigned int rchild = loc * m_ + m_;
	// if right child exists, 
	if (smallerchild>(heapvec.size())){return;}
	// find the best child
	if(smallerchild<heapvec.size()+1){
		for(unsigned int i=smallerchild;i<rchild && i<heapvec.size();i++){
			if(c_(heapvec[i+1], heapvec[smallerchild])){
				smallerchild = i+1;
			}
		}
	}
	// swaps it for the smallest child until it is in its right place
	if(c_(heapvec[smallerchild], heapvec[loc])){
		swap(heapvec[loc], heapvec[smallerchild]);
		trickleDown(smallerchild,c_);
	}
}


template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
	heapvec.push_back(item);
	size_++;
	trickleUp(heapvec.size()-1,c_);
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
	if(heapvec.size()==0){
		return true;
	}
	else{
		return false;
	}
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
	return size_;
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  else{
		return heapvec[0];
  }

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
	else{
		heapvec[0]=heapvec[heapvec.size()-1];
		heapvec.pop_back();
		size_--;
		trickleDown(0,c_);
	}
}



#endif

