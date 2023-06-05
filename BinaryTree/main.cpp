#include<iostream>
using namespace std;

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
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t" << this << endl;
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
	~Tree()
	{
		cout << "TDestructor:\t" << this << endl;
		if (Root) delete Root;
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
	//     Methods:
	void print(Element* Root)const
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << "\t";
		print(Root->pRight);
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
		if (Root->pLeft <= Root->pRight)
			return depth(Root->pRight) + 1;
		else return depth(Root->pLeft) + 1;
		
}

};

class UniqueTree :public Tree
{
public:
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
};

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер дерева: "; cin >> n;
	Tree tree;
	cout << "Минимальное значение в дереве: " << tree.minValue(tree.getRoot()) << endl;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100, tree.getRoot());
	}
	tree.print(tree.getRoot());

	cout << endl;
	cout << "Минимальное значение в дереве: " << tree.minValue(tree.getRoot()) << endl;
	cout << "Максимальное значение в дереве: " << tree.maxValue(tree.getRoot()) << endl;
	cout << "Количество элементов в дереве: " << tree.count(tree.getRoot()) << endl;

	/*UniqueTree u_tree;
	for (int i = 0; i < n; i++)
	{
		u_tree.insert(rand() % 100, u_tree.getRoot());
	}
	u_tree.print(u_tree.getRoot());
	cout << endl;
	cout << endl;
	cout << "Минимальное значение в дереве: " << u_tree.minValue(u_tree.getRoot()) << endl;
	cout << "Максимальное значение в дереве:" << u_tree.maxValue(u_tree.getRoot()) << endl;
	cout << "Количество элементов в дереве: " << u_tree.count(u_tree.getRoot()) << endl;*/

	cout << "Сумма элементов: " << tree.sum(tree.getRoot()) << endl;
	cout << "Cреднее-арифметическое элементов дерева: " << tree.avg(tree.getRoot()) << endl;
	cout << "Глубина дерева: " << tree.depth(tree.getRoot()) << endl;
}