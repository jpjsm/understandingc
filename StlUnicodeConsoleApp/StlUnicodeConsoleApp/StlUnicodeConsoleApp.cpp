// StlUnicodeConsoleApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>

#include <iostream>
#include <string>
#include <vector>

int wmain(int argc, wchar_t* argv[])
{
    WIN32_FIND_DATA ffd;
    long long filesize;
    std::vector<std::wstring> args(argc);
    size_t length_of_arg;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    unsigned long dwError = 0;
    std::wstring folder;

    if (argc != 2)
    {
        std::wcout << "\nUsage: " << argv[0] << " <directory name>" << std::endl;
        return (-1);
    }

    folder = L"\\\\?\\"  + std::wstring(argv[1]) + L"\\*";


    // Find the first file in the directory.

    hFind = FindFirstFileW(folder.c_str(), &ffd);

    if (INVALID_HANDLE_VALUE == hFind)
    {
        return dwError;
    }

    return 0;
}

