#include "wfind.hpp"

std::vector<fs::directory_entry> searchInFiles::searchDirectory(std::string regexr)
{
    std::vector<fs::directory_entry> result;
    for (auto &&file : fs::recursive_directory_iterator(curWorkingDir))
    {
        if (contentMatch(file, regexr))
            result.push_back(file);
    }
    return result;
}

bool searchInFiles::contentMatch(fs::path filename, std::string regexr)
{
    std::ifstream inp(filename.string(), std::ios::in | std::ios::binary);
    std::regex expr(regexr);
    if (inp.is_open())
    {
        std::string content;
        while (std::getline(inp, content))
        {
            if (std::regex_search(content, expr))
                return true;
        }
        inp.close();
    }
    return false;
}