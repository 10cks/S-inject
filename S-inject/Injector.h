#pragma once
#include <Windows.h>
#include <iostream>
#include <tlhelp32.h>
using std::string;

#define DEREF( name )*(UINT_PTR *)(name)
#define DEREF_64( name )*(DWORD64 *)(name)
#define DEREF_32( name )*(DWORD *)(name)
#define DEREF_16( name )*(WORD *)(name)
#define DEREF_8( name )*(BYTE *)(name)

class Injector
{
private:
	string DllPath;
	bool exist;

public:
	Injector(string dll_path);
	Injector();
	~Injector();
	void unInject(DWORD pid);
	void unReflectInject(DWORD pid);
	void unApcInject(DWORD pid);

	void RemoteThreadInject(DWORD pid);
	void ReflectInject(DWORD pid);
	void ApcInject(DWORD pid);

	void Injectable();

	void ShellcodeInject(string basedsc, DWORD pid);
	void ApcShellcodeInject(string basedsc, DWORD pid);
	void ContextShellcodeInject(string basedsc, DWORD pid);

	DWORD GetPidName(char name[]);
	void setter(string dll_path);

private:
	bool bFileExists(string filePath);
	bool bInjectable(DWORD pid);
	bool bGetModule(DWORD pid, MODULEENTRY32& result);

	DWORD dwGetOffset(HANDLE Image, CHAR* FuncName);
	DWORD Rva2Offset(DWORD dwRva, UINT_PTR uiBaseAddress);
};

