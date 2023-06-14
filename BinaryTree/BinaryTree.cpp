#include"BinaryTree.h"

////////////////////////////////////////////////////////////////////
///////////////////    Tree member functions     ///////////////////
template<typename T>typename Tree<T>::Element* getRoot()
{
	return Tree<T>::Root;
}
template<typename T>Tree<T>::Tree() :Root(nullptr)
{
	cout << "TConstructor:\t" << this << endl;
}
template<typename T>Tree<T>::Tree(const std::initializer_list<T>& il) : Tree()
{
	for (T i : il)insert(i, Root);
}
template<typename T>Tree<T>::~Tree()
{
	clear(Root);
	Root = nullptr;
	cout << "TDestructor:\t" << this << endl;
}
template<typename T>void Tree<T>::insert(T Data)
{
	insert(Data, Root);
}
template<typename T>void Tree<T>::erase(T Data)
{
	erase(Data, Root);
}
template<typename T>T Tree<T>::count()const
{
	return count(Root);
}
template<typename T>T Tree<T>::sum()const
{
	return sum(Root);
}
template<typename T>T Tree<T>::avg()const
{
	return avg(Root);
}
template<typename T>T Tree<T>::minValue()const
{
	return minValue(Root);
}
template<typename T>T Tree<T>::maxValue()const
{
	return maxValue(Root);
}
template<typename T>int Tree<T>::depth()const
{
	return depth(Root);
}
template<typename T>void Tree<T>::balance()
{
	balance(Root);
}
template<typename T>void Tree<T>::print()const
{
	print(Root);
	cout << endl;
}
template<typename T>void Tree<T>::print(int depth)const
{
	print(Root, depth, 50);
	cout << endl;
}
template<typename T>void Tree<T>::true_print()const
{
	true_print(Root, depth());
	cout << endl;
}
template<typename T>void Tree<T>::clear()
{
	clear(Root);
	Root = nullptr;
}
//private:
template<typename T>void Tree<T>::clear(Element* Root)
{
	if (Root == nullptr)return;
	clear(Root->pLeft);
	clear(Root->pRight);
	delete Root;
}
//            Adding elements:
template<typename T>void Tree<T>::insert(T Data, Element* Root)
{
	if (this->Root == nullptr)this->Root = new Element(Data);
	if (Root == nullptr)return;
	if (Data < Root->Data)
	{
		if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
		else insert(Data, Root->pLeft);
	}
	else
	{
		if (Root->pRight == nullptr)Root->pRight = new Element(Data);
		else insert(Data, Root->pRight);
	}
}
template<typename T>void Tree<T>::erase(T Data, Element*& Root)
{
	if (Root == nullptr)return;
	erase(Data, Root->pLeft);
	erase(Data, Root->pRight);
	if (Data == Root->Data)
	{
		if (Root->is_leaf()/*Root->pLeft == Root->pRight*/)
		{
			delete Root;
			Root = nullptr;
		}
		else
		{
			if (count(Root->pLeft) > count(Root->pRight))
			{
				Root->Data = maxValue(Root->pLeft);
				erase(maxValue(Root->pLeft), Root->pLeft);
			}
			else
			{
				Root->Data = minValue(Root->pRight);
				erase(minValue(Root->pRight), Root->pRight);
			}
		}
	}
}
//                      Methods:
template<typename T>int Tree<T>::count(Element* Root)const
{
	/*if (Root == nullptr)return 0;
	else return count(Root->pLeft) + count(Root->pRight)+1;*/
	//return Root ? count
	return Root == nullptr ? 0 : count(Root->pLeft) + count(Root->pRight) + 1;
}
template<typename T>T Tree<T>::sum(Element* Root)const
{
	if (Root == nullptr)return 0;
	else return Root->Data + sum(Root->pLeft) + sum(Root->pRight);
}
template<typename T>T Tree<T>::avg(Element* Root)const
{
	if (Root == nullptr)return 0;
	else return (double)sum(Root) / count(Root);
}
template<typename T>T Tree<T>::minValue(Element* Root)const
{
	if (Root == nullptr)return 0;
	/*/if (Root->pLeft == nullptr)return Root->Data;
	else return minValue(Root->pLeft);*/

	return Root->pLeft == nullptr ? Root->Data : minValue(Root->pLeft);
}
template<typename T>T Tree<T>::maxValue(Element* Root)const
{
	if (Root == nullptr)return 0;
	/*if (Root->pRight == nullptr)return Root->Data;
	else return maxValue(Root->pRight);*/

	return Root->pRight == nullptr ? Root->Data : maxValue(Root->pRight);
}
template<typename T>int Tree<T>::depth(Element* Root)const
{
	if (Root == nullptr)return 0;
	int l_depth = depth(Root->pLeft) + 1;
	int r_depth = depth(Root->pRight) + 1;
	return l_depth > r_depth ? l_depth : r_depth;

	/*else return
		depth(Root->pLeft) > depth(Root->pRight) ?
		depth(Root->pLeft) + 1:
		depth(Root->pRight) + 1;*/
}
template<typename T>void Tree<T>::balance(Element* Root)
{
	if (Root == nullptr)return;
	if (abs(count(Root->pLeft) - count(Root->pRight)) < 2)return;
	// Функция abs() возвращает абсолютное значение числа:
	// 2 - 5 = -3;
	//abs (2-5) = 3;
	if (count(Root->pLeft) < count(Root->pRight))
	{

		if (Root->pLeft)insert(Root->Data, Root->pLeft);
		else Root->pLeft = new Element(Root->Data);
		Root->Data = minValue(Root->pRight);
		erase(minValue(Root->pRight), Root->pRight);
	}
	else if (count(Root->pLeft) > count(Root->pRight))
	{

		if (Root->pRight)insert(Root->Data, Root->pRight);
		else Root->pRight = new Element(Root->Data);
		Root->Data = maxValue(Root->pLeft);
		erase(maxValue(Root->pLeft), Root->pLeft);
	}
	balance(Root->pLeft);
	balance(Root->pRight);
	balance(Root);
}
template<typename T>void Tree<T>::print(Element* Root)const
{
	if (Root == nullptr)return;
	print(Root->pLeft);
	cout << Root->Data << "\t";
	print(Root->pRight);
}
template<typename T>void Tree<T>::print(Element* Root, int depth, int width)const
{
	if (Root == nullptr)return;
	width /= 2;
	print(Root->pLeft, depth - 1, width);
	if (depth == 0)
	{
		cout.width(width);
		cout << Root->Data << tab;
	}
	cout.width(width);
	cout << "";
	print(Root->pRight, depth - 1, width);
}
template<typename T>void Tree<T>::true_print(Element* Root, int depth)const
{
	if (depth == -1)return;
	true_print(Root, depth - 1);
	print(Root, depth, 50);
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
}
///////////////////    Tree member functions     ///////////////////
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
///////////////////   Element member functions     ///////////////////
template<typename T> Tree<T>::Element::Element(T Data, Element* pLeft, Element* pRight) :Data(Data), pLeft(pLeft), pRight(pRight)
{
#ifdef DEBUG
	cout << "EConstructor:\t" << this << endl;
#endif // DEBUG

}
template<typename T> Tree<T>::Element::~Element()
{
#ifdef DEBUG
	cout << "EDestructor:\t" << this << endl;
#endif // DEBUG
}
template<typename T>bool Tree<T>::Element::is_leaf()const
{
	return pLeft == pRight;
}
///////////////////    Element member functions     /////////////////////
/////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////
///////////////////   UniqueTree member functions     ///////////////////
template<typename T>void insert(T Data, typename Tree<T>::Element* Root)
{
	if (this->Root == nullptr)this->Root = new typename Tree<T>::Element::Element(Data);
	if (Root == nullptr)return;
	if (Data < Root->Data)
	{
		if (Root->pLeft == nullptr)Root->pLeft = new typename Tree<T>::Element::Element(Data);
		else insert(Data, Root->pLeft);
	}
	else if (Data > Root->Data)
	{
		if (Root->pRight == nullptr)Root->pRight = new typename Tree<T>::Element::Element(Data);
		else insert(Data, Root->pRight);
	}
}
//public:
template<typename T>void insert(T Data)
{
	insert(Data, Tree<T>::Root);
}
///////////////////    UniqueTree member functions     ///////////////////
//////////////////////////////////////////////////////////////////////////

template<typename T>
void measure(const char description[], const Tree<T>& tree, T(Tree<T>::* member_function)()const)
{
	cout << description;
	clock_t t_start = clock();
	cout << (tree.*member_function)();
	clock_t t_end = clock();
	cout << " выполнено за " << double(t_end - t_start) / CLOCKS_PER_SEC << " секунд.\n";
}