#include "Poglavlje6.h"


//? -------------------------------------->	VJEZBE	<----------------------------------------------------
using namespace POG_6;
void Poglavlje6::vj1_parrots() const
{
	std::cout << "Broj papiga: " << POG_6::vj_1::how_many_parots() << "\n";
}

void Poglavlje6::vj2_salary() const
{
	std::cout << "Highest salary: " << vj_2::highest_salary( vj_2::getInput(), 0 ) << "\n";
}

void Poglavlje6::vj3_sum() const
{
	std::cout << "sum: " << vj_3::sum( vj_3::Input::numbers ) << "\n";
}

void Poglavlje6::vj4_count_negative_numbers() const
{
	std::cout << "negativnih brojeva u listi je: " << vj_4::cnt_neg_num() << "\n";
}

void Poglavlje6::vj5_biggest_num_tree() const
{
	std::cout << "najveci broj u stablu: " << vj_5::execute() << '\n';
}

//? ----------------------------------------->	ZADACI	<------------------------------------------------
void ispisBrojeva( const treeNode* root );
void ispisStabla( const char* ime, const treeNode* root )
{
	std::puts( ime );
	ispisBrojeva( root );
	std::puts( "\n" );
}
void ispisBrojeva( const treeNode* root )
{
	if( root == nullptr )	return;

	ispisBrojeva( root->left.get() );
	std::cout << root->number << " ";
	ispisBrojeva( root->right.get() );
}

void Poglavlje6::zad1_sum_of_positive_numbers() const
{
	static constexpr std::array numbers = { 1, 5, -4, 100, -54, 0 , 5, -54, 100 };
	Zadaci_array::zad1( numbers );
	Zadaci_List::zad1( numbers );
	std::puts( "-----------------------\n" );
}

void Poglavlje6::zad2_binary_str_even_odd() const
{
	static constexpr std::array binaryString1{ '1', '1', '0', '0', '1', '0', '1' };
	static constexpr std::array binaryString2{ '1', '1', '1', '0', '1', '0', '1' };
	static constexpr std::array binaryString3{ '0', '0', '0', '0', '0', '0', '0' };

	Zadaci_array::zad2( binaryString1 );
	Zadaci_List::zad2( binaryString1 );
	std::puts( "-----------------------\n" );
	Zadaci_array::zad2( binaryString2 );
	Zadaci_List::zad2( binaryString2 );
	std::puts( "-----------------------\n" );
	Zadaci_array::zad2( binaryString3 );
	Zadaci_List::zad2( binaryString3 );
	std::puts( "-----------------------\n" );

}

void Poglavlje6::zad3_target_appeard() const
{
	static constexpr std::array brojevi{ 1, 2, 3, 4, 1, 2, 2, 5 };
	Zadaci_array::zad3( brojevi, 2 );
	Zadaci_List::zad3( brojevi, 2 );
	std::puts( "-----------------------\n" );
	Zadaci_array::zad3( brojevi, 0 );
	Zadaci_List::zad3( brojevi, 0 );
	std::puts( "-----------------------\n" );
}


static std::unique_ptr<treeNode> setupTreeFrom( const auto& brojevi )
{
	auto retVal = std::make_unique<treeNode>( brojevi.at( 0 ) );
	auto Lleft1 = std::make_unique<treeNode>( brojevi.at( 1 ) );
	auto Lleft2 = std::make_unique<treeNode>( brojevi.at( 2 ) );
	auto Lright2 = std::make_unique<treeNode>( brojevi.at( 3 ) );
	auto Rright1 = std::make_unique<treeNode>( brojevi.at( 4 ) );
	auto Rleft2 = std::make_unique<treeNode>( brojevi.at( 5 ) );
	auto Rright2 = std::make_unique<treeNode>( brojevi.at( 6 ) );

	Rright1->left = std::move( Rleft2 );
	Rright1->right = std::move( Rright2 );
	retVal->right = std::move( Rright1 );

	Lleft1->left = std::move( Lleft2 );
	Lleft1->right = std::move( Lright2 );
	retVal->left = std::move( Lleft1 );

	return retVal;
}

bool test_heap( const std::unique_ptr<treeNode>& node );
void Poglavlje6::zad4_tree_is_heap() const
{
	static constexpr std::array brojevi1{ 1, 2, 3, 4, 5, 6, 7 };
	static constexpr std::array brojevi2{ 5, 4, 3, 1, 2, 6, 7 };
	static constexpr std::array brojevi3{ 7, 6, 5, 4, 3, 2, 1 };
	static constexpr std::array brojevi4{ 5 };
	static constexpr std::array brojevi5{ 5, 4 };

	std::unique_ptr<treeNode> root1 = setupTreeFrom( brojevi1 );
	ispisStabla( "root1", root1.get() );
	std::cout << "root1 ima heap strukturu: " << ( ( test_heap( root1 ) == true ) ? "true" : "false" );
	std::puts( "\n-----------------------\n" );

	std::unique_ptr<treeNode> root2 = setupTreeFrom( brojevi2 );
	ispisStabla( "root2", root2.get() );
	std::cout << "root2 ima heap strukturu: " << ( ( test_heap( root2 ) == true ) ? "true" : "false" );
	std::puts( "\n-----------------------\n" );

	std::unique_ptr<treeNode> root3 = setupTreeFrom( brojevi3 );
	ispisStabla( "root3", root3.get() );
	std::cout << "root3 ima heap strukturu: " << ( ( test_heap( root3 ) == true ) ? "true" : "false" );
	std::puts( "\n-----------------------\n" );

	auto root4 = std::make_unique<treeNode>( brojevi4.front() );
	ispisStabla( "root4", root4.get() );
	std::cout << "root4 ima heap strukturu: " << ( ( test_heap( root4 ) == true ) ? "true" : "false" ) << " (edge case: only 1 node in tree)";
	std::puts( "\n-----------------------\n" );

	auto root5 = std::make_unique<treeNode>( brojevi5.front() );
	root5->left = std::make_unique<treeNode>( brojevi5.back() );
	ispisStabla( "root5", root5.get() );
	std::cout << "root5 ima heap strukturu: " << ( ( test_heap( root5 ) == true ) ? "true" : "false" ) << " (edge case: only 2 node in tree)";
	std::puts( "\n-----------------------\n" );

	std::unique_ptr<treeNode> root6 = nullptr;
	ispisStabla( "root6", root6.get() );
	std::cout << "root6 ima heap strukturu: " << ( ( test_heap( root6 ) == true ) ? "true" : "false" ) << " (edge case: root == nullptr)";
	std::puts( "\n-----------------------\n" );
}

bool test_heap( const std::unique_ptr<treeNode>& node )
{
	if( node == nullptr )	return false; // empty node
	const bool existLeft = node->left != nullptr;
	const bool existRight = node->right != nullptr;
	const bool expression = uint8_t( ( existLeft && node->number > node->left->number ) + ( existRight && node->number > node->right->number ) ) == existLeft + existRight;
	bool evaluation;
	if( existLeft )						evaluation = expression && test_heap( node->left );
	if( existRight )					evaluation = expression && test_heap( node->right );

	if( !existLeft & !existRight )		return true;
	else								return evaluation;
}

static bool test_binaryTree( const treeNode* node );
void Poglavlje6::zad5_is_binary_search_tree() const
{
	// 1 2 3 4 5 6 7

	//		4
	//	2		6
	// 1   3   5    7
	static constexpr std::array brojevi1{ 1, 2, 3, 4, 5, 6, 7 };
	static constexpr std::array brojevi2{ 4, 2, 1, 3, 6, 5, 7 };
	static constexpr std::array brojevi3{ 7, 6 };
	static constexpr std::array brojevi4{ 6, 7 };
	static constexpr std::array brojevi5{ 5 };
	static constexpr std::array<int, 0> brojevi6{};


	std::unique_ptr<treeNode> root1 = setupTreeFrom( brojevi1 );
	ispisStabla( "root1", root1.get() );
	std::cout << "root1 ima binary search tree strukturu: " << ( ( test_binaryTree( root1.get() ) == true ) ? "true" : "false" );
	std::puts( "\n-----------------------\n" );

	std::unique_ptr<treeNode> root2 = setupTreeFrom( brojevi2 );
	ispisStabla( "root2", root2.get() );
	std::cout << "root2 ima binary search tree strukturu: " << ( ( test_binaryTree( root2.get() ) == true ) ? "true" : "false" );
	std::puts( "\n-----------------------\n" );

	std::unique_ptr<treeNode> root3 = std::make_unique<treeNode>( brojevi3.front() );
	root3->left = std::make_unique<treeNode>( brojevi3.back() );
	ispisStabla( "root3", root3.get() );
	std::cout << "root3 ima binary search tree strukturu: " << ( ( test_binaryTree( root3.get() ) == true ) ? "true" : "false" ) << " (edge case: 1 node [on lef side])";
	std::puts( "\n-----------------------\n" );

	std::unique_ptr<treeNode> root4 = std::make_unique<treeNode>( brojevi4.front() );
	root4->right = std::make_unique<treeNode>( brojevi4.back() );
	ispisStabla( "root4", root4.get() );
	std::cout << "root4 ima binary search tree strukturu: " << ( ( test_binaryTree( root4.get() ) == true ) ? "true" : "false" ) << " (edge case: 1 node [on right side])";
	std::puts( "\n-----------------------\n" );

	auto root5 = std::make_unique<treeNode>( brojevi5.front() );
	ispisStabla( "root5", root5.get() );
	std::cout << "root5 ima binary search tree strukturu: " << ( ( test_binaryTree( root5.get() ) == true ) ? "true" : "false" ) << " (edge case: only 1 node)";
	std::puts( "\n-----------------------\n" );

	std::unique_ptr<treeNode> root6 = nullptr;
	ispisStabla( "root6", root6.get() );;
	std::cout << "root6 ima binary search tree strukturu: " << ( ( test_binaryTree( root6.get() ) == true ) ? "true" : "false" ) << " (edge case: root == nullptr)";
	std::puts( "\n-----------------------\n" );
}

static bool test_binaryTree( const treeNode* node )
{
	if( node == nullptr ) return false;
	const bool existLeft = node->left != nullptr;
	const bool existRight = node->right != nullptr;
	const bool expression = uint8_t( ( existLeft && node->number > node->left->number ) + ( existRight && node->number < node->right->number ) ) == existLeft + existRight;
	bool evaluate;
	if( existLeft )		evaluate = expression && test_binaryTree( node->left.get() );
	if( existRight )	evaluate = expression && test_binaryTree( node->right.get() );

	if( !existLeft && !existRight )	return true;
	else							return evaluate;
}

void insertInto( std::unique_ptr<treeNode>& root, int value );
void Poglavlje6::zad6_insert_value_in_binary_search_tree() const
{
	static constexpr std::array brojevi1{ 6, 3, 1, 5, 9, 7, 10 };
	static constexpr std::array brojevi2{ 7, 6 };	// node lijevo
	static constexpr std::array brojevi3{ 6, 7 };	// node desno
	static constexpr std::array brojevi4{ 5 };		// samo root
	static constexpr std::array<int, 0> brojevi5{};	// nema roota

	auto root1 = setupTreeFrom( brojevi1 );
	ispisStabla( "root1", root1.get() );
	insertInto( root1, 0 );
	insertInto( root1, 1 );
	insertInto( root1, 4 );
	insertInto( root1, 8 );
	insertInto( root1, -1 );
	ispisStabla( "root1", root1.get() );
	std::puts( "\nnakon umetanja:" );
	std::cout << "root1 ima binary search tree strukturu: " << ( ( test_binaryTree( root1.get() ) == true ) ? "true" : "false" );
	std::puts( "\n-----------------------\n" );

	std::unique_ptr<treeNode> root2 = std::make_unique<treeNode>(brojevi2.front());
	root2->left = std::make_unique<treeNode>( brojevi2.back() );
	ispisStabla( "root2", root2.get() );
	insertInto( root2, 5 );
	insertInto( root2, 6 );
	ispisStabla( "root2", root2.get() );
	std::puts( "\nnakon umetanja:" );
	std::cout << "root2 ima binary search tree strukturu: " << ( ( test_binaryTree( root2.get() ) == true ) ? "true" : "false" );
	std::puts( "\n-----------------------\n" );

	std::unique_ptr<treeNode> root3 = std::make_unique<treeNode>( brojevi3.front() );
	root3->right = std::make_unique<treeNode>( brojevi3.back() );
	ispisStabla( "root3", root3.get() );
	insertInto( root3, 5 );
	insertInto( root3, 6 );
	ispisStabla( "root3", root3.get() );
	std::puts( "\nnakon umetanja:" );
	std::cout << "root1 ima binary search tree strukturu: " << ( ( test_binaryTree( root3.get() ) == true ) ? "true" : "false" );
	std::puts( "\n-----------------------\n" );

	std::unique_ptr<treeNode> root4 = std::make_unique<treeNode>( brojevi4.front() );
	ispisStabla( "root4", root4.get() );
	insertInto( root4, 5 );
	insertInto( root4, 6 );
	ispisStabla( "root4", root4.get() );
	std::puts( "\nnakon umetanja:" );
	std::cout << "root4 ima binary search tree strukturu: " << ( ( test_binaryTree( root4.get() ) == true ) ? "true" : "false" );
	std::puts( "\n-----------------------\n" );

	std::unique_ptr<treeNode> root5 = nullptr;
	ispisStabla( "root5", root5.get() );
	insertInto( root5, 5 );
	insertInto( root5, 6 );
	ispisStabla( "root5", root5.get() );
	std::puts( "\nnakon umetanja:" );
	std::cout << "root5 ima binary search tree strukturu: " << ( ( test_binaryTree( root5.get() ) == true ) ? "true" : "false" );
	std::puts( "\n-----------------------\n" );
}

std::optional<const treeNode**> findNode( const treeNode** node, int value );
void insertInto( std::unique_ptr<treeNode>& root, int value )
{
	auto newNode = std::make_unique<treeNode>( value );
	const treeNode* rootNode = root.get();
	std::optional<const treeNode**> nodeToInsert = findNode( &rootNode, value );
	if( nodeToInsert.has_value() )
	{
		treeNode* n = const_cast<treeNode*>(*nodeToInsert.value());
		if( value < n->number )
			n->left = std::move( newNode );
		else
			n->right = std::move( newNode );
	}
	else								std::clog << "Node sa brojem \"" << value << "\" vec postoji ili je root == nullptr!\n\n";
	//! poslat addresu roota iz ove funkcije jer ako salje iz findNoe funk, onda je to dangling ref

	//? ------------------------------------------------------
	//? Moj workaround za ovo sto nedaje adresu varijable
	//  const treeNode* rightNode = node->right.get();
	// -pa onda
	//  std::optional<const treeNode**>( &leftNode )
	// ? ====================================================
	//X const treeNode** test3 = &( node->right.get());
	//! error: expression must be an lvalue
	//? ------------------------------------------------------
}

std::optional<const treeNode**> findNode( const treeNode** node, int value )
{
	if( *node == nullptr )	return std::nullopt; // root nepostoji
	const bool goLeft  = value < (*node)->number;
	const bool goRight = value > ( *node )->number;
	const treeNode* leftNode = ( *node )->left.get();
	const treeNode* rightNode = ( *node )->right.get();

	if( ( *node )->left != nullptr && goLeft )			return findNode( &leftNode, value );
	else if( ( *node )->left == nullptr && goLeft )		return std::optional<const treeNode**>( node );
	else if( ( *node )->right != nullptr && goRight )	return findNode( &rightNode, value );
	else if( ( *node )->right == nullptr && goRight )	return std::optional<const treeNode**>( node );
	else /*  exist */									return std::nullopt;
}
