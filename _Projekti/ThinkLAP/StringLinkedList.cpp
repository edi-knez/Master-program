#include <iostream>
#include <array>
#include <vector>
#include <cstdint>
#include "StringLL.h"
#include "StringLLAdv.h"

namespace StringLinkedList
{
	void vj6_append(struct StringLLAdv& advNode, char slovo)
	{
		StringLL* tmp = new StringLL;
		tmp->slovo = slovo;
		tmp->next = nullptr;
		if (advNode.head.next == nullptr)
		{
			advNode.head.next = tmp;
		}
		else
		{
			advNode.tail->next = tmp;
		}
		advNode.tail = tmp;
		++advNode.head.slovo;
	}

	char vj6_characterAt(const struct StringLLAdv& advNode, uint8_t pos)
	{
		uint8_t numEl = advNode.head.slovo;
		if (pos < 0 || pos > numEl) return -1;
		StringLL* head = advNode.head.next;
		while (pos > 0)
		{
			head = head->next;
			--pos;
		}
		return head->slovo;
	}

	void vj7_concatenate(struct StringLLAdv& advNode, const struct StringLLAdv& advNode2)
	{
		int numEl = advNode2.head.slovo;
		StringLL* tmp = advNode2.head.next;
		while (numEl > 0)
		{
			StringLinkedList::vj6_append(advNode, tmp->slovo);
			tmp = tmp->next;
			--numEl;
		}
	}

	void del(struct StringLL* head);
	void vj8_rmvchar(struct StringLLAdv& advNode, uint8_t pos, uint8_t kolicina)
	{
		uint8_t numEl = advNode.head.slovo;
		if (pos < 0			|| pos > numEl ||
			kolicina < 0	|| kolicina > numEl)	return;
		StringLL* pocetak = advNode.head.next;
		StringLL* tmp = advNode.head.next;
		StringLL* kraj;
		while (pos > 0)
		{
			pocetak = tmp;
			tmp = tmp->next;
			--pos;
		}
		kraj = tmp;
		while (kraj != nullptr && kolicina > 0)
		{
			kraj = kraj->next;
			--kolicina;
			--advNode.head.slovo;
		}
		if (pocetak == tmp)
		{
			advNode.head.next = kraj;
		}
		pocetak->next = kraj;
		tmp->next = nullptr;
		StringLinkedList::del(tmp);
	}

	StringLLAdv vj9_intToList()
	{
		StringLLAdv retVal;

		while (char znamenka = std::cin.get())
		{
			if (isdigit(znamenka))
			{
				StringLinkedList::vj6_append(retVal, znamenka);
			}
			else	break;
		}
		return retVal;
	}

	void vj10_append_front(struct StringLLAdv& advNode, char slovo)
	{
		StringLL* tmp = new StringLL;
		tmp->slovo = slovo;
		tmp->next = advNode.head.next;
		if (advNode.head.next == nullptr)	advNode.tail = tmp;
		advNode.head.next = tmp;
		++advNode.head.slovo;
	}
	namespace _internal
	{
		void vj10_prijenos_jedinica(StringLLAdv& advNode, StringLL* tmp, StringLL* preth)
		{
			if (tmp != nullptr)
				vj10_prijenos_jedinica(advNode, tmp->next, tmp);
			else
				return;

			if (tmp->slovo > '9')	// prijelaz
			{						/// '5' + '5' - '0' - 10 == 48 -> '0'
				if (preth == tmp)
					StringLinkedList::vj10_append_front(advNode, '1');
				else
				{
					++preth->slovo;
				}
				tmp->slovo -= 10;
			}
		}
	}
	StringLLAdv vj10_add_2_int_lists(const StringLLAdv& advNode1, const StringLLAdv& advNode2)
	{
		StringLLAdv retVal;
		StringLL* tmp = advNode1.head.next;
		StringLL* tmp2 = advNode2.head.next;
		uint8_t numEl1, numEl2;
		numEl1 = advNode1.head.slovo;
		numEl2 = advNode2.head.slovo;
		if (numEl1 > numEl2)
		{
			while (numEl1 > numEl2)
			{
				StringLinkedList::vj10_append_front(retVal, tmp->slovo);
				tmp = tmp->next;
				--numEl1;
			}
		}
		else if (numEl2 > numEl1)
		{
			while (numEl2 > numEl1)
			{
				StringLinkedList::vj10_append_front(retVal, tmp2->slovo);
				tmp2 = tmp2->next;
				--numEl2;
			}
		}

		while (tmp != nullptr)
		{
			StringLinkedList::vj6_append(retVal, tmp->slovo + (tmp2->slovo - '0'));
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}

		_internal::vj10_prijenos_jedinica(retVal, retVal.head.next, retVal.head.next);
		return retVal;
	}

	void del(struct StringLLAdv& advNode)
	{
		StringLL* tmpHead = advNode.head.next;
		while (tmpHead != nullptr)
		{
			StringLL* tmp = tmpHead;
			tmpHead = tmpHead->next;
			delete tmp;
		}
		advNode.head.slovo = 0;
	}

	void del(struct StringLL* head)
	{
		StringLL* tmpHead = head;
		while (tmpHead != nullptr)
		{
			StringLL* tmp = tmpHead;
			tmpHead = tmpHead->next;
			delete tmp;
		}
	}
};
