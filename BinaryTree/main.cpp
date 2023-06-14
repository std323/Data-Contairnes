#include"BinaryTree.h"
#include"BinaryTree.cpp"


//#define BASE_CHEK
//#define DEPTH_CHEK
//#define BALANCE_CHEK
//#define PREFORMANCE_CHEK

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHEK
	int n;
	cout << "Введите размер дерева: "; cin >> n;
	Tree<int> tree;// = {50, 25, 75, 16, 32, 64, 80, 78};
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


	UniqueTree<int> u_tree;
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
	Tree<int> tree = { 50, 25, 75, 16, 32, 64, 80, 68 };
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
	Tree<int> tree;
	t_start = clock(); //Функция 'clock()' 
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);
	}
	t_end = clock();
	cout << "Дерево заполнено за: " << double(t_end - t_start) / CLOCKS_PER_SEC << " сек." << endl;
	//tree.print();

	measure<int>("Минимальное значение в дереве:\t ", tree, &Tree<int>::minValue);
	measure<int>("Максимальное значение в дереве:\t ", tree, &Tree<int>::maxValue);
	measure<int>("Сумма элементов деревa:\t\t ", tree, &Tree<int>::sum);
	measure<int>("Количество элементов в дереве:\t ", tree, &Tree<int>::count);
	measure<double>("Cреднее-арифметическое элементов дерева:\t ", tree, &Tree<int>::avg);
	measure<int>("Глубина дерева:\t\t\t ", tree, &Tree<int>::depth);




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
	Tree<int> tree = { 3, 5, 8, 13, 21, 34, 55 };

	tree.true_print();
	tree.balance();
	tree.true_print();

#endif // BALANCE_CHEK

	Tree<double> tree = { 5.5, 2.5, 7.5, 1.6, 3.2, 6.4, 8.1 };
	tree.true_print();
}
