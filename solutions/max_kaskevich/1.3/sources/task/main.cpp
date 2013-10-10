#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <locale>

const std::string bad_chars = " -\\,";

void read_line(std::ifstream& stream, std::string& line)
{
    std::getline(stream, line);
    line.erase(
        std::remove_if(line.begin(), line.end(), [](const char& c)
		{
			return std::any_of(bad_chars.begin(), bad_chars.end(),
				[=](const char& b){return b == c;});
		}),
        line.end());

    std::transform(line.begin(), line.end(), line.begin(), ::tolower);
}

int main( int argc, char* argv[] )
{
    setlocale(LC_ALL, "");
    std::ifstream input(SOURCE_DIR "/tests/test1.txt");

    std::string text;
    read_line(input, text);

    std::string line;
    while(!input.eof())
    {
        read_line(input, line);
        if(line.empty())
        {
            continue;
        }
		std::cout << (std::search(text.begin(), text.end(), line.rbegin(), line.rend()) != text.end() ?
			"YES" : "NO") << std::endl;
    }   

}
