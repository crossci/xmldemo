#include "include\tinyxml.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	const char* filepath = "protocol.xml";
	TiXmlDocument doc(filepath);
	bool loadOkay = doc.LoadFile();
	if (!loadOkay) {
		printf("Could not load test file %s. Error='%s'. Exiting.\n", filepath, doc.ErrorDesc());
	}
	TiXmlElement* root = doc.RootElement();
	for (TiXmlNode*  commondNode = root->FirstChild("commond");
		commondNode;
		commondNode = commondNode->NextSibling("commond"))
	{
		const char* id = commondNode->ToElement()->Attribute("id");
		const char* name = commondNode->ToElement()->Attribute("name");
		const char* desc = commondNode->ToElement()->Attribute("desc");
		cout << id << "		" << name << "		" << desc << endl;
	}
	system("pause");
}