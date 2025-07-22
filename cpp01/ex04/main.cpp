#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void replace_all(std::string& content, const std::string& s1, const std::string& s2)
{
    std::string::size_type pos = 0;

    while ((pos = content.find(s1, pos)) != std::string::npos)
    {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "put 3 arguments" << '\n';
        return 0;
    }
    std::string fileName = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::ifstream in(fileName.c_str());
    std::string content;

    if (s1.empty())
    {
        std::cerr << "S1 shoudn't be empty." << '\n';
        return 1;
    }
    if (!in.is_open())
    {
        std::cerr << "Failed to open input file: " << '\n';
        return 1;
    }
    std::stringstream buffer;
    buffer << in.rdbuf();
    std::string fileContent = buffer.str();
    in.close();
    replace_all(fileContent, s1, s2);
    std::string outName = fileName + ".replace";
    std::ofstream   out(outName.c_str());
    if (!out.is_open())
    {
        std::cerr << "Failed to open output file" << std::endl;
        return 1;
    }
    out << fileContent;
    out.close();
    return 0;
}