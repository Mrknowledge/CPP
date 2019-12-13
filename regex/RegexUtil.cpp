#include "RegexUtil.h"

CRegexUtil::CRegexUtil()
{
	return;
}

CRegexUtil::~CRegexUtil()
{
	return;
}

std::string CRegexUtil::StrToLower(std::string str)
{
	std::string tmp;
	for(size_t i=0; i<str.length(); ++i)
		tmp.push_back(tolower(str[i]));
	return tmp;
}

bool CRegexUtil::Match(const char* cType, const char* cURL)
{
	bool ret = false;
	std::string type, str;
	int result, z, reti;
	regmatch_t pm[10];
	const size_t nmatch = 10;
	type = std::string(cType);
	str = std::string(cURL);

	std::map<std::string, std::string> regs;
	std::map<std::string, int> types;
	regs["ip"] = "[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}";
	regs["email"] = "[a-zA-Z0-9_.-]+@[a-zA-Z0-9_.-]+\\.[a-zA-Z0-9_.-]+";
	//for filter
	regs["1219"] = "^http://t.moonbasa.com/[0-9]+[/]?";

	types["ip"] = 1;
	types["email"] = 2;
	//for filter
	types["1219"] = 3;

	regex_t preg;

	type = StrToLower(type);
	reti = regcomp(&preg, regs[type].c_str(), REG_EXTENDED|REG_NOSUB);
	if (reti)
	{
		char errbuf[1024];
		regerror(reti, &preg, errbuf, 1024);
		printf("Could not compile regex with message<%s>!", errbuf);
		return ret;
	}

	result = regexec(&preg, str.c_str(), 0, NULL, 0);

	switch (types[type])
	{
		case 1:
		case 2:
		case 3:
			if (result == REG_NOMATCH)
				printf("Regcomp %s not match reg express %s\n", cType, regs[type].c_str());
			else if (!result) 
			{
				printf("Match!\n");
				ret = true;
			}
		default:
			break;
	}

	regfree(&preg);

	return ret;
}

int main()
{
	CRegexUtil engine;
	std::string str = "http://t.moonbasa.com/vplaza";
	//≤‚ ‘µ˜”√
	if(engine.Match("1219", str))
		printf("OK\n");
	return 0;
}
