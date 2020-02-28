#include "AnagramGame.h"

using namespace std;

void AnagramGame::SubmitWord(std::string word)
{
	cout << "Submitting word " + word;
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

bool AnagramGame::isAnagram(string filePath)
{
	string submittedWord = this->getSubmittedWord();
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

/// SETTERS

void AnagramGame::setAnagramWord(string word)
{
	m_anagramWord.assign(word);
}

void AnagramGame::setSubmittedWord(string word)
{
	m_submittedWord.assign(word);
}

/// GETTERS

string AnagramGame::getAnagramWord()
{
	return m_anagramWord;
}

string AnagramGame::getSubmittedWord()
{
	return m_submittedWord;
}


