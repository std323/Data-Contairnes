#pragma once

#include<iostream>
#include<ctime>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab  "\t"
#define delimiter    "\n------------------------------------\n"

//#define DEBUG
template<typename T>class Tree;
template<typename T>class UniqueTree;

template<typename T>class Tree
{
protected:
	class Element
	{
		T Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(T Data, Element* pLeft = nullptr, Element* pRight = nullptr);
		~Element();
		bool is_leaf()const;
		friend class Tree<T>;
		friend class UniqueTree<T>;

	}*Root;
public:
	Element* getRoot();
	Tree();
	Tree(const std::initializer_list<T>& il);
	~Tree();
	void insert(T Data);
	void erase(T Data);
	T count()const;
	T sum()const;
	T avg()const;
	T minValue()const;
	T maxValue()const;
	int depth()const;
	void balance();
	void print()const;
	void print(int depth)const;
	void true_print()const;
	void clear();

	//private:
	void clear(Element* Root);

	//            Adding elements:
	void insert(T Data, Element* Root);
	void erase(T Data, Element*& Root);

	//                      Methods:
	int count(Element* Root)const;
	T sum(Element* Root)const;
	T avg(Element* Root)const;
	T minValue(Element* Root)const;
	T maxValue(Element* Root)const;
	int depth(Element* Root)const;
	void balance(Element* Root);
	void print(Element* Root)const;
	void print(Element* Root, int depth, int width)const;
	void true_print(Element* Root, int depth)const;
};
template<typename T>class UniqueTree :public Tree<T>
{
	void insert(T Data, typename Tree<T>::Element* Root);
public:
	void insert(T Data);
};

template<typename T>
void measure(const char description[], const Tree<T>& tree, T(Tree<T>::* member_function)()const);

