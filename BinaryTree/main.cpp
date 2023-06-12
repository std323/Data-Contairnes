#include<iostream>
#include<ctime>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab  "\t"
#define delimiter    "\n------------------------------------\n"

//#define DEBUG
class Tree
{
protected:
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) :Data(Data), pLeft(pLeft), pRight(pRight)
		{
#ifdef DEBUG
			cout << "EConstructor:\t" << this << endl;
#endif // DEBUG

		}
		~Element()
		{
#ifdef DEBUG
			cout << "EDestructor:\t" << this << endl;
#endif // DEBUG
		}
		bool is_leaf()const
		{
			return pLeft == pRight;
		}
		friend class Tree;
		friend class UniqueTree;

	}*Root;
public:
	Element* getRoot()
	{
		return Root;
	}
	Tree() :Root(nullptr)
	{
		cout << "TConstructor:\t" << this << endl;
	}
	Tree(const std::initializer_list<int>& il) :Tree()
	{
		for (int i : il)insert(i, Root);
	}
	~Tree()
	{
		clear(Root);
		Root = nullptr;
		cout << "TDestructor:\t" << this << endl;

	}
	void insert(int Data)
	{
		insert(Data, Root);
	}
	int count()const
	{
		return count(Root);
	}
	int minValue()const
	{
		return minValue(Root);
	}
	int maxValue()const
	{
		return maxValue(Root);
	}
	void balance()
	{
		balance(Root);
	}
	void print()const
	{
		print(Root);
		cout << endl;
	}
	void print(int depth)const
	{
		print(Root, depth, 50);
		cout << endl;
	}
	void true_print()const
	{
		true_print(Root, depth());
		cout << endl;
	}

	int sum()const
	{
		return sum(Root);
	}
	double avg()const
	{
		return avg(Root);
	}
	int depth()const
	{
		return depth(Root);
	}
	void clear()
	{
		clear(Root);
		Root = nullptr;
	}
	void erase(int Data)
	{
		erase(Data, Root);
	}


private:
	void clear(Element* Root)
	{
		if (Root == nullptr)return;
		clear(Root->pLeft);
		clear(Root->pRight);
		delete Root;
	}

	//            Adding elements:
	void insert(int Data, Element* Root)
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
	void erase(int Data, Element*& Root)
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


	//     Methods:


	void print(Element* Root)const
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
	}
	void print(Element* Root, int depth, int width)const
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
	void true_print(Element* Root, int depth)const
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

	int minValue(Element* Root)const
	{
		if (Root == nullptr)return 0;
		/*/if (Root->pLeft == nullptr)return Root->Data;
		else return minValue(Root->pLeft);*/

		return Root->pLeft == nullptr ? Root->Data : minValue(Root->pLeft);
	}
	int maxValue(Element* Root)const
	{
		if (Root == nullptr)return 0;
		/*if (Root->pRight == nullptr)return Root->Data;
		else return maxValue(Root->pRight);*/

		return Root->pRight == nullptr ? Root->Data : maxValue(Root->pRight);
	}
	int count(Element* Root)const
	{
		/*if (Root == nullptr)return 0;
		else return count(Root->pLeft) + count(Root->pRight)+1;*/
		//return Root ? count
		return Root == nullptr ? 0 : count(Root->pLeft) + count(Root->pRight) + 1;
	}

	int sum(Element* Root)const
	{
		if (Root == nullptr)return 0;
		else return Root->Data + sum(Root->pLeft) + sum(Root->pRight);
	}

	double avg(Element* Root)const
	{
		if (Root == nullptr)return 0;
		else return (double)sum(Root) / count(Root);
	}
	int depth(Element* Root)const
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
	void balance(Element* Root)
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


};

class UniqueTree :public Tree
{

	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else if (Data > Root->Data)
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
public:
	void insert(int Data)
	{
		insert(Data, Root);
	}
};
template<typename T>
void measure(const char description[], const Tree& tree, T(Tree::* member_function)()const)
{
	cout << description;
	clock_t t_start = clock();
	cout << (tree.*member_function)();
	clock_t t_end = clock();
	cout << " выполнено за " << double(t_end - t_start) / CLOCKS_PER_SEC << " секунд.\n";
}

//#define BASE_CHEK
//#define DEPTH_CHEK
#define BALANCE_CHEK
//#define PREFORMANCE_CHEK

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHEK
	int n;
	cout << "Введите размер дерева: "; cin >> n;
	Tree tree;// = {50, 25, 75, 16, 32, 64, 80, 78};
	cout << "Минимальное значение в дереве: " << tree.minValue() << endl;
	cout << "Максимальное значение в дереве: " << tree.minValue() << endl;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);
	}
	tree.print();

	cout << endl;
	cout << "Минимальное значение в дереве: " << tree.minValue() << endl;
	cout << "Максимальное значение в дереве: " << tree.maxValue() << endl;
	cout << "Количество элементов в дереве: " << tree.count() << endl;
	cout << "Сумма элементов: " << tree.sum() << endl;
	cout << "Cреднее-арифметическое элементов дерева: " << tree.avg() << endl;
	cout << "Глубина дерева: " << tree.depth() << endl;

	int value;
	cout << "Введите удаляемое значение: "; cin >> value;
	tree.erase(value);
	tree.print();


	UniqueTree u_tree;
	for (int i = 0; i < n; i++)
	{
		u_tree.insert(rand() % 100);
	}
	u_tree.print();
	cout << endl;
	cout << endl;
	cout << "Минимальное значение в дереве: " << u_tree.minValue() << endl;
	cout << "Максимальное значение в дереве:" << u_tree.maxValue() << endl;
	cout << "Количество элементов в дереве: " << u_tree.count() << endl;

	cout << "Сумма элементов: " << u_tree.sum() << endl;
	cout << "Cреднее-арифметическое элементов дерева: " << u_tree.avg() << endl;
	cout << "Глубина дерева: " << u_tree.depth() << endl;
#endif // BASE_CHEK

#ifdef DEPTH_CHEK
	Tree tree = { 50, 25, 75, 16, 32, 64, 80, 68 };
	//tree.~Tree();
	tree.print();
	cout << "Глубина дерева: " << tree.depth() << endl;

	//tree.print(0);
	tree.true_print();

	/*int value;
	cout << "Введите удаляемое значение: "; cin >> value;
	tree.erase(value);
	tree.print();*/
#endif // DEPTH_CHEK

#ifdef PREFORMANCE_CHEK
	clock_t t_start, t_end;
	int n;
	cout << "Введите размер дерева: "; cin >> n;
	Tree tree;
	t_start = clock(); //Функция 'clock()' 
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);
	}
	t_end = clock();
	cout << "Дерево заполнено за: " << double(t_end - t_start) / CLOCKS_PER_SEC << " сек." << endl;
	//tree.print();

	measure("Минимальное значение в дереве:\t ", tree, &Tree::minValue);
	measure("Максимальное значение в дереве:\t ", tree, &Tree::maxValue);
	measure("Сумма элементов деревa:\t\t ", tree, &Tree::sum);
	measure("Количество элементов в дереве:\t ", tree, &Tree::count);
	measure("Cреднее-арифметическое элементов дерева:\t ", tree, &Tree::avg);
	measure("Глубина дерева:\t\t\t ", tree, &Tree::depth);




	/*t_start = clock();
	cout << "Минимальное значение в дереве: " << tree.minValue() << tab;
	t_end = clock();
	cout << double(t_end - t_start) / CLOCKS_PER_SEC << " сек." << endl;

	t_start = clock();
	cout << "Максимальное значение в дереве: " << tree.maxValue() << tab;
	t_end = clock();
	cout << double(t_end - t_start) / CLOCKS_PER_SEC << " сек." << endl;

	t_start = clock();
	cout << "Количество элементов в дереве: " << tree.count() << tab;
	t_end = clock();
	cout << double(t_end - t_start) / CLOCKS_PER_SEC << " сек." << endl;

	t_start = clock();
	cout << "Сумма элементов:\t " << tree.sum() << tab;
	t_end = clock();
	cout << double(t_end - t_start) / CLOCKS_PER_SEC << " сек." << endl;

	t_start = clock();
	cout << "Cреднее-арифметическое элементов дерева: " << tree.avg() << tab;
	t_end = clock();
	cout << double(t_end - t_start) / CLOCKS_PER_SEC << " сек." << endl;

	t_start = clock();
	cout << "Глубина дерева: " << tree.depth() << tab;
	t_end = clock();
	cout << double(t_end - t_start) / CLOCKS_PER_SEC << " сек." << endl;*/


#endif // PREFORMANCE_CHEK
#ifdef BALANCE_CHEK
	Tree tree = { 3, 5, 8, 13, 21, 34, 55 };

	tree.true_print();
	tree.balance();
	tree.true_print();

#endif // BALANCE_CHEK





}
