#ifndef __REGEXUTIL_H__
#define __REGEXUTIL_H__

#include <sys/types.h>
#include <regex.h>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>

class CRegexUtil
{
public:
	CRegexUtil();
	virtual ~CRegexUtil();
	bool Match(const char* cType, const char* cURL);

private:
	std::string StrToLower(std::string str);
};

#endif
