#include <iostream>
#include <string>

class Languages
{
private:
	const std::string language;

	std::string english(uint8_t textNumber);
	std::string russia(uint8_t textNumber);

public:
	Languages(std::string language);

	std::string getText(uint8_t textNumber);
};