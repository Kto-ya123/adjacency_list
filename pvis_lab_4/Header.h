#pragma once

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
template <typename T> struct  AdgList;

//struct of data
template <typename T> struct _Vertex //структура для хранения данных: вершина, содержит только значение и пару методов
{
	_Vertex(T _value) //конструктор
	{
		value = _value;
	}
	bool operator==(const _Vertex<T> a)const //перегруженный оператор сравнения == спецификатор const здесь показывает, что объект при выполнении данного метода не будет изменяться
	{
		return value == a.value; //само сравнение
	}
	bool operator!=(const _Vertex<T> a)const// ещё один оператор стравнения, структура у них у всех одна и та же
	{
		return value != a.value;
	}
	bool operator<=(const _Vertex<T> a)const
	{
		return value <= a.value;
	}
	bool operator>=(const _Vertex<T> a)const
	{
		return value >= a.value;
	}
	bool operator<(const _Vertex<T> a)const
	{
		return value < a.value;
	}
	bool operator>(const _Vertex<T> a)const
	{
		return value > a.value;
	}
	T value; // хранимое значение
};
//iterator
template <typename V> struct IteratorVertex //обычный итератор
{
public:
	friend AdgList<V>; //объявляем наш основной класс дружественным
	typedef V value_type; //value_type это тип который показывает какой тип мы храним
	IteratorVertex() : ptr(nullptr){} //стандартный конструктор
	typedef typename vector<pair<_Vertex<V>, vector<int>>>::iterator ins_iterator; //очень сложный тип у итератора поэтому затайпдэфил
	IteratorVertex(const ins_iterator& _ptr) :ptr(_ptr) {}  //конструктор, в осовном испольузется для инициализации функцией begin() и end() из основного класса
	IteratorVertex(const IteratorVertex& _ptr) :ptr(_ptr.ptr) {}//конструктор копирования

	IteratorVertex operator++() //оператор ++ (постфиксный)
	{
		return IteratorVertex(++ptr);	
	}
	IteratorVertex operator--() //постфиксный оператор
	{
		return IteratorVertex(--ptr);
	}
	
	value_type& operator*() //разыменование указателя
	{
		return ptr->first.value;
	}
	bool operator==(const IteratorVertex& ar) //операторы сравнения
	{
		return ar.ptr == ptr;
	}
	bool operator!=(const IteratorVertex& ar)
	{
		return !(ar.ptr == ptr);
	}
private:
	typename vector<pair<_Vertex<V>, vector<int>>>::iterator ptr; //сам итератор который указыает на элемент основного вектора из основного класса adgList
};
template <typename V> struct ConstIteratorVertex //в каждом итераторе всё почти одинаково
{
public:
	friend AdgList<V>;
	typedef V value_type;
	ConstIteratorVertex() : ptr(nullptr) {}
	typedef typename vector<pair<_Vertex<V>, vector<int>>>::const_iterator ins_iterator;
	ConstIteratorVertex(const ins_iterator& _ptr) :ptr(_ptr) {}
	ConstIteratorVertex(const ConstIteratorVertex& _ptr) :ptr(_ptr.ptr) {}
	ConstIteratorVertex operator++() 
	{
		return ConstIteratorVertex(++ptr);
	}
	ConstIteratorVertex operator--()
	{
		return ConstIteratorVertex(--ptr);
	}
	const value_type& operator*() const //когда возвращаю здесь константа поэтому нельзя изменять, остальное всё то же
	{
		return ptr->first.value;
	}
	bool operator==(const ConstIteratorVertex& ar)const
	{
		return ar.ptr == ptr;
	}
	bool operator!=(const ConstIteratorVertex& ar)const
	{
		return !(ar.ptr == ptr);
	}
private:
	typename vector<pair<_Vertex<V>, vector<int>>>::const_iterator ptr; //класс содержит константый итератор на элемент из основного класса adgList
};
template <typename V> struct ReverseIteratorVertex //здесь то же что и в основном итераторе только:смотреть в конце класса
{
	friend AdgList<V>;
	typedef V value_type;
	ReverseIteratorVertex() : ptr(nullptr) {}
	typedef typename vector<pair<_Vertex<V>, vector<int>>>::reverse_iterator ins_iterator;
	ReverseIteratorVertex(const ins_iterator& _ptr) :ptr(_ptr) {}
	ReverseIteratorVertex(const ReverseIteratorVertex& _ptr) :ptr(_ptr.ptr) {}
	ReverseIteratorVertex operator++()
	{
		return ReverseIteratorVertex(++ptr);
	}
	ReverseIteratorVertex operator--()
	{
		return ReverseIteratorVertex(--ptr);
	}
	value_type& operator*()
	{
		return ptr->first.value;
	}
	bool operator==(const ReverseIteratorVertex& ar)
	{
		return ar.ptr == ptr;
	}
	bool operator!=(const ReverseIteratorVertex& ar)
	{
		return !(ar.ptr == ptr);
	}
private:
	typename vector<pair<_Vertex<V>, vector<int>>>::reverse_iterator ptr; //содеражит реверсивный итератор на элемент класса


};
template <typename V> struct ConstReverseIteratorVertex //тоже самое что и реверсивный итератор кроме: смотреть функцию разыменования
{
	friend AdgList<V>;
	typedef V value_type;
	ConstReverseIteratorVertex() : ptr(nullptr) {}
	typedef typename vector<pair<_Vertex<V>, vector<int>>>::reverse_iterator ins_iterator;
	ConstReverseIteratorVertex(const ins_iterator& _ptr) :ptr(_ptr) {}
	ConstReverseIteratorVertex(const ConstReverseIteratorVertex& _ptr) :ptr(_ptr.ptr) {}
	ConstReverseIteratorVertex operator++()
	{
		return ReverseIteratorVertex(++ptr);
	}
	ConstReverseIteratorVertex operator--()
	{
		return ReverseIteratorVertex(--ptr);
	}
	const value_type& operator*() //возвращает константное значение
	{
		return ptr->first.value;
	}
	bool operator==(const ConstReverseIteratorVertex& ar)
	{
		return ar.ptr == ptr;
	}
	bool operator!=(const ConstReverseIteratorVertex& ar)
	{
		return !(ar.ptr == ptr);
	}
private:
	typename vector<pair<_Vertex<V>, vector<int>>>::reverse_iterator ptr;


}; 
template <typename V> struct IteratorEdgeIncidentVertex
{
public:
	friend AdgList<V>;
	IteratorEdgeIncidentVertex():ptr(nullptr) {}
	IteratorEdgeIncidentVertex(const pair<int, vector<int>::iterator>& _ptr) :number(_ptr.first), ptr(_ptr.second) {}
	IteratorEdgeIncidentVertex(const IteratorEdgeIncidentVertex* _ptr) : number(_ptr.number), ptr(_ptr.ptr) {}

	IteratorEdgeIncidentVertex operator++()
	{
		return IteratorEdgeIncidentVertex(pair<int, vector<int>::iterator>{number, ++ptr});
	}
	IteratorEdgeIncidentVertex operator--()
	{
		return IteratorEdgeIncidentVertex(pair<int, vector<int>::iterator>{number, --ptr});
	}
	pair<int, int> operator*()
	{
		return (pair<int, int>{number, *ptr});
	}

	bool operator==(const IteratorEdgeIncidentVertex& ar)
	{
		return (ar.ptr == ptr && number == ar.number);
	}
	bool operator!=(const IteratorEdgeIncidentVertex& ar)
	{
		return !(ar.ptr == ptr && number == ar.number);
	}
private:
	int number;
	vector<int>::iterator ptr;

};
template <typename V> struct ReverseIteratorEdgeIncidentVertex
{
public:
	friend AdgList<V>;
	ReverseIteratorEdgeIncidentVertex() :ptr(nullptr) {}
	ReverseIteratorEdgeIncidentVertex(const pair<int, vector<int>::reverse_iterator>& _ptr) :number(_ptr.first), ptr(_ptr.second) {}
	ReverseIteratorEdgeIncidentVertex(const ReverseIteratorEdgeIncidentVertex* _ptr) : number(_ptr.number), ptr(_ptr.ptr) {}

	ReverseIteratorEdgeIncidentVertex operator++()
	{
		return ReverseIteratorEdgeIncidentVertex(pair<int, vector<int>::iterator>{number, ++ptr});
	}
	ReverseIteratorEdgeIncidentVertex operator--()
	{
		return ReverseIteratorEdgeIncidentVertex(pair<int, vector<int>::iterator>{number, --ptr});
	}
	pair<int, int> operator*()
	{
		return (pair<int, int>{number, *ptr});
	}

	bool operator==(const ReverseIteratorEdgeIncidentVertex& ar)
	{
		return (ar.ptr == ptr && number == ar.number);
	}
	bool operator!=(const ReverseIteratorEdgeIncidentVertex& ar)
	{
		return !(ar.ptr == ptr && number == ar.number);
	}
private:
	int number;
	vector<int>::reverse_iterator ptr;

};

//epmty iterator
template <typename V> struct _IteratorEdge
{

};
template <typename V> struct _ReverseIteratorEdge
{

};
template <typename V> struct _IteratorVertexAdgacentVertex
{

};
template <typename V> struct ReverseIteratorVertexAdgacentVertex
{

};




template <typename T> struct  AdgList
{
	typedef T value_type; //тип хранимого элемента
	typedef _Vertex<T> Vertex; //делает из обобщённого класса, класс с определённым типом
	//итераторы, чтобы обращение к ним в классе было проще
	typedef IteratorVertex<T> iterator; 
	typedef ReverseIteratorVertex<T> reverse_iterator;
	typedef ConstIteratorVertex<T> const_iterator;
	typedef ConstReverseIteratorVertex<T> const_reverse_iterator;
	typedef IteratorEdgeIncidentVertex<T> iterator_inc_edge; //итератор вершин инцидентных данной
	typedef ReverseIteratorEdgeIncidentVertex<T> reverse_iterator_inc_edge;//тоже итератор вершин но реверсивный
	friend ostream& operator<< <T>(ostream&, const AdgList<T>&);
	//constructors
	AdgList() {}
	AdgList(const AdgList<T>& _adglist) //конструктор копирования
	{
		this->vec = _adglist.vec;
	}
	//--------------------------
	bool empty() //пустой ли
	{
		return vec.empty(); //возвращает значение основного вектора лежащего в поле private снизу класса
	} 
	void clear() // очищает класс
	{
		while (!vec.empty()) //пока не пустой, просто убирает элементы из основного вектора, который лежи в private
		{
			vec.pop_back();
		}
	}
	void addVertex(T _value, int n, ...)//добавляем вершину , в объявлении это функция с переменным количеством параметров
	{
		vector<int> vr; //вектор вершин смежной с данной
		int* p = &n; //устанавливаем указатель на первый известный аргумент
		while (*p) //проходим по массиву аргументов и если аргумент не равен нулю то тогда добавляем его в вектор вершин смежной с данной
		{
			if (*p > vec.size()) // если номер вершины больше чем размер основного вектора, то пытаемся создать ребро к несуществующей вершине.. выбрасываем исключение
				throw exception("Not find Vertex");
			//(*p)--;
			vr.push_back(*p); //добавляем вершину 
			p++;
		}
		vec.push_back(pair<Vertex, vector<int>>({_value }, { vr }));
		for (int i(0); i < vr.size(); i++)
		{
			vec[vr[i]-1].second.push_back(vec.size());
		}

	}
	void addEdge(int firstVert, int secondVert)
	{
		if (firstVert > 0 && secondVert > 0)
		{
			if (firstVert-1 < vec.size() && secondVert-1 < vec.size())
			{
				if (!checkEdge(firstVert, secondVert))
				{
					firstVert--;
					vec[firstVert++].second.push_back(secondVert--);
					vec[secondVert].second.push_back(firstVert);
					
				}
				else
				{
					throw exception("have this edge");
				}

			}
			else
			{
				throw exception("Not find Vertex");

			}
		}
		else
		{
			throw exception("Not find Vertex");
		}
		
	}
	void deleteEdge(int firstVert, int secondVert)
	{
		if (firstVert > 0 && secondVert > 0)
		{
			if (firstVert - 1 < vec.size() && secondVert - 1 < vec.size())
			{
				firstVert--;
				auto it = find(vec[firstVert].second.begin(), vec[firstVert].second.end(), secondVert);
				if (it != vec[firstVert].second.end())
				{
					vec[firstVert].second.erase(it, it + 1);
				}
				firstVert++;
				secondVert--;
				it = find(vec[secondVert].second.begin(), vec[secondVert].second.end(), firstVert);
				if (it != vec[secondVert].second.end())
				{
					vec[secondVert].second.erase(it, it + 1);
				}
			}
			else
			{
				throw exception("Not found Vertex");
			}
		}
		else
		{
			throw exception("Not found Vertex");
		}
	}
	void deleteVertex(T val)
	{
		if (empty())
		{
			throw exception("Not found");
		}
		int number = 0;
		for (; vec[number].first.value != val; number++)
		{
			;
		}
		if (number == vec.size())
		{
			throw exception("Not found");
		}
		for (auto it = vec.begin(); it != vec.end(); it++)
		{
			auto it_find = find(it->second.begin(), it->second.end(), number + 1);
			if (it_find != it->second.end())
			{
				it->second.erase(it_find, it_find + 1);
			}
			for (auto it_in = it->second.begin(); it_in != it->second.end(); it_in++)
			{
				if (*it_in > number + 1)
				{
					(*it_in)--;
				}
			}
		}
		vec.erase(vec.begin() + number, vec.begin() + number + 1);
	}
	bool checkVertex(T value)
	{
		for (int i(0); i < vec.size(); i++)
		{
			if (vec[i].first.value == value)
				return true;
		}
		return false;
	}
	bool checkEdge(int vertFirst, int vertSecond)
	{
		vertFirst--;
		for (auto it_in = vec[vertFirst].second.begin(); it_in < vec[vertFirst].second.end(); it_in++)
		{
			if (*it_in == vertSecond)
				return true;
		}
		return false;
	}
	int quantVertex()
	{
		return vec.size();
	}
	int quantEdge()
	{
		int sum = 0;
		for (auto it = vec.begin(); it < vec.end(); it++)
		{
			sum += it->second.size();
		}
		return sum / 2;
	}
	int powerVertex(T value)
	{
		auto it = vec.begin();
		for (; it < vec.end(), value != it->first.value; it++)
		{
			;
		}
		if (it == vec.end())
		{
			throw exception("Not find Vertex");
		}
		else
		{
			return it->second.size();
		}
	}
	
	//----------------------------------------------
	//function of iterator
	typename iterator begin()
	{
		return iterator(vec.begin());
	}
	typename iterator end()
	{
		return iterator(vec.end());
	}
	typename reverse_iterator rbegin()
	{
		return reverse_iterator(vec.rbegin());
	}
	typename reverse_iterator rend()
	{
		return reverse_iterator(vec.rend());
	}
	typename const_iterator cbegin()
	{
		return const_iterator(vec.cbegin());
	}
	typename const_iterator cend()
	{
		return const_iterator(vec.cend());
	}
	typename const_reverse_iterator crbegin()
	{
		return const_reverse_iterator(vec.crbegin());
	}
	typename const_reverse_iterator crend()
	{
		return const_reverse_iterator(vec.crend());
	}
	void erase(iterator it)
	{
		vec.erase(it.ptr, it.ptr + 1);
	}
	void erase(const_iterator it)
	{
		vec.erase(it.ptr, it.ptr + 1);
	}
	void eraseEdge(iterator_inc_edge it)
	{
		deleteEdge(it.number, *(it.ptr));
	}
	void eraseEdge(reverse_iterator_inc_edge it)
	{
		deleteEdge(it.number, *(it.ptr));
	}
	typename iterator_inc_edge ibegin(T value)
	{
		int i = 0;
		for (; i < vec.size(), vec[i].first.value != value; i++)
		{
			;
		}
		if (vec[i].first.value != value)
			throw exception("Not found Vertex");
		return iterator_inc_edge(pair<int, vector<int>::iterator>{i+1, vec[i].second.begin()});
	}
	typename iterator_inc_edge iend(T value)
	{
		int i = 0;
		for (; i < vec.size(), vec[i].first.value != value; i++)
		{
			;
		}
		if (vec[i].first.value != value)
			throw exception("Not found Vertex");
		return iterator_inc_edge(pair<int, vector<int>::iterator>{i+1, vec[i].second.end()});

	}
	typename reverse_iterator_inc_edge irbegin(T value)
	{
		int i = 0;
		for (; i < vec.size(), vec[i].first.value != value; i++)
		{
			;
		}
		if (vec[i].first.value != value)
			throw exception("Not found Vertex");
		return reverse_iterator_inc_edge(pair<int, vector<int>::reverse_iterator>{i+1, vec[i].second.rbegin()});
	}
	typename reverse_iterator_inc_edge irend(T value)
	{
		int i = 0;
		for (; i < vec.size(), vec[i].first.value != value; i++)
		{
			;
		}
		if (vec[i].first.value != value)
			throw exception("Not found Vertex");
		return reverse_iterator_inc_edge(pair<int, vector<int>::reverse_iterator>{i+1, vec[i].second.rend()});

	}
	//-----------------------------------------------
	//operation for compare
	void operator=(const AdgList<T>& _adglist)
	{
		vec = _adglist.vec;
	}
	bool operator==(const AdgList<T> a)
	{
		return vec == a.vec;
	}
	bool operator!=(const AdgList<T>& _adglist)
	{
		return vec != _adglist.vec;
	}
	bool operator<=(const AdgList<T>& _adglist)
	{
		return vec <= _adglist.vec;
	}
	bool operator>=(const AdgList<T>& _adglist)
	{
		return vec >= _adglist.vec;
	}
	bool operator<(const AdgList<T>& _adglist)
	{
		return vec < _adglist.vec;
	}
	bool operator>(const AdgList<T>& _adglist)
	{
		return vec > _adglist.vec;
	}
	//--------------------------------------------------
private:
	vector<pair<Vertex, vector<int>>> vec; 
};


template <typename V> 
	ostream& operator<< (ostream& os, const AdgList<V>& _adglist)
{
	for (int i(0); i < _adglist.vec.size(); i++)
	{
		os << i+1 << " - " << _adglist.vec[i].first.value << " : ";
		for (auto it_in = _adglist.vec[i].second.begin(); it_in != _adglist.vec[i].second.end(); it_in++)
		{
			os << *it_in << " ";
		}
		os << endl;
		
	}
	return os;
}