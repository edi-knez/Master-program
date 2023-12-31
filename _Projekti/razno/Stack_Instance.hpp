#pragma once
#include <array>
#include <iostream>


class Stack_Instance
{
	friend std::ostream& operator <<( std::ostream& out, const Stack_Instance& sInst );

public:
	Stack_Instance() = default;
	Stack_Instance( const Stack_Instance& ) = default;
	Stack_Instance& operator= ( const Stack_Instance& ) = default;
	~Stack_Instance() = default;

public:
	[[nodiscard]] int size() { return m_index; }
	[[maybe_unused]] bool push_back( int value );
	[[maybe_unused]] int pop();

public:
	void take_control();
	void release_control();
	[[nodiscard]] static const Stack_Instance* const who_is_owner( const Stack_Instance* sIns, const size_t kolicina );

private:
	int m_index;
	bool m_I_am_LockingStack;
	static std::array<int, 100> m_stack;

private:
	static enum class status : bool
	{
		LOCKED = 0,
		OPEN
	} m_statusOfStack;

private:
	[[nodiscard]] Stack_Instance::status is_stack_locked() const;
	static friend const bool check_have_access( const Stack_Instance& this_stack );
};


[[nodiscard]] inline const bool check_have_access( const Stack_Instance& this_stack )
{
	return this_stack.m_I_am_LockingStack;
}