#include<iostream>
#include<string>
#include <stdexcept>
template<typename T>
class vect {
private:
	size_t m_size = 0;
	size_t m_capacity = 2;
	T* m_array;
	//expanding array when size is equal to capacity
	void expand_vector() {
		m_capacity = m_capacity * 2;
		T* helper = new T[m_capacity];
		for (size_t i = 0; i < m_size; i++) {
			helper[i] = m_array[i];
		}
		delete[]m_array;
		m_array = helper;
		helper = nullptr;
	}
public:
	// Constructor when size is provided by user;
	vect(size_t size) :m_size(size) {
		if (size == 0) {
			m_capacity = 2;
		}
		if (m_size > 0) {
			m_capacity = m_size * m_capacity;
		}
			m_array = new T[m_capacity];

			for (size_t i = 0; i < m_size; i++) {
				m_array[i]=T();//initialize so that no garbage value
			}
		
	}
	//Defualt constructor
	vect() {
		m_array = new T[m_capacity];

	}
	vect(const vect<T>& copy):m_size(copy.m_size),m_capacity(copy.m_capacity) {
		m_array = new T[m_capacity];
		for (size_t i = 0; i < m_size; i++) {
			m_array[i] = copy.m_array[i];
		}
	}

	//Destructor free up heap allocated vect and destroys instance
	~vect() {
		delete[]m_array;
	}
	void push_back(T value) {
		if (m_size == m_capacity) {
			expand_vector();
		}
		m_array[m_size] = value;
		m_size++;
	}
	void pop_back() {
		if (m_size == 0) {

			throw std::runtime_error("pop_back on empty vector");
		}
		
		m_size--;
		
	}
		void erase() {
			m_size = 0;
		}
		size_t size() {
			return m_size;
		}
		size_t index_of(T value) {
			for (size_t i = 0; i < m_size; i++) {
				if (m_array[i] == value) {
					return i;
				}
			}
			std::cout << "not found" << std::endl;
			throw std::runtime_error("Value not found");//instead of exiting
		}
		size_t capacity() {
			return m_capacity;
		}


		T& operator[](size_t index) {
			if (index >= m_size) {
				throw std::out_of_range("Index out of bounds");//instead of exit using throw
			}
			
			return m_array[index];
             }
		const T& operator[](size_t index) const {
			if (index >= m_size) {
				throw std::out_of_range("Index out of bounds");
			}
			return m_array[index];
		}
		
		 vect<T>& operator=(const vect<T>& copy) {
			 if (this == &copy) {
				 return *this;
			}
			delete[]m_array;
			m_size = copy.m_size;
			m_capacity = copy.m_capacity;
			m_array = new T[m_capacity];
			for (size_t i = 0; i < m_size; i++) {
				m_array[i] = copy.m_array[i];
			} 
			return *this;
		}
		

};


int main() {
	vect<std::string> e;
	vect<std::string> f = e;



}