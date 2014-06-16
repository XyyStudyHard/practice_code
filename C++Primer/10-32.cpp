#include "cpp_project.h"


ifstream &open_file(ifstream &in, const string &file)
{
	in.close();
	in.clear();
	in.open(file.c_str());
	return in;
}

string make_plural£¨size_t ctr, const string &word, const string &ending)
{
	return (ctr == 1) ? word : word + ending;
}

void print_results(const vector<TextQuery::line_no>& locs, 
				  const string& sought, const TextQuery &file)
{
	typedef vector<TextQuery::line_no> line_nums;
	line_nums::size_type size = locs.size();
	cout << "\n" << sought << " occurs " << size << " "
		<< make_plural(size, "time", "s") << endl;
	// print each line in which the word appeared
	line_nums::const_iterator it = locs.begin();
	for ( ; it != locs.end(); ++it)
		cout << "\t(line " << (*it) + 1 << ")" << file.text_line(*it) << endl;
}


int main(int argc, char **argv)
{
	ifstream infile;
	if (argc < 2 || !open_file(infile, argv[1]))
	{
		cerr << "No input file !" << endl;
		return -1;
	}

	TextQuery tq;
	tq.read_file(infile);   // builds query map

	infile.close();

	while(true)
	{
		cout << "enter word to look for, or q to quit: ";
		string s;
		cin >> s;
		if (!cin || s == "q")
			break;
		// get the vector of line numbers on which this word appears
		vector<TextQuery::line_no> locs = tq.run_query(s);
		print_results(locs, s, tq);
	}

	system("pause");
	return 0;
}