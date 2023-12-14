#include "Stack_Instance.hpp"

std::array<int, 100> Stack_Instance::m_stack{ 0 };
Stack_Instance::status Stack_Instance::m_statusOfStack = status::OPEN;


bool Stack_Instance::push_back( int value )
{
	if( m_statusOfStack == status::LOCKED )
	{
		if( m_I_am_LockingStack )
		{
			if( m_index < 100 )
			{
				std::cout << "Uspjesno dodan element na stack!\n";
				m_stack[++m_index] = value;
				return true;
			}
			else { std::cout << "Stack popunjen!\n"; }
		}
		else { std::cout << "Access denied!\n"; }
	}
	else { std::cout << "Stack je slobodan, ali ovaj objekt nije najprije zakljucao stack!\n"; }

	return false;
}

int Stack_Instance::pop()
{
	if( is_stack_locked() == status::LOCKED )
	{
		if( m_I_am_LockingStack )
		{
			if( m_index > 0 )
			{
				std::cout << "Uspjesno uklonjen element sa stacka!\n";
				return m_stack[--m_index];
			}
			else { std::clog << "Stack prazan!\n"; }
		}
		else { std::cerr << "Access denied!\n"; }
	}
	else { std::cout << "Stack je slobodan, ali ovaj objekt nije najprije zakljucao stack!\n"; }

	return -1;
}

void Stack_Instance::take_control()
{
	if( is_stack_locked() == status::LOCKED )	return;

	// else stack is ready for object to control it
	std::cout << "Stack is now locked by this object: " << this << "\n";
	m_statusOfStack = status::LOCKED;
	this->m_I_am_LockingStack = true;
}

void Stack_Instance::release_control()
{
	if( is_stack_locked() == status::OPEN )	return;

	if( check_have_access( *this ) )
	{
		std::cout << "Stack is now available for other objects!\n";
		m_statusOfStack = status::OPEN;
		this->m_I_am_LockingStack = false;
	}
	// else do nothing
}

Stack_Instance::status Stack_Instance::is_stack_locked() const { return m_statusOfStack; }

const Stack_Instance* const Stack_Instance::who_is_owner( const Stack_Instance* sIns, const size_t BROJ_INSTANCI)
{
	for( size_t i = 0; i < BROJ_INSTANCI; ++i )
	{
		if( check_have_access( *sIns ) )
		{
			std::cout << "i: " << i << ".\n";
			return sIns + i;
		}
	}
	return nullptr;
}

std::ostream& operator<<( std::ostream& out, const Stack_Instance& s )
{
	out << &s;
	return out;
}
