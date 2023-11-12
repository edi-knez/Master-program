#ifndef _nPOG6
#define _nPOG6
#include <cstdint>
#include <array>


namespace POG_6 {

	namespace vj_1 {
		namespace NotYourBusiness {
			inline uint8_t Art() { return 7; }
			inline uint8_t Belinda() { return 5; }
			inline uint8_t Cory() { return 3; }
			inline uint8_t Debbie() { return 10; }
			inline uint8_t Evan() { return 2; }

			inline uint16_t how_many_parots_itern( uint8_t iter = 1 )
			{
				if( iter == 6 )	return 0;
				uint8_t brojPapigaNaPeronu;
				switch( iter )
				{
				case 1:
					brojPapigaNaPeronu = Art();
					break;
				case 2:
					brojPapigaNaPeronu = Belinda();
					break;
				case 3:
					brojPapigaNaPeronu = Cory();
					break;
				case 4:
					brojPapigaNaPeronu = Debbie();
					break;
				case 5:
					brojPapigaNaPeronu = Evan();
					break;
				default:
					brojPapigaNaPeronu = 0;
				}
				return brojPapigaNaPeronu + how_many_parots_itern( iter + 1 );

			}
		};
		inline uint16_t how_many_parots()
		{
			return NotYourBusiness::how_many_parots_itern();
		}
	};
	////////////////////////

	namespace vj_2 {
		namespace Input {
			inline const std::array customers{ 172'000u, 68'000u, 193'000u, 13'000u, 256'000u, 99'000u };
		};

		inline std::array<uint32_t, 6> getInput() { return Input::customers; }

		inline uint32_t highest_salary( const std::array<uint32_t, 6>& customeRS, uint8_t customer = 6 )
		{
			if( customer == 0 ) return 9;
			const uint32_t nextCustomer = highest_salary( customeRS, customer - 1 );
			if( nextCustomer > customeRS[customer - 1] )
				return nextCustomer;
			else
				return customeRS[customer - 1];
		}
	};
	////////////////////////

	namespace vj_3 {
		namespace Input {
			inline const std::array<uint32_t, 10> numbers{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		};

		inline uint32_t sum( const std::array<uint32_t, 10>& numbers, uint8_t iter = 0 )
		{
			if( iter == numbers.size() - 1 )
			{
				return numbers[iter];
			}
			return numbers[iter] + sum( numbers, iter + 1 );
		}
	};
	////////////////////////

	namespace vj_4 {
		namespace NotYourBusiness {		//
			struct node
			{
				int data;
				node* next;
			};
			using numList = node;
			inline void setupLL( numList* head )
			{
				numList* iter = head;
				iter->next = new numList;
				iter = iter->next;
				iter->data = 7;
				iter->next = new numList;
				iter = iter->next;
				iter->data = 12;
				iter->next = new numList;
				iter = iter->next;
				iter->data = 9;
				iter->next = new numList;
				iter = iter->next;
				iter->data = -14;
				iter->next = new numList;
				iter = iter->next;
				iter->data = -12;
				iter->next = new numList;
				iter = iter->next;
				iter->data = 0;
				iter->next = nullptr;
			}
			inline void freeMemory( numList* head )
			{
				while( head != nullptr )
				{
					numList* tmp = head;
					head = head->next;
					delete tmp;
				}
			}
			//
			inline uint16_t rec( const NotYourBusiness::numList* head )
			{
				if( head == nullptr )	return 0;
				return				rec( head->next ) + ( head->data < 0 );
			}

		};

		inline uint16_t cnt_neg_num()
		{
			using numList = NotYourBusiness::node;
			auto* head = new numList;
			NotYourBusiness::setupLL( head );
			const uint16_t cnt = rec( head->next );
			NotYourBusiness::freeMemory( head );
			return cnt;
		}
	};
	////////////////////////

	namespace vj_5 {
		struct treeNode
		{
			treeNode* Left = nullptr;
			treeNode* Right = nullptr;
			int num = INT32_MIN;
		};

		namespace NotYourBusiness {
			inline void setup( treeNode*& root ) // 5, 7, 10, 8, 3, 11, 9
			{
				root = new treeNode;
				root->num = 5;

				root->Left = new treeNode;
				treeNode* l1_L = root->Left;
				l1_L->num = 7;

				l1_L->Left = new treeNode;
				treeNode* l2_LL = l1_L->Left;
				l2_LL->num = 8;


				l1_L->Right = new treeNode;
				treeNode* l2_LR = l1_L->Right;
				l2_LR->num = 3;


				root->Right = new treeNode;
				treeNode* l1_R = root->Right;
				l1_R->num = 7;

				l1_R->Left = new treeNode;
				treeNode* l2_RL = l1_R->Left;
				l2_RL->num = 11;

				l1_R->Right = new treeNode;
				treeNode* l2_RR = l1_R->Right;
				l2_RR->num = 9;
			}
			inline void cleanup( treeNode*& root )
			{
				if( root == nullptr ) return;
				cleanup( root->Left );
				cleanup( root->Right );
				delete root;
				root = nullptr;
			}

			inline int biggestInTree( treeNode* root )
			{
				if( root == nullptr ) return INT32_MIN;
				int big = root->num;

				if( const int bigL = biggestInTree( root->Left ); big < bigL ) big = bigL;
				if( const int bigR = biggestInTree( root->Right ); big < bigR ) big = bigR;
				return big;
			}
		};


		inline int execute()
		{
			treeNode* root = nullptr;
			NotYourBusiness::setup( root );
			const int big = NotYourBusiness::biggestInTree( root );
			NotYourBusiness::cleanup( root );
			return big;
		}
	};

};

#endif