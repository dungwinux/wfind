#include <iostream>
#include "src/wfind.hpp"

int main(int argc, char const *argv[])
{
    std::cout
        << "wfind - Find files whose contents match the given search regular expression" << std::endl;

// Check compiler's name & version
#if defined(__GNUC__)
    std::cout
        << "  built with gcc " << __GNUC__ << "." << __GNUC_MINOR__ << "." << __GNUC_PATCHLEVEL__;
        
#if defined(__MINGW64__)
    std::cout << " (MinGW-w64 64bit " << __MINGW64_VERSION_MAJOR << "." << __MINGW64_VERSION_MINOR << ")";
#elif defined(__MINGW32__)
    std::cout << " (MinGW/MinGW-w64 32bit " << __MINGW32_VERSION_MAJOR << "." << __MINGW32_VERSION_MINOR << ")";
#endif

#ifdef __CYGWIN__
    std::cout << " (Cygwin)";
#endif

    std::cout << std::endl;
#elif defined(_MSC_VER)
    std::cout
        << "  built with MS Visual C++ " << _MSC_FULL_VER << std::endl;
#else
    std::cout << "  built with unknown C++ compiler" << std::endl;
#endif

    if ((argc == 1) || (argc == 2 && (argv[1] == std::string("-h") || argv[1] == std::string("--help"))))
    {
        std::cout
            << std::endl
            << "Usage: " << argv[0] << " [regex] [directory]" << std::endl
            << std::endl
            << "  regex     : Regular expression used to find in files" << std::endl
            << "  directory : (Optional) Directory for look up" << std::endl;
        return 0;
    }

    std::string keyword = std::string(argv[1]);

    wfind sif;
    if (argc > 2)
        if (!sif.changeDirectory(fs::path(std::string(argv[2]))))
        {
            std::cout << "wfind: directory does not exist." << std::endl;
            return 1;
        }

    std::cout << "Looking up directory: " << sif.currentDirectory() << std::endl;
    std::cout << "Regex: \"" << keyword << "\"" << std::endl;

    std::vector<fs::directory_entry> result;
    try
    {
        result = sif.searchDirectory(keyword);
    }
    catch (std::regex_error e)
    {
        std::cout << "wfind: regex error" << std::endl;
    }

    for (auto &&iter : result)
        std::cout << iter << std::endl;
    if (result.empty())
        std::cout << "wfind: no files found." << std::endl;
    else
        std::cout << "wfind: " << result.size() << " file(s) found." << std::endl;

    return 0;
}
