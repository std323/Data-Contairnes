#include<iostream>
using namespace std;

#define tab "\t"
#define delimiter   "\n----------------------------------\n"

class List
{
	class Element
	{
		int Data; //значение элемента
		Element* pNext;//указатель на следующий элемент
		Element* pPrev;//указатель на предыдущий элемент
	public:
		Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr) : Data(Data), pNext(pNext), pPrev(pPrev)
		{
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t" << this << endl;
		}
		friend class List;
	}*Head, *Tail;//Обьекты и указатели на обьекты можно обьявлять сразу же после описания класса
	size_t size;
public:
	List()
	{
		Head = Tail = nullptr;
		size = 0;
		cout << "LConstructor:\t" << this << endl; 
	}
	~List()
	{
		cout << "LDestructor:\t" << this << endl;
	}

	//                 Adding elements:
	void push_front(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head = Tail = new Element(Data);
			size++;
			return;
		}
		Element* New = new Element(Data);
		New->pNext = Head; 
		Head->pPrev = New;
		Head = New;
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr && Tail == nullptr)return push_front(Data);
		Element* New = new Element(Data);
		New->pPrev = Tail;
		Tail->pNext = New;
		Tail = New;
		size++;
	}

	//      Removing elements:
	void pop_front()
	{
		if (Head == nullptr && Tail == nullptr)return;
		Element* Erased = Head; //1) Запоминаем адрес удаляемого элемента
		Head = Head->pNext;     //2) Исключаем удаляемый элемент из списка
		Head->pPrev = Erased;
		delete Erased;          //3) Удаляем элемент из памяти
		size--;
	}

	

	//                Methods:

	void print()const
	{
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << "Количество элементов списка: " << size << endl;
	}

	void reverse_print()const
	{
		for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
			cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;

		cout << "Количество элементов списка: " << size << endl;
	}

	
};

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер списка: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
		//list.push_back(rand() % 100);
		
		
	}
	list.print();
	//list.reverse_print();
	//list.pop_front();
	list.print();
}