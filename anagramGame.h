#pragma once
#include <string>
#include <map>

using namespace std;

class AnagramGame
{
public:
	AnagramGame();
	AnagramGame(const string& word);
	virtual ~AnagramGame() {}

	/// <summary>
	/// Submit a word on behalf of a user. A word is accepted if its letters are 
	/// contained in the original string submitted in the constructor, and if it 
	/// is in the word list at https://sites.google.com/a/ifyoucan.org/downloads/downloads/wordlist.txt. 
	/// If the word is accepted and its score is high enough, the submission 
	/// should be added to the high score list. If there are multiple submissions 
	/// with the same score, all are accepted, but the first submission with that 
	/// score should rank higher. 
	/// </summary>
	/// <param name="word">Word submitted by the user</param>
	void SubmitWord(string &word);

	// Check if submittedWord is a substring of anagramWord
	bool IsUserWordValid(const string &userWord, const string &anagramWord);

	// Check if string 1 is a substring of string 2 (no order)
	bool IsSubstring(const string &s1, const string &s2);

	// Check if submittedWord belongs to the word list
	bool IsAnagram(const string &filePath);

	// Update the array containing the best scores
	void UpdateTopScores(const string &userWord);

private:
	string m_anagramWord;
	string m_userWord;

	multimap<int, string> m_scores;
};

