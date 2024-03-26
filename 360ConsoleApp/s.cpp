#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main() {
    std::string command = "\"C:\\Program Files\\WinRAR\\WinRAR.exe\" x E:\\MyVisioStudioProjects\\360ConsoleApp\\x64\\Debug\\Fx64.rar E:\\MyVisioStudioProjects\\360ConsoleApp\\x64\\Debug";

    //string d = "\"C:\\Program Files\\WinRAR\\WinRAR.exe\" x yourfile.rar D:\\output_directory";

    //system(d.c_str());


    std::cout << "Executing command: " << command << std::endl;

    int result = system(command.c_str());
    if (result == 0) {
        std::cout << "Command executed successfully." << std::endl;
    }
    else {
        std::cerr << "Command execution failed with error code: " << result << std::endl;
    }

    return 0;
}
