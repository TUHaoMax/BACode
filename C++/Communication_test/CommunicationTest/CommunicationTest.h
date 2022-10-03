
#pragma once

#include <iostream>


class CommunicationTest
{
public:
	std::string Url;

	CommunicationTest(std::string Url);

	std::string Send(std::string name, std::string parameters);
};