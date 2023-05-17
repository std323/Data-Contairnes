#include<iostream>
using namespace std;

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

class Element
{
	int Data; //Значение элемента
	Element* pNext;//Адрес следующего элемента
public:
	Element(int Data, Element* pNext = nullptr) : Data(Data), pNext(pNext)
	{
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		cout << "EDestructor:\t" << this << endl;
	}
	friend class Forwardlist;
};

class Forwardlist
{
	Element* Head; //Голова - это указатель на начальный элемент списка,
	//так же как в массиве, имя массива содержит адрес нулевого элемента,
	//Голова списка содержит адрес начального элемента.
public:
	Forwardlist()
	{
		Head = nullptr;//Когда список пуст, его голова указывает на 0
	cout << "LConstructor:\t" << this << endl;
	}
		~Forwardlist()
	{
		while (Head != nullptr)pop_front();
		cout << "LDestructor:\t" << this << endl;
		
	}
	
		//            Adding elements:
		void push_front(int Data)
		{
			Element* New = new Element(Data);//1) Cоздаем новый элемент
			New->pNext = Head; //2) Включаем новый элемент в список
			Head = New; //3) Переносим Голову на новый элемент

		}

		void insert(int Data, int Index)
		{
			//1) Cоздаем новый элемент:
			Element* New = new Element(Data);
			//2) Доходим до нужного элемента:
			Element* Temp = Head;
			for (int i = 0; i < Index - 1; i++)Temp = Temp->pNext;
			//3) Включаем созданный элемент в список:
			New->pNext = Temp->pNext;
			Temp->pNext = New;
		}

		//      Removing elements:
		
		void pop_front()
			{
			Element* Erased = Head; //1) Запоминаем адрес удаляемого элемента
			Head = Head->pNext;     //2) Исключаем удаляемый элемент из списка
			delete Erased;          //3) Удаляем элемент из памяти
			}

		void pop_back()
		{
			Element* Temp = Head;
			while (Temp->pNext->pNext)
			{
				Temp = Temp->pNext;
			}
			delete Temp->pNext;
			Temp->pNext = nullptr;
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
		}
		
		//  Methods:
		void print()const
		{
			/*
			----------------------
			Для того чтобы перемещаться по списку нужно две вещи:
			1. Итератор;
			2. Цикл;
			----------------------
			*/
			Element* Temp = Head; //Temp - это итератор.
			                      //Итератор - это указатель, при помощи которого можно получить доступ к элементам структуры данных
			while (Temp)
			{
				cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
				Temp = Temp->pNext; //Переход на следующий элемент
			}

		}
		void push_back(int Data)
		{
			if (Head == nullptr)return push_front(Data);
			Element* New = new Element(Data);
			Element* Temp = Head;
			while (Temp->pNext)
			{
				Temp = Temp->pNext;

			}
			Temp->pNext = New;
		}

};


void main()
{
	setlocale(LC_ALL, "");
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
	list.print();
	/*int value;
	int index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	cout << "Bведите индекс добавляемого элемента: "; cin >> index;
	//list.pop_back();
	list.insert(value, index);*/

	int index;
	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	list.erase(index);
	list.print();
}