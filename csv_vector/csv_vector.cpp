// csv_vector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
#include <iterator>
#include <vector>

#include <map>


// http://stackoverflow.com/questions/5607589/right-way-to-split-an-stdstring-into-a-vectorstring
// http://stackoverflow.com/questions/236129/split-a-string-in-c
// http://stackoverflow.com/questions/236129/split-a-string-in-c
// http://thispointer.com/stdmap-tutorial-part-1-usage-detail-with-examples/

using namespace std;

int main()
{
	struct tokens : std::ctype<char>
	{
		tokens() : std::ctype<char>(get_table()) {}

		static std::ctype_base::mask const* get_table()
		{
			typedef std::ctype<char> cctype;
			static const cctype::mask *const_rc = cctype::classic_table();

			static cctype::mask rc[cctype::table_size];
			std::memcpy(rc, const_rc, cctype::table_size * sizeof(cctype::mask));

			rc[','] = std::ctype_base::space;
			rc[' '] = std::ctype_base::space;
			rc[':'] = std::ctype_base::space;
			return &rc[0];
		}
	};


	map<string, int> mymap;
	mymap.insert(make_pair("201", 1));
	mymap.insert(make_pair("202", 2));
	mymap.insert(make_pair("203", 3));
	mymap.insert(make_pair("204", 4));
	mymap.insert(make_pair("COM1", 5));
	mymap.insert(make_pair("COM2", 6));


	map <string, int>::iterator it = mymap.begin();

//	cout << mymap["201"] << endl;
	while (it != mymap.end())
	{
		cout << it->first << " :: " << it->second << endl;
		it++;
	}
	//--------------------------------------------------------
	std::string s = " R:COM2,234,222,433,5643,66 5345,43:4234";
	std::stringstream ss(s);
	ss.imbue(std::locale(std::locale(), new tokens()));
	std::istream_iterator<std::string> begin(ss);
	std::istream_iterator<std::string> end;
	std::vector<std::string> vstrings(begin, end);
	//std::copy(vstrings.begin(), vstrings.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
	std::copy(vstrings.begin(), vstrings.end(), std::ostream_iterator<std::string>(std::cout,  "\n"));

	cout << vstrings.size() << endl;
	//cout << mymap[vstrings[1]] << endl;	
	
	
	return 0;
}
