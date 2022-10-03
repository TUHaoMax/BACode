

#include "CommunicationTest.h"

#include <iostream>
#include <cpr/cpr.h>

CommunicationTest::CommunicationTest(std::string Url)
{
	this->Url = Url;
}


std::string CommunicationTest::Send(std::string name, std::string parameters)
{
	cpr::Response r = cpr::Get(cpr::Url{ this->Url+ name + "/" + parameters });
	return r.text;
}