#pragma once
#include <array>
#include <vector>
#include <iostream>
#include <memory>
#include <optional>

#include "nPog6.hpp"

#include "Zadaci_array.h"
#include "Zadaci_List.h"

struct treeNode
{
	treeNode(int initNum) : number(initNum) {}
	std::unique_ptr<treeNode> left = nullptr;
	std::unique_ptr<treeNode> right = nullptr;
	int number = -1;
};

class Poglavlje6
{
public: //  vjezbe	<---------------------------------------------------
	void vj1_parrots() const;
	void vj2_salary() const;
	void vj3_sum() const;
	void vj4_count_negative_numbers() const;
	void vj5_biggest_num_tree() const;
	//

public:	//	zadaci	<---------------------------------------------------
	void zad1_sum_of_positive_numbers() const;
	void zad2_binary_str_even_odd() const;
	void zad3_target_appeard() const;
	void zad4_tree_is_heap() const;
	void zad5_is_binary_search_tree() const;
	void zad6_insert_value_in_binary_search_tree() const;
};

/*
inline
void Poglavlje6::zad3() const
{
	static constexpr std::array brojevi{ 1, 2, 3, 4, 1, 2, 2, 5 };
	const int target1 = 2;
	Zadaci_array::zad3( brojevi, target1 );
	//Zadaci_List::zad3( brojevi, 2 );

}//*/
