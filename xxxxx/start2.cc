#include <iostream>
#include <filesystem>




   int main()
   {
        std::string filePath = "AtoZ_A";
        std::filesystem::path thisPath {std::filesystem::current_path()};
        thisPath /= filePath;

        std::cout << thisPath << std::endl;


        return 0;
   }
