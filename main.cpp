#include <iostream>
#include <fstream>
#include <string>
#include "pugixml.hpp"
#pragma comment(lib, "pugixmlsd.lib")

void getXml(LPCTSTR url)
{ 
	CFile file((TEXT("temp1.xml")), CFile::modeCreate|CFile::modeWrite);
	CString content;
	CString data;
	DWORD dwStatusCode;
	CInternetSession session(TEXT("HttpClient"));

	CHttpFile* pfile = (CHttpFile *)session.OpenURL(url);
	pfile -> QueryInfoStatusCode(dwStatusCode);
	if(dwStatusCode == HTTP_STATUS_OK)
	{
		while (pfile -> ReadString(data))
		{
			content += data;
		}
	}
	pfile -> Close();
	delete pfile;
	session.Close();
	file.Write(content, content.GetLength());
	file.Close();
}

void convertXml()
{
	auto LocUtf8 = std::locale(std::locale(""), new std::codecvt_utf8<wchar_t>);
	std::wifstream wfin("temp1.xml");
	std::wstring wstr, content;
	wfin.imbue(LocUtf8);
	while(getline(wfin, wstr))
	{
		content += wstr;
	}
	wfin.close();
	system("del temp1.xml");
	//std::wcout.imbue(std::locale(""));
	//std::wcout << content << std::endl;

	std::locale::global(std::locale("Chinese-simplified"));
	std::wofstream wfout("temp.xml");
	wfout << content;
	wfout.close();
}

void readXml()
{
	pugi::xml_document doc;
	doc.load_file("temp.xml");
	//doc.save(std::cout);
	pugi::xml_node data = doc.child("xml");
	for(pugi::xml_node tool = data.first_child(); tool; tool = tool.next_sibling())  
	{    

		for(pugi::xml_node element = tool.first_child(); element; element = element.next_sibling())  
		{  
			std::cout << element.name() << " : " << element.text().get() << std::endl;  
		}
		std::cout << std::endl;
	}
}

int main()
{
	LPCTSTR str = TEXT("http://api.kuaidi100.com/api?id=a78e61062aabe452&com=yuantong&nu=9100493541&show=1");
	getXml(str);
	convertXml();
	readXml();
	system("del temp.xml");
	//system("pause");
	return 0;
}