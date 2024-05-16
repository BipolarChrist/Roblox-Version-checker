#include <iostream>
#include <filesystem>
#include <string>
#include <windows.h>
#include <Lmcons.h>


std::wstring GetUserName() {
    wchar_t username[UNLEN + 1];
    DWORD username_len = UNLEN + 1;

    if (GetUserNameW(username, &username_len)) {
        return std::wstring(username);
    }
    else {
        std::wcerr << L"failed to get user" << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

int main() {
  
    std::wstring userName = GetUserName();

    
    std::wstring robloxPath = L"C:\\Users\\" + userName + L"\\AppData\\Local\\Roblox\\Versions";

    
    if (!std::filesystem::exists(robloxPath)) {
        std::wcerr << L"failed to get version: " << robloxPath << std::endl;
        return EXIT_FAILURE;
    }

   
    for (const auto& entry : std::filesystem::directory_iterator(robloxPath)) {
        if (entry.is_directory()) {
            std::wcout << L"Roblox version: " << entry.path().filename().wstring() << std::endl;
        }
    }

    return EXIT_SUCCESS;
}
