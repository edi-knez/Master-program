#include "Poglavlje4.h"
#include <string.h>
#include <cstdint>

//? ---------------------------------------	ZADACI	--------------------------------------------------
void Poglavlje4::append(const char*& cstr, char ch)
{
	uint8_t len = static_cast<uint8_t>(strlen(cstr) + 2);
	auto* temp = new char[len];
	strcpy_s(temp, len - 1, cstr);	// mora imat dosta prostora za sadrzaj cstr + '\0'

	////for (uint8_t i = 0; i < len - 2; ++i)
	////	temp[i] = cstr[i];
	temp[len - 2] = ch;
	temp[len - 1] = '\0';
	////std::cout << "temp: " << temp << '\n';
	if (strcmp(cstr, "\0") != 0)	delete[] cstr;
	cstr = temp;
}

void Poglavlje4::concatenate(const char*& cstr, const char* cstrDodaj)
{
	const uint8_t len1 = strlen(cstr);
	const uint8_t len2 = strlen(cstrDodaj) + 1;
	char* temp = new char[len1 + len2];
	strcpy_s(temp, len1+1, cstr);
	strcpy_s(temp + len1, len2, cstrDodaj);
	if (strcmp(cstr, "\0") != 0)	delete[] cstr;
	cstr = temp;
}

char* Poglavlje4::characterAt(const char* cstr, uint8_t poz)
{
	ch.get()[0] = cstr[poz - 1];
	return ch.get();
}
//

void Poglavlje4::addRecord(StudentRecord*& sRec, Student stud)
{
	if (sRec == nullptr)
		sRec = new StudentRecord(stud.m_id, stud.m_grade);
	else
	{
		StudentRecord* newRecord = new StudentRecord(stud.m_id, stud.m_grade);
		newRecord->next = sRec;
		sRec = newRecord;
	}
}

float Poglavlje4::averageRecord(StudentRecord* sRec)
{
	int brOcjena = 0;
	int zbroj = 0;
	while (sRec)
	{
		zbroj += sRec->studentInfo.m_grade;
		++brOcjena;
		sRec = sRec->next;
	}

	if (zbroj > 0)	return zbroj / static_cast<float>(brOcjena);
	else			return -1;
}


//? -------------------------------------->	VJEZBE	<------------------------------------------------
void Poglavlje4::vj1_()
{

}
const char* Poglavlje4::vj2_sub_string(const char* cstr, int startPos, int length)
{
	int zadnjaPos = -1;
        if (startPos < 0)
                return new const char[1] ('\0');
	char* retVal = new char[length + 1];
	int i = 0;
	for (; i < startPos && *cstr != '\0'; ++i) // offset
		++cstr;
	for (int j = 0; j < length && *cstr != '\0'; ++cstr, ++j)
	{
		retVal[j] = *cstr;
		zadnjaPos = j;
	}
	retVal[zadnjaPos + 1] = '\0';
	return retVal;
}

void Poglavlje4::vj3_replaceString(const char*& source, const char* target, const char* replaceText)
{
	int sourceLen = 0;
	const int targetLen = strlen(target);
	const int replaceLen = strlen(replaceText);

	int cntZamjena = 0;
	for (const char* psrc = source; psrc[sourceLen] != '\0'; ++sourceLen)
	{
		if (psrc[sourceLen] == target[0])
		{
			int i = 1;
			for (const char* psrc2 = &psrc[sourceLen + 1];
				(*psrc2 == target[i]) && (i < targetLen) && (*psrc2 != '\0');
				++psrc2, ++i)
			{}
			if (i == targetLen)
			{
				char* psrc2 = const_cast<char*>(&psrc[sourceLen]);
				++cntZamjena;
				for (i -= 1;
					i >= 0;
					--i)
				{
					*psrc2 = '\n';
					++psrc2;
				}
			}
		}
	}

	if (replaceLen == targetLen)
	{
		if (replaceLen == '\0')	return; // sourceLen = targetLen = replaceLen = 0
		for (const char* psrc = source; *psrc != '\0'; ++psrc)
		{
			if (*psrc == '\n')
			{
				int i = 0;
				for (char* cpSrc =  const_cast<char *>(psrc);
					*cpSrc != '\0' && i < replaceLen;
					++cpSrc)
				{
					*cpSrc = replaceText[i];
				}
				psrc += replaceLen;
			}
		}
	}
	else
	{
		int duljina = sourceLen + (replaceLen - targetLen) * cntZamjena;
		char* tmp = new char[duljina + 1];

		char* ptmp = tmp;
		int len = 0;
		for (const char* psrc = source; len < duljina; ++len)
		{
			if (*psrc != '\n')
			{
				*ptmp = *psrc;
				++ptmp;
				++psrc;
			}
			else
			{
				int i = 0;
				for (char* psrc2 = const_cast<char *>(psrc);
					*psrc2 != '\0' && i < replaceLen;
					++psrc2, ++ptmp, ++i)
				{
					*ptmp = replaceText[i];
				}
				len += replaceLen - 1;
				psrc += replaceLen - 1;
			}
		}
		tmp[duljina] = '\0';
		delete[] source;
		source = tmp;
	}
}

void Poglavlje4::vj4_append(myCharptr& string, char ch)
{
	uint8_t len;
	if (string.getContent() == nullptr)	len = 1;
	else								len = string.getLength() + 1;
	myCharptr tmp(len, string);
	tmp.getContent()[len] = ch;
	string.reset(1);
	string = std::move(tmp);
}

void Poglavlje4::vj4_concatenate(Poglavlje4::myCharptr& string, const Poglavlje4::myCharptr& dodajString)
{
	if (string.getContent() == nullptr)
	{
		string = dodajString;
	}
	else if(dodajString.getContent() == nullptr)	return;
	else
	{
		uint8_t lenStr1 = string.getLength();
		uint8_t lenStr2 = dodajString.getLength();

		Poglavlje4::myCharptr tmp;
		//tmp.reserve(lenStr1 + lenStr2 - 1);
		for (int i = 1; i <= lenStr1; ++i)
			tmp.getContent()[i] = string.getContent()[i];

		for (int i = 1; i < tmp.getLength(); ++i)
			tmp.getContent()[i + lenStr1] = dodajString.getContent()[i];
		string.reset(1);
		string = std::move(tmp);
		tmp.reset();
	}
}

void Poglavlje4::vj4_concatenate(Poglavlje4::myCharptr& store, const Poglavlje4::myCharptr& string, const Poglavlje4::myCharptr& dodajString)
{
	store.~myCharptr();
	if (string.getContent() == nullptr)
	{
		store = dodajString;
	}
	else if (dodajString.getContent() == nullptr)	store = string;
	else
	{
		uint8_t lenStr1 = string.getLength();
		uint8_t lenStr2 = dodajString.getLength();

		Poglavlje4::myCharptr tmp;
		//tmp.reserve(lenStr1 + lenStr2 - 1);
		for (int i = 1; i <= lenStr1; ++i)
			tmp.getContent()[i] = string.getContent()[i];

		for (int i = 1; i < tmp.getLength(); ++i)
			tmp.getContent()[i + lenStr1] = dodajString.getContent()[i];

		store = std::move(tmp);
		tmp.reset();
	}
}

void Poglavlje4::vj4_concatenate(Poglavlje4::myCharptr& store, Poglavlje4::myCharptr& string, const char* dodajString)
{
	store.~myCharptr();
	char lenDodStr = strlen(dodajString) + 1;
	if (string.getContent() == nullptr)
	{
		store = std::move(myCharptr{lenDodStr, dodajString});
		string.reset();
	}
	else if (dodajString == nullptr)	store = string;
	else
	{
		uint8_t lenStr1 = string.getLength();

		Poglavlje4::myCharptr tmp(lenStr1 + lenDodStr, string);

		for (int i = lenDodStr; i > 0; --i)
			tmp.getContent()[i + lenStr1] = dodajString[i - 1];

		store = std::move(tmp);
		tmp.reset();
	}
}

void Poglavlje4::vj4_concatenate(myCharptr& string, const char* cstrDodaj)
{

	uint8_t lenStr1 = string.getLength();
	uint8_t lenStr2 = strlen(cstrDodaj) + (string.getContent() == nullptr);
	Poglavlje4::myCharptr tmp(lenStr1 + lenStr2 - 1, string);
	for (int i = lenStr1 + 1; i <= tmp.getLength(); ++i)
		tmp.getContent()[i] = cstrDodaj[i - 1];
	string.reset(1);
	string = std::move(tmp);
}

char Poglavlje4::vj4_characterAt(const myCharptr& string, uint8_t pos)
{
	if (string.getContent() == nullptr || pos < 0 || pos > string.getLength())	return '\0';
	return string.getContent()[pos];
}

void remove_from_record(Poglavlje4::StudentRecord*& sRec, Poglavlje4::StudentRecord* tmp, Poglavlje4::StudentRecord* tmp2)
{
	if (tmp == sRec)
	{
		sRec = sRec->next;
		tmp->next = nullptr;
		delete tmp;
	}
	else
	{
		tmp2->next = tmp->next;
		tmp->next = nullptr;
		delete tmp;
	}
}
bool remove_check(char lookFor, char studInfo)
{
	return lookFor == studInfo;
}
void remove_by_id(Poglavlje4::StudentRecord*& sRec, char lookFor)
{
	Poglavlje4::StudentRecord* tmp = sRec;
	Poglavlje4::StudentRecord* tmp2 = tmp;
	while (tmp != nullptr)
	{
		if (remove_check(lookFor - '0', tmp->studentInfo.m_id) == true)
		{
			remove_from_record(sRec, tmp, tmp2);
			std::cout << "Rekord obrisan!\n";
			return;
		}
		tmp2 = tmp;
		tmp = tmp->next;
	}
	std::cout << "Rekord nepostoji!\n";
}
void remove_by_grade(Poglavlje4::StudentRecord*& sRec, char lookFor)
{
	Poglavlje4::StudentRecord* tmp = sRec;
	Poglavlje4::StudentRecord* tmp2 = tmp;
	while (tmp != nullptr)
	{
		if (remove_check(lookFor, tmp->studentInfo.m_grade) == true)
		{
			remove_from_record(sRec, tmp, tmp2);
			std::cout << "Rekord obrisan!\n";
			return;
		}
		tmp2 = tmp;
		tmp = tmp->next;
	}
	std::cout << "Rekord nepostoji!\n";
}
void Poglavlje4::vj5_remove_record(StudentRecord*& sRec, int kriterij, char mode)
{
	switch (mode)
	{
	case '0':
		remove_by_id(sRec, kriterij);
		break;
	case '1':
		remove_by_grade(sRec, kriterij);
		break;
	default:
		return;
	}

}
