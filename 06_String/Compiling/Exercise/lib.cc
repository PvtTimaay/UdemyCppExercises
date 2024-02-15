#include <vector>
#include <filesystem>
#include <iostream>

#include "lib.h"

bool is_source_file(const fs::path &file)
{
    if (file.extension() == ".cc" || file.extension() == ".cpp" || file.extension() == ".h" || file.extension() == ".hpp")
    {
        return true;
    }
    return false;
}

std::vector<fs::path> get_source_files_in_dir(const fs::path &dir)
{
    if (std::filesystem::exists(dir) && std::filesystem::is_directory(dir))
    {
        std::vector<fs::path> tempPathVec;
        for (auto &entry : fs::directory_iterator(dir))
        {
            if (entry.is_regular_file() && is_source_file(entry.path()))
            {
                tempPathVec.push_back(entry);
            }
        }
        return tempPathVec;
    }
    std::cout << "no C++ source file" << std::endl;
    std::vector<std::filesystem::path>();
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
