#include "utils.hpp"
#include <stdexcept>

namespace baltam::py::utils
{
	// Convert UTF-8 Str to UTF-16 std::wstring
	std::wstring utf8_to_utf16(const std::string &utf8_str)
	{
		// Calculate the length of the resulting UTF-16 string
		int utf16_len = MultiByteToWideChar(CP_UTF8, 0, utf8_str.c_str(), -1, nullptr, 0);
		if (utf16_len == 0) {
			throw std::runtime_error("转换 UTF-8 到 UTF-16 失败");
		}

		// Allocate space for the UTF-16 string
		std::wstring utf16_str(utf16_len, L'\0');

		// Perform the conversion
		MultiByteToWideChar(CP_UTF8, 0, utf8_str.c_str(), -1, &utf16_str[0], utf16_len);

		return utf16_str;
	}

	std::string utf16_to_utf8(const std::wstring &utf16_str)
	{
		// Calculate the length of the resulting UTF-8 string
		int utf8_len = WideCharToMultiByte(CP_UTF8, 0, utf16_str.c_str(), (int)utf16_str.size(), nullptr, 0, nullptr, nullptr);
		if (utf8_len == 0) {
			throw std::runtime_error("转换 UTF-16 到 UTF-8 失败");
		}

		// Allocate space for the UTF-8 string
		std::string utf8_str(utf8_len, '\0');

		// Perform the conversion
		WideCharToMultiByte(CP_UTF8, 0, utf16_str.c_str(), (int)utf16_str.size(), &utf8_str[0], utf8_len, nullptr, nullptr);

		return utf8_str;
	}

	std::string utf16_to_gbk(const std::wstring &utf16_str)
	{
		const int cp_gbk = 936;
		int gbk_len = WideCharToMultiByte(cp_gbk, 0, utf16_str.c_str(), -1, nullptr, 0, nullptr, nullptr);
		if (gbk_len == 0) {
			throw std::runtime_error("转换 UTF-16 到 GBK 失败");
		}

		std::string gbk_str(gbk_len, '\0');
		WideCharToMultiByte(cp_gbk, 0, utf16_str.c_str(), -1, &gbk_str[0], gbk_len, nullptr, nullptr);

		return gbk_str;
	}

	std::wstring gbk_to_utf16(const std::string& gbk_str)
	{
		const int cp_gbk = 936;
		int utf16_len = MultiByteToWideChar(cp_gbk, 0, gbk_str.c_str(), -1, nullptr, 0);
		if (utf16_len == 0) {
			throw std::runtime_error("转换 GBK 到 UTF-16 失败");
		}

		std::wstring utf16_str(utf16_len, L'\0');
		MultiByteToWideChar(cp_gbk, 0, gbk_str.c_str(), -1, &utf16_str[0], utf16_len);

		return utf16_str;
	}

	// 获取 SetEnvironmentVariableW 设置的环境变量
	std::wstring MyGetEnvironmentVariableW(const std::wstring& name)
	{
		// 1) get required buffer size
		DWORD size = GetEnvironmentVariableW(name.c_str(), nullptr, 0);
		if (size == 0) {
			if (GetLastError() == ERROR_ENVVAR_NOT_FOUND)
				return L"";  // not defined
			throw std::runtime_error("GetEnvironmentVariableW failed");
		}
		// 2) fetch the value
		std::vector<wchar_t> buf(size);
		DWORD ret = GetEnvironmentVariableW(name.c_str(), buf.data(), size);
		if (ret == 0 || ret >= size)
			throw std::runtime_error("Unexpected buffer size error");
		return std::wstring(buf.data());
	}
}
