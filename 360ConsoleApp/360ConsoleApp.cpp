#include <iostream>
#include <cstdlib>
#include <windows.h>

int main() {
    wchar_t buffer[MAX_PATH];  // 使用宽字符数组
    // 获取当前程序的路径
    DWORD ret = GetModuleFileName(NULL, buffer, MAX_PATH);
    if (ret == 0) {
        std::wcerr << L"Error getting module file name." << std::endl;
        return 1;
    }

    // 使用std::wstring来处理宽字符数组
    std::wstring path = std::wstring(buffer);
    std::wstring path2 = std::wstring(buffer);

    std::size_t pos = path.find_last_of(L"\\/");
    if (pos != std::wstring::npos) {
        path = path.substr(0, pos + 1); // 包括斜线
        path2 = path2.substr(0, pos + 1); // 包括斜线
    }



    path += L"winrar.exe";

    // 构建并执行静默安装命令
    // 注意：使用 _wsystem 而不是 system
    std::wstring command = L"\"" + path + L"\" /S";

    int result = _wsystem(command.c_str());
    if (result == 0) {
        std::cout << "Installation completed successfully." << std::endl;

        // 安装成功后的操作  // 假设Fx64.rar文件在当前程序目录

        std::wstring winrarPath = L"\"C:\\Program Files\\WinRAR\\WinRAR.exe\"";
        std::wstring rarFile = path2 + L"Fx64.rar";
        std::wstring rarCommand = winrarPath + L" x " + rarFile + L" " + path2 ;

        // 打印命令行字符串以进行检查
        std::wcout << L"Executing command: " << rarCommand << std::endl;

        // 使用 _wsystem 执行宽字符命令
        int result = _wsystem(rarCommand.c_str());
        if (result == 0) {
            std::wcout << L"Unpacking completed successfully." << std::endl;
        }
        else {
            std::wcerr << L"Unpacking failed." << std::endl;
        }



    }
    else {
        std::cerr << "Installation failed." << std::endl;
    }


    return 0;
}
