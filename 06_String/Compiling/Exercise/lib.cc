#include <vector>
#include <filesystem>
#include <iostream>

#include "lib.h"

bool is_source_file(const fs::path &file)
{
    if (file.extension() == ".cc" || ".cpp" || ".h" || ".hpp")
    {
        return true;
    }

}

std::vector<fs::path> get_source_files_in_dir(const fs::path &dir)
{
    if (is_source_file(dir))
    {
        std::vector<fs::path> tempPathVec;
        tempPathVec.push_back(dir);
        return tempPathVec;
    }
    std::cout << "no C++ source file" << std::endl;
}

void compile_file(fs::path source_file)
{

}

fs::path link_files(FileVec source_files)
{

}

void run(const fs::path &executable_path)
{

}
