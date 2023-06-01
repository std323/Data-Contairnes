#pragma once

#include<iostream>
#include<ctime>
using namespace std;
using std::cin;
using std::cout;
using std::endl;;

#define tab "\t"
#define delimiter   "\n----------------------------------\n"


template<typename T>class List
{
	class Element
	{
		T Data; //�������� ��������
		Element* pNext;//��������� �� ��������� �������
		Element* pPrev;//��������� �� ���������� �������
	public:
		Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr);
		~Element();
		friend class List<T>;
	}*Head, * Tail;//������� � ��������� �� ������� ����� ��������� ����� �� ����� �������� ������
	size_t size;

	class ConstBaseIterator
	{
		//Generalisation - ���������
	protected:
		Element* Temp;
	public:
		ConstBaseIterator(Element* Temp) :Temp(Temp) {}
		~ConstBaseIterator() {}
		bool operator==(const ConstBaseIterator& other)const;
		bool operator!=(const ConstBaseIterator& other)const;
		const T& operator*()const;
	};
public:
	class ConstIterator :public ConstBaseIterator
	{
	public:
		ConstIterator(Element* Temp);
		~ConstIterator();
		ConstIterator& operator++();
		ConstIterator operator++(int);
		ConstIterator& operator--();
		ConstIterator operator--(int);
	};
	class ConstReverseIterator :public ConstBaseIterator
	{
	public:
		ConstReverseIterator(Element* Temp);
		~ConstReverseIterator();
		ConstReverseIterator& operator++();
		ConstReverseIterator operator++(int);
		ConstReverseIterator& operator--();
		ConstReverseIterator operator--(int);
	};
	class Iterator :public ConstIterator
	{
	public:
		Iterator(Element* Temp):ConstIterator(Temp) {}
		~Iterator() {}

		T& operator*();
	};
	class ReverseIterator : public ConstReverseIterator
	{
	public:
		ReverseIterator(Element* Temp):ConstReverseIterator(Temp) {}
		~ReverseIterator() {}

		T& operator*();
	};

	Iterator begin();
	Iterator end();
	ConstIterator begin()const;
	ConstIterator end()const;
	ReverseIterator rbegin();
	ReverseIterator rend();
	ConstReverseIterator rbegin()const;
	ConstReverseIterator rend()const;

	//                 Constructors:
	List();
	List(int size);
	List(const std::initializer_list<T>& il);
	List(const List<T>& other);
	~List();

	//                       Operators:
	List<T>& operator=(const List<T>& other);

	//                 Adding elements:
	void push_front(T Data);
	void push_back(T Data);
	void insert(T Data, int Index);
	void erase(int Index);

	//      Removing elements:
	void pop_front();
	void pop_back();

	//                Methods:
	void print()const;
	void reverse_print()const;
};

template<typename T>List<T> operator+(const List<T>& left, const List<T>& right);
