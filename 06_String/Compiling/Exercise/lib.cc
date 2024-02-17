#include <filesystem>
#include <iostream>
#include <vector>

#include "lib.h"

bool is_source_file(const fs::path &file)
{
    // source files only
    if (file.extension() == ".cc" || file.extension() == ".cpp" || file.extension() == ".cxx")
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
    return std::vector<std::filesystem::path>();
}

void compile_file(fs::path source_file)
{
    //std::string = "g++ -c (Pfad.cc) -o (Pfad.o)"
    const std::string source_file_string = source_file.string();
    std::string command = "g++ -c " + source_file_string;

    source_file.replace_extension("o");
    const std::string object_file_string = source_file.string();
    command += " -o " + object_file_string;

    std::system(command.c_str());
}

fs::path link_files(FileVec source_files)
{
    // g++ Main.o -o Main
    std::string command = "g++ ";
    for (auto &source_file : source_files)
    {
        source_file.replace_extension("o");
        const std::string object_source_file = source_file.string();
        command += object_source_file + " ";
    }
    std::filesystem::path executable_path = source_files[0].parent_path();
    executable_path /= "test";

    command += " -o " + executable_path.string();
    std::system(command.c_str());
    return executable_path;
}

void run(const fs::path &executable_path)
{
    std::string run_executable_path_string = executable_path.string();
    std::system(run_executable_path_string.c_str());
}
