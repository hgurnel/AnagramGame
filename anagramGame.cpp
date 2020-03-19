#include "AnagramGame.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>

using namespace std;

// Constructors
AnagramGame::AnagramGame() : m_anagramWord("") {}
AnagramGame::AnagramGame(const string &word) : m_anagramWord(word) {}

void AnagramGame::SubmitWord(string &word)
{
	cout << "\nSubmitting word: " + word << endl;
	m_userWord = word;

	if (this->IsUserWordValid(m_userWord, m_anagramWord))
		cout << "\nValid word" << endl;
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
		return true;
	else
		return false;
}

bool AnagramGame::IsSubstring(const string& sUser, const string& sAnagram)
{
	string sU = sUser;
	string sA = sAnagram;
	// Remove blank spaces
	remove_if(sU.begin(), sU.end(), isspace);
	remove_if(sA.begin(), sA.end(), isspace);
	// Sort alphabetically, so user word and anagram word have the same order
	sort(sU.begin(), sU.end());
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
    ifstream inputStream(filePath.c_str(), ios::in);

    if (inputStream)
    {
        string line;

        // Read file line by line and check for a match with submittedWord
        while (std::getline(inputStream, line))
        {
			int result = m_userWord.compare(line);
			if (result == 0)
			{
				cout << "\nIt is an anagram of: " + m_anagramWord << endl;
				return true;
				break;
			}
        }
		cout << "\nIt is not an anagram of: " + m_anagramWord << endl;
		return false;
    }
    else
    {
        cerr << "\nCannot open " << filePath << endl;
    }

void AnagramGame::UpdateTopScores(const string& userWord)
{
	int key = userWord.length();

	if(m_scores.count(key)==0)
		m_scores.insert(std::pair<int, string>(userWord.length(), userWord));
	else
	{
		for (auto itr = m_scores.begin(); itr != m_scores.end(); itr++)
		{
			if (itr->first == key)
			{
				// Update score without duplicates
				if (itr->second != userWord)
				{
					m_scores.insert(std::pair<int, string>(userWord.length(), userWord));
				}
			}
		}
	}

	cout << "\nCOUNT for key " << key << ": " << m_scores.count(key) << endl;
	
	cout << "\n----- TOP SCORES -----\n" << endl;
	
	for (std::pair<int, string> elem : m_scores)
		std::cout << elem.first << " :: " << elem.second << std::endl;

	cout << "\n----------------------\n" << endl;
}

std::string AnagramGame::GetWordEntryAtPosition(int position)
{
	return "";
}

int AnagramGame::GetScoreAtPosition(int position)
{
	return -1;
}


