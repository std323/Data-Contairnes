#include<iostream>
#include<time.h>

using namespace std;

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n-------------------------------------------\n"

class Element
{
	int Data; //Значение элемента
	Element* pNext;//Адрес следующего элемента
	static int count; //Cчетчик элементов
public:
	
	Element(int Data, Element* pNext = nullptr) : Data(Data), pNext(pNext)
	{
		count++;
#ifdef DEBUG
		cout << "EConstructor:\t" << this << endl;
#endif // DEBUG

	}
	~Element()
	{
		count--;
#ifdef DEBUG
		cout << "EDestructor:\t" << this << endl;
#endif // DEBUG
	}
	friend class Forwardlist;
	friend class Iterator;
};

int Element::count = 0;//Cтатическую переменную можно проинициализировать только за пределами класса
class Iterator
{
	Element* Temp;
public:
	Iterator(Element* Temp) :Temp(Temp)
	{
		cout << "ItConstructor:\t" << this << endl;
	}
	~Iterator()
	{
		cout << "ItDestructor:\t" << this << endl;
	}
	
	Iterator& operator++()
	{
		Temp = Temp->pNext;
		return *this;
	}

	bool operator==(const Iterator& other)const
	{
		return this->Temp == other.Temp;
	}
	bool operator!=(const Iterator& other)const
	{
		return this->Temp != other.Temp;
	}

	int& operator*()
	{
		return Temp->Data;
	}
};

class Forwardlist
{
	Element* Head; //Голова - это указатель на начальный элемент списка,
	//так же как в массиве, имя массива содержит адрес нулевого элемента,
	//Голова списка содержит адрес начального элемента.
	unsigned int size;  //Количество элементов списка
public:
	Iterator begin()
	{
		return Head;
	}
	Iterator end()
	{
		return nullptr;
	}
	Forwardlist()
	{
		Head = nullptr;//Когда список пуст, его голова указывает на 0
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	Forwardlist(const Forwardlist& other) :Forwardlist()
	{
		/*Element* Temp = other.Head;
		while (Temp)
		{
			push_back(Temp->Data);
			Temp = Temp->pNext;
		}*/
		*this = other;  //Пвторно используем код оператора =
		cout << "CopyConstructor: " << this << endl;
	}

	Forwardlist(const initializer_list<int>& il) :Forwardlist()
	{
		cout << typeid(il.begin()).name() << endl;
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
	}

	~Forwardlist()
	{
		while (Head)pop_front();
		cout << "LDestructor:\t" << this << endl;

	}
	//    Operators:
	Forwardlist& operator=(const Forwardlist& other)
	{
		if (this == &other)return*this;
		while (Head)pop_front();
		/*Element* Temp = other.Head;
		while (Temp)
		{
			push_back(Temp->Data);
			Temp = Temp->pNext;
		}*/
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)push_front(Temp->Data);
		reverse();
		cout << "CopyAssignment:\t" << this << endl;
		return *this;

	}

	//            Adding elements:
	void push_front(int Data)
	{
		/*Element* New = new Element(Data);//1) Cоздаем новый элемент
		New->pNext = Head; //2) Включаем новый элемент в список
		Head = New; //3) Переносим Голову на новый элемент*/

		Head = new Element(Data, Head);
		size++;

	}

	void push_back(int Data)
	{
		if (Head == nullptr)return push_front(Data);
		Element* Temp = Head;
		while (Temp->pNext)
		{
			Temp = Temp->pNext;

		}
		Temp->pNext = new Element(Data);

		size++;
	}

	void insert(int Data, int Index)
	{
		if (Index == 0)return push_front(Data);
		if (Index > size)return;
		//1) Cоздаем новый элемент:
		//Element* New = new Element(Data);
		//2) Доходим до нужного элемента:
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)Temp = Temp->pNext;
		//3) Включаем созданный элемент в список:
		//New->pNext = Temp->pNext;
		Temp->pNext = new Element(Data, Temp->pNext);
		size++;
	}

	//      Removing elements:

	void pop_front()
	{
		Element* Erased = Head; //1) Запоминаем адрес удаляемого элемента
		Head = Head->pNext;     //2) Исключаем удаляемый элемент из списка
		delete Erased;          //3) Удаляем элемент из памяти
		size--;
	}

	void pop_back()
	{
		if (Head->pNext == nullptr)return pop_front();
		Element* Temp = Head;
		while (Temp->pNext->pNext)
		{
			Temp = Temp->pNext;
		}
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}

	void erase(int index)
	{
		if (index < 0)return;
		if (index == 0)return pop_front();
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)Temp = Temp->pNext;
		Element* Erased = Temp->pNext;
		Temp->pNext = Temp->pNext->pNext;
		delete Erased;
		size--;
	}

	//  Methods:

	void reverse()
	{
		Forwardlist reverse;
		while (Head)
		{
			reverse.push_front(Head->Data);
			pop_front();
			size++;
		}
		this->Head = reverse.Head;
		reverse.Head = nullptr;
	}
	
	void print()const
	{
		/*
		----------------------
		Для того чтобы перемещаться по списку нужно две вещи:
		1. Итератор;
		2. Цикл;
		----------------------
		*/
		cout << "\n----------------------" << this << "--------------\n";
		cout << "Head : " << Head << endl;
		/*Element* Temp = Head; //Temp - это итератор.
		//Итератор - это указатель, при помощи которого можно получить доступ к элементам структуры данных
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext; //Переход на следующий элемент
		}*/

		for(Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;

		cout << "Количество элементов списка: " << size << endl;
		cout << "Общее количество элементов: " << Head->count << endl;
	}

};

//#define BASE_CHEK
//#define COPY_CHEK
//#define PREFORMANCE_CHEK
//#define RANGE_BASED_FOR_ARRAY



void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHEK
	int n;
	cout << "Введите размер списка: "; cin >> n;
	Forwardlist list;
	for (int i = 0; i < n; i++)
	{
		int number = rand() % 100;
		cout << number << tab;
		//list.push_front(rand() % 100);
		list.push_back(number);
	}
	//list.push_back(123);
	list = list;
	list.print();
	/*int value;
	int index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	cout << "Bведите индекс добавляемого элемента: "; cin >> index;
	//list.pop_back();
	list.insert(value, index);
	list.print();*/

	/*int index;
	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	list.erase(index);
	list.print();*/

	/*Forwardlist list2;
	list2.push_back(1024);
	list2.push_back(2048);
	list2.push_back(3072);
	list2.push_back(4096);

	list.print();*/
#endif // BASE_CHEK


#ifdef COPY_CHEK
	/*Forwardlist list2 = list;
//Forwardlist list2;
//list2.push_back(1024);
//list2.push_back(2048);
//list2.push_back(3072);
//list2.push_back(4096);
list2 = list;
list.print();
list2.print();*/
#endif // COPY_CHEK

#ifdef PREFORMANCE_CHEK
	int n;
	cout << "Введите размер списка: "; cin >> n;
	Forwardlist list;
	cout << "Список создан, идет загрузка данных" << endl;
	clock_t t_start = clock();

	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	clock_t t_end = clock();
	cout << "Данные загружены за " << double(t_end - t_start) / CLOCKS_PER_SEC << endl;
	//list.print();
	cout << delimiter << endl;
	cout << "Копируем список: " << endl;
	t_start = clock();
	Forwardlist list2 = list;
	t_end = clock();
	cout << "Cписок скопирован за " << double(t_end - t_start) / CLOCKS_PER_SEC << " cекунд" << endl;
	//list2.print();  
#endif // PREFORMANCE_CHEK

#ifdef RANGE_BASED_FOR_ARRAY
	int arr[] = { 3, 5, 8,13,21 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;

	//Range-base for:
	//В данном случае range (диапазон) - это структура данных, для которой должен выполнится 'for'
	for (int i : arr)
	{
		cout << i << tab;
	}
	cout << endl;
#endif // RANGE_BASED_FOR_ARRAY

	Forwardlist list = { 3, 5, 8, 13, 21 };
	//list.print();
	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;
}