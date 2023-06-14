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
	cout << "������� ������ ������: "; cin >> n;
	Tree<int> tree;// = {50, 25, 75, 16, 32, 64, 80, 78};
	cout << "����������� �������� � ������: " << tree.minValue() << endl;
	cout << "������������ �������� � ������: " << tree.minValue() << endl;
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);
	}
	tree.print();

	cout << endl;
	cout << "����������� �������� � ������: " << tree.minValue() << endl;
	cout << "������������ �������� � ������: " << tree.maxValue() << endl;
	cout << "���������� ��������� � ������: " << tree.count() << endl;
	cout << "����� ���������: " << tree.sum() << endl;
	cout << "C������-�������������� ��������� ������: " << tree.avg() << endl;
	cout << "������� ������: " << tree.depth() << endl;

	int value;
	cout << "������� ��������� ��������: "; cin >> value;
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
	cout << "����������� �������� � ������: " << u_tree.minValue() << endl;
	cout << "������������ �������� � ������:" << u_tree.maxValue() << endl;
	cout << "���������� ��������� � ������: " << u_tree.count() << endl;

	cout << "����� ���������: " << u_tree.sum() << endl;
	cout << "C������-�������������� ��������� ������: " << u_tree.avg() << endl;
	cout << "������� ������: " << u_tree.depth() << endl;
#endif // BASE_CHEK

#ifdef DEPTH_CHEK
	Tree<int> tree = { 50, 25, 75, 16, 32, 64, 80, 68 };
	//tree.~Tree();
	tree.print();
	cout << "������� ������: " << tree.depth() << endl;

	//tree.print(0);
	tree.true_print();

	/*int value;
	cout << "������� ��������� ��������: "; cin >> value;
	tree.erase(value);
	tree.print();*/
#endif // DEPTH_CHEK

#ifdef PREFORMANCE_CHEK
	clock_t t_start, t_end;
	int n;
	cout << "������� ������ ������: "; cin >> n;
	Tree<int> tree;
	t_start = clock(); //������� 'clock()' 
	for (int i = 0; i < n; i++)
	{
		tree.insert(rand() % 100);
	}
	t_end = clock();
	cout << "������ ��������� ��: " << double(t_end - t_start) / CLOCKS_PER_SEC << " ���." << endl;
	//tree.print();

	measure<int>("����������� �������� � ������:\t ", tree, &Tree<int>::minValue);
	measure<int>("������������ �������� � ������:\t ", tree, &Tree<int>::maxValue);
	measure<int>("����� ��������� �����a:\t\t ", tree, &Tree<int>::sum);
	measure<int>("���������� ��������� � ������:\t ", tree, &Tree<int>::count);
	measure<double>("C������-�������������� ��������� ������:\t ", tree, &Tree<int>::avg);
	measure<int>("������� ������:\t\t\t ", tree, &Tree<int>::depth);




	/*t_start = clock();
	cout << "����������� �������� � ������: " << tree.minValue() << tab;
	t_end = clock();
	cout << double(t_end - t_start) / CLOCKS_PER_SEC << " ���." << endl;

	t_start = clock();
	cout << "������������ �������� � ������: " << tree.maxValue() << tab;
	t_end = clock();
	cout << double(t_end - t_start) / CLOCKS_PER_SEC << " ���." << endl;

	t_start = clock();
	cout << "���������� ��������� � ������: " << tree.count() << tab;
	t_end = clock();
	cout << double(t_end - t_start) / CLOCKS_PER_SEC << " ���." << endl;

	t_start = clock();
	cout << "����� ���������:\t " << tree.sum() << tab;
	t_end = clock();
	cout << double(t_end - t_start) / CLOCKS_PER_SEC << " ���." << endl;

	t_start = clock();
	cout << "C������-�������������� ��������� ������: " << tree.avg() << tab;
	t_end = clock();
	cout << double(t_end - t_start) / CLOCKS_PER_SEC << " ���." << endl;

	t_start = clock();
	cout << "������� ������: " << tree.depth() << tab;
	t_end = clock();
	cout << double(t_end - t_start) / CLOCKS_PER_SEC << " ���." << endl;*/


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
