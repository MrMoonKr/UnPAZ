#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <memory>
#include <cstdio>
#include <time.h>
#include <filesystem>

namespace fs = std::filesystem;

///printf formatting for std::string
///If you need "width" argument in pattern, use this instead of boost::format
///source: https://stackoverflow.com/a/26221725
template<typename ... Args>
std::string string_format(const std::string &format, Args ... args)
{
	size_t size = snprintf(nullptr, 0, format.c_str(), args ...) + 1; /// Extra space for '\0'
	std::unique_ptr<char[]> buf(new char[size]);
	snprintf(buf.get(), size, format.c_str(), args ...);
	return std::string(buf.get(), buf.get() + size - 1); /// We don't want the '\0' inside
}


/// wildcard matching ('?', '*')
bool WildMatch(std::string pat, std::string str);
bool WildMatch(std::wstring pat, std::wstring str);


/// simple text progressbar
bool printProgress(uint32_t current, uint32_t maximum, std::string text); ///print progressbar
bool printProgress(); ///clear the line
std::string getProgressString(uint32_t current, uint32_t maximum, std::string text);
std::string getProgressString();

#include <filesystem>


/// automatically rename file (it adds [] to the end of file name)
void autoRenameFile(fs::path &FilePath);
///ask if you want to automatically rename file (it adds [] to the end of file name)
///returns char which option was selected - (y)es / (N)o / (a)lways / ne(v)er / (e)xit
char autoRenameFilePrompt(fs::path &FilePath);
///Ask if you want to create directories needed for file specified in FilePath.
///returns char which option was selected - (Y)es / (a)lways / (s)kip file / (e)xit
char createPathPrompt(fs::path &FilePath);
///returns path relative to current path (because eperimental::filesystem doesn't have implemented boost::filesystem::relative)
fs::path relativePathTo(fs::path from, fs::path to);

