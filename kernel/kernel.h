#pragma once
#include <cstdint>
#include <basetsd.h>
#include <TlHelp32.h>
#include <winnt.h>
#include "../kernel/spoof.h"

uintptr_t virtualaddy;
uintptr_t proc_ud;



#define code_rDTB CTL_CODE(FILE_DEVICE_UNKNOWN, 0x754, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define code_rw CTL_CODE(FILE_DEVICE_UNKNOWN, 0x856, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define code_ba CTL_CODE(FILE_DEVICE_UNKNOWN, 0x783, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define code_security 0x97723a00

static bool EAC = false;

typedef struct _rw {
	INT32 security;
	INT32 process_id;
	ULONGLONG address;
	ULONGLONG buffer;
	ULONGLONG size;
	BOOLEAN write;
	BOOLEAN EAC;
} rw, * prw;

typedef struct _dtb {
	INT32 security;
	INT32 process_id;
	bool* operation;
} dtb, * dtbl;

typedef struct _ba {
	INT32 security;
	INT32 process_id;
	ULONGLONG* address;
} ba, * pba;

struct comms_t {
	std::uint32_t key;

	struct {
		void* handle;
	}window;
};
typedef struct _hide {
	comms_t* a;
} hide, * hidea;

typedef struct _ga {
	INT32 security;
	ULONGLONG* address;
} ga, * pga;

typedef struct _SYSTEM_BIGPOOL_ENTRY
{
	union {
		PVOID VirtualAddress;
		ULONG_PTR NonPaged : 1;
	};
	ULONG_PTR SizeInBytes;
	union {
		UCHAR Tag[4];
		ULONG TagUlong;
	};
} SYSTEM_BIGPOOL_ENTRY, * PSYSTEM_BIGPOOL_ENTRY;

typedef struct _SYSTEM_BIGPOOL_INFORMATION {
	ULONG Count;
	SYSTEM_BIGPOOL_ENTRY AllocatedInfo[ANYSIZE_ARRAY];
} SYSTEM_BIGPOOL_INFORMATION, * PSYSTEM_BIGPOOL_INFORMATION;

typedef struct _cr {

	INT32 process_id;
} ca, * cra;

namespace mem {
	HANDLE driver_handle;
	INT32 process_id;

	bool find_driver() {
		SPOOF_FUNC;
		//Device Name: \\Device\\desirelol
		//Symbolic link: \\DosDevices\\desirelol
		driver_handle = CreateFileW((L"\\\\.\\\desirelol"), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);

		if (!driver_handle || (driver_handle == INVALID_HANDLE_VALUE))
			return false;

		return true;
	}

	void read_physical(PVOID address, PVOID buffer, DWORD size) {
		SPOOF_FUNC;
		_rw arguments = { 0 };

		arguments.security = code_security;
		arguments.address = (ULONGLONG)address - 928369281;
		arguments.buffer = (ULONGLONG)buffer - 85125152;
		arguments.size = size - 172471244;
		arguments.process_id = process_id - 928359823;
		arguments.write = FALSE;

		if (EAC)
			arguments.EAC = TRUE;
		else
			arguments.EAC = FALSE;

		DeviceIoControl(driver_handle, code_rw, &arguments, sizeof(arguments), nullptr, NULL, NULL, NULL);
	}

	inline bool read1(const std::uintptr_t address, void* buffer, const std::size_t size)
	{
		SPOOF_FUNC;
		if (buffer == nullptr || size == 0) {
			return false;
		}
		read_physical(reinterpret_cast<PVOID>(address), buffer, static_cast<DWORD>(size));
	}

	void write_physical(PVOID address, PVOID buffer, DWORD size) {
		SPOOF_FUNC;
		_rw arguments = { 0 };

		arguments.security = code_security;
		arguments.address = (ULONGLONG)address - 928369281;
		arguments.buffer = (ULONGLONG)buffer - 85125152;
		arguments.size = size - 172471244;
		arguments.process_id = process_id - 928359823;
		arguments.write = TRUE;

		if (EAC)
			arguments.EAC = TRUE;
		else
			arguments.EAC = FALSE;

		DeviceIoControl(driver_handle, code_rw, &arguments, sizeof(arguments), nullptr, NULL, NULL, NULL);
	}
	bool CR3() {
		SPOOF_FUNC;
		bool ret = false;
		_dtb arguments = { 0 };
		arguments.security = code_security;
		arguments.process_id = process_id;
		arguments.operation = (bool*)&ret;
		if (EAC)
		{
			DeviceIoControl(driver_handle, code_rDTB, &arguments, sizeof(arguments), nullptr, NULL, NULL, NULL);
		}
		else
		{
			return true;
		}

		return ret;
	}

	uintptr_t find_image() {
		SPOOF_FUNC;
		uintptr_t image_address = { NULL };
		_ba arguments = { NULL };

		arguments.security = code_security;
		arguments.process_id = process_id;
		arguments.address = (ULONGLONG*)&image_address;

		DeviceIoControl(driver_handle, code_ba, &arguments, sizeof(arguments), nullptr, NULL, NULL, NULL);

		return image_address;
	}



	INT32 find_process(LPCTSTR process_name) {
		SPOOF_FUNC;
		PROCESSENTRY32 pt;
		HANDLE hsnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		pt.dwSize = sizeof(PROCESSENTRY32);
		if (Process32First(hsnap, &pt)) {
			do {
				if (!lstrcmpi(pt.szExeFile, process_name)) {
					CloseHandle(hsnap);
					process_id = pt.th32ProcessID;
					proc_ud = pt.th32ProcessID;
					return pt.th32ProcessID;
				}
			} while (Process32Next(hsnap, &pt));
		}
		CloseHandle(hsnap);
		return process_id;

	}
}
bool IsProcessRunning(LPCTSTR process_name) {
	SPOOF_FUNC;
	PROCESSENTRY32 pt;
	HANDLE hsnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	pt.dwSize = sizeof(PROCESSENTRY32);


	if (Process32First(hsnap, &pt)) {
		do {
			if (lstrcmpi(pt.szExeFile, process_name) == 0) {
				CloseHandle(hsnap);
				return true;
			}
		} while (Process32Next(hsnap, &pt));
	}

	CloseHandle(hsnap);
	return false;
}


template <typename T>
T read(uint64_t address) {
	SPOOF_FUNC;

	T buffer{ };
	mem::read_physical((PVOID)address, &buffer, sizeof(T));
	return buffer;
}

template <typename T>
T write(uint64_t address, T buffer) {
	SPOOF_FUNC;
	mem::write_physical((PVOID)address, &buffer, sizeof(T));
	return buffer;
}

template<typename T>
bool read_array(uintptr_t address, T out[], size_t len)
{
	SPOOF_FUNC;
	for (size_t i = 0; i < len; ++i)
	{
		out[i] = read<T>(address + i * sizeof(T));
	}
	return true; // you can add additional checks to verify successful reads
}

bool is_valid(const uint64_t adress)
{
	SPOOF_FUNC;
	if (adress <= 0x400000 || adress == 0xCCCCCCCCCCCCCCCC || reinterpret_cast<void*>(adress) == nullptr || adress >
		0x7FFFFFFFFFFFFFFF) {
		return false;
	}
	return true;
}