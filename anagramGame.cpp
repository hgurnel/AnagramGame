#include "AnagramGame.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

// Constructor
AnagramGame::AnagramGame(const string &word) : m_anagramWord(word){}

void AnagramGame::SubmitWord(string &word)
{
	cout << "\nSubmitting word " + word << endl;
	m_userWord = word;

	if (this->IsUserWordValid(m_userWord, m_anagramWord))
	{
		cout << "\nValid word" << endl;
	}
	else
	{
		cout << "\nWRONG. Enter letters from : " + m_anagramWord << "\n" << endl;
		cin >> word;

		this->SubmitWord(word);
	}
}

bool AnagramGame::IsUserWordValid(const string &userWord, const string &anagramWord)
{
	if (this->IsSubstring(userWord, anagramWord))
}

bool AnagramGame::CheckSubmittedWord()
{
	string submittedWord = this->getSubmittedWord();
	string anagramWord = this->getAnagramWord();

	if (anagramWord.find(submittedWord) != std::string::npos)
	{
		cout << "TRUE" << endl;
		return true;
	}
	else
	{
		cout << "FALSE" << endl;
		return false;
}
}

bool AnagramGame::IsSubstring(const string& sUser, const string& sAnagram)
{
	string sU = sUser;
	string sA = sAnagram;
	// Remove blank spaces
	remove_if(sA.begin(), sA.end(), isspace);
	// Sort alphabetically, so user word and anagram word have the same order
	sort(sA.begin(), sA.end());
	int nU = sU.size();
	int nA = sA.size();

	// To start the inner for-loop where it was stopped when the break statement was run previously
	int index = 0;

	bool isCharInAnagramWord = false;
	bool isWordValid = true;

	for (int i = 0; i < nU; i++)
	{
		isCharInAnagramWord = false;

		for (int j = index; j < nA; j++)
		{
			if (sU[i] == sA[j])
			{
				isCharInAnagramWord = true;
				// Next time time, the inner for-loop should start one step after the index where the break statement was run 
				index = j + 1;
				break;
			}
		}

		if (!isCharInAnagramWord)
		{
			isWordValid = false;
			break;
		}
	}

	if (isWordValid)
		return true;
	else
		return false;
}

bool AnagramGame::IsAnagram(const string &filePath)
{
    ifstream inputStream(filePath, ios::in);

    if (inputStream)
    {
        string line;

        // Read file line by line and check for a match with submittedWord
        while (std::getline(inputStream, line))
        {
			int result = submittedWord.compare(line);
			if (result == 0)
			{
				cout << "ANAGRAM" << endl;
				return true;
				break;
			}
        }
		cout << "NOT ANAGRAM" << endl;
		return false;
    }
    else
    {
        cerr << "Cannot open " << filePath << endl;
    }
}

std::string AnagramGame::GetWordEntryAtPosition(int position)
{
	return "";
}

int AnagramGame::GetScoreAtPosition(int position)
{
	return -1;
}


