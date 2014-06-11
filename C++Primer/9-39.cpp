#include <iostream>
#include <vector>
#include <fstream>
#include <string>


using namespace std;

#define N 100

int main(void)
{
	string line1 = "we were her pride of 10 she named us:";
	string line2 = "Benjamin, Phoenix, the Prodigal";
	string line3 = "and perspicacious pacific Suzanne";
	string sentence = line1 + " " + line2 + " " + line3;
	string separator(" \t:,\v\r\n\f");  // 用作分割符

	int count = 0, wordlen, maxlen, minlen;
	vector<string> longestword, shortestword;
	string::size_type startpos = 0, endpos = 0;
	string word;

	while ((startpos = sentence.find_first_not_of(separator, startpos)) != string::npos)
	{
		count ++;
		endpos = sentence.find_first_of(separator, startpos);
		if (endpos == string::npos)
		{
			//this is the last word in the sentence
			wordlen = sentence.size() - startpos;
		}
		else
		{
			wordlen = endpos - startpos;
		}
		// get the word
		word.assign(sentence.begin() + startpos, sentence.begin() + startpos + wordlen);
		//设置下次查找的起始位置
		startpos = sentence.find_first_not_of(separator, endpos);

		if (count == 1)
		{
			maxlen = wordlen;
			minlen = wordlen;
			longestword.push_back(word);
			shortestword.push_back(word);
		}
		else
		{
			if (wordlen > maxlen)
			{
				maxlen = wordlen;
				longestword.clear();
				longestword.push_back(word);
			}
			else if (wordlen == maxlen)
				longestword.push_back(word);
			
			if (wordlen < minlen)
			{
				minlen = wordlen;
				shortestword.clear();
				shortestword.push_back(word);
			}
			else if (wordlen == minlen)
				shortestword.push_back(word);
		}
	}
	cout << "word amount: " << endl << count << endl;
	vector<string>::iterator iter;
	cout << "longest words: " << endl;
	iter = longestword.begin();
	while(iter != longestword.end())
		cout << *iter++ << endl;
	cout << "shortest words: " << endl;
	iter = shortestword.begin();
	while (iter != shortestword.end())
		cout << *iter++ << endl;
	

	system("pause");
	return 0;
}

