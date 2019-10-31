#include <iostream>
#include <string>
#include <initializer_list>
#include <cstddef>

template <class T>
class List
{

	private:

//	size_t _size;
	typedef struct llist {
	T value;
	struct llist *next;
	struct llist *prev;
	} llist;
	
	llist *_head;
	llist *_tail;
	size_t _count;
	public:
	// default constructor
	List(){
		_head = 0;
		_tail = 0;
		_count = 0;
	}	

	// copy constructor
	//List(const List<T>&0 other)

	List(const std::initializer_list<T>& other)
	{
		_head = 0;
		_tail = 0;
		_count = 0;

		for (auto value : other)
			push_back(value);
	}
	// deconstructor
	~List()
	{
		while (!empty())
			pop_front();
	}
	// copy operator
	
	List& operator= (const List& a)
	{
		for (const llist* b = a._head; b != 0; b = b->next)
		{
			push_back(b->value);
		}
		return *this;
	}
	
	T& front()
	{
		return _head->value;
	}
	T& back()
	{
		return _tail->value;
	}

	const T& front() const
	{
		return _head->value;
	}

	const T& back() const
	{
		return _tail->value;
	}

	void push_front(T value)
	{
		llist *ptr = new llist;
		ptr->value = value;

		ptr->prev = NULL;
		ptr->next = _head;
		if (_head != NULL)
			_head->prev = ptr;
		if (_tail == NULL)
			_tail = ptr;
		_head = ptr;
		_count++;
	}

	void push_back (const T value)
	{ 
		llist *ptr = new llist;
		ptr->value = value;
		ptr->next = NULL;
		ptr->prev = _tail;
		if (_tail != NULL)
			_tail->next = ptr;
		if (_head == NULL)
			_head = ptr;
		_tail = ptr;

		_count++;
	}

	void pop_front()
	{
		llist *temp = _head;
		_head = _head->next;
		if (_head)
			_head->prev = _head->prev->prev;
		else 
			_tail = NULL;
		delete temp;
	}
	
	void pop_back ()
	{
		llist *temp = _tail;
		_tail = _tail->prev;
		if (_tail)
			_tail->next = _tail->next->next;
		else 
			_head = NULL;

		delete temp;
	}

	void reverse()
	{
		if ( size() <= 1)
			return;
		llist *newtail = _head;
		llist *temp;
		while (newtail != NULL)
		{
			temp = newtail->prev;
			newtail->prev = newtail->next;
			newtail->next = temp;
			newtail = newtail->prev;
		}

		if (temp)
			temp = temp->prev;
		_tail = _head;
		_head = temp;
	}
		
	bool empty() const
	{
		return size() == 0;
	}
	
	void clear()
	{
		while (!empty())
		{
			pop_back();
		}
	}
	
	void unique()
	{
		for (llist *i = _head; i != 0; i -> next)
		{
			while (i->next != 0 && i->value == i->next->value)
			{
				llist *save = i->next;
				i->next = save->next;

				if (save->next != 0)
				{
					save->next->prev = i;
					delete save;
				}
				else 
				{
					_tail = i;
					delete save;
				}
			}
		}
	}
	
	size_t size() const
	{
		size_t count = 0;
		if (_head == NULL)
			return count;
		if (_head == _tail)
		{
			count++;
			return count;
		}
		
		for (llist *temp = _head; temp != NULL;temp= temp->next, count++){}

		return count;
	}	
	
	template <typename V> friend bool operator ==(const List<V>& a, const List<V>& b);
	
	template <typename V> friend bool operator !=(const List<V>& a, const List<V>& b);
};

     template<typename T>
     bool operator == (const List<T>& a, const List<T>& b){
             if (a.size() != b.size())
                     return false;
             auto *aptr = a._head;
             auto *bptr = b._head;

             for ( ; aptr != nullptr && bptr != nullptr; aptr = aptr->next , bptr = bptr -> next)
             {
                     if (aptr -> value != bptr -> value)
                             return false;
             }
             return true;
     }

     template<typename T>
     bool operator != (const List<T>& a, const List<T>& b){
             if (a.size() != b.size())
                     return true;
             
	     auto *aptr = a._head;
             auto *bptr = b._head;

             for ( ; aptr != nullptr && bptr != nullptr; aptr = aptr->next , bptr = bptr -> next)
             {
                     if (aptr -> value != bptr -> value)
                             return true;
	     }
             return false;
     }
