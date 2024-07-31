#pragma once
#include <windows.h>
#include <windef.h>
#include <winnt.h>
#include <math.h>
#include <stdlib.h>
#include <winternl.h>
#define _USE_MATH_DEFINES 1
#define PAYLOAD_TIME 20
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <mmsystem.h>
#include <iostream>
#pragma  comment(lib,"msimg32.lib")
#pragma comment(lib, "winmm.lib")
#define RGBBRUSH (DWORD)0x1900ac010e
#define SRCBSH (DWORD)0x89345c
#define SquareWave(t, freq, sampleCount) (((BYTE)(2.f * (FLOAT)(freq) * ((t) / (FLOAT)(sampleCount))) % 2) == 0 ? 1.f : -1.f)
#define TriangleWave(t, freq, sampleCount) (4.f * ( FLOAT )fabs(((FLOAT)(t) / ((FLOAT)(sampleCount) / (FLOAT)(freq))) - floor(((FLOAT)(t) / ((FLOAT)(sampleCount) / (FLOAT)(freq)))) - .5f) - 1.f)
#define CUSRGB(r, g, b) (r | g << 8 | g << 16)
#define winapi WINAPI
#define lpvoid LPVOID
#define dword DWORD
#define ulonglong ULONGLONG
#define uint UINT
#define rdtsc __rdtsc
DWORD xs;
VOID SeedXorshift32(DWORD dwSeed)
{
	xs = dwSeed;
}
DWORD xorshift32()
{
	xs ^= xs << 13;
	xs ^= xs << 17;
	xs ^= xs << 5;
	return xs;
}

extern RECT GetVirtualScreen();
extern BOOL CALLBACK MonitorEnumProc(HMONITOR hMonitor, HDC hdcMonitor, PRECT prcBounds, LPARAM lParam);
extern POINT GetVirtualScreenPos();
extern SIZE GetVirtualScreenSize();

RECT GetVirtualScreen()
{
	RECT rcScreen = { 0 };
	EnumDisplayMonitors(NULL, NULL, MonitorEnumProc, (LPARAM)&rcScreen);
	return rcScreen;
}
POINT GetVirtualScreenPos()
{
	RECT rcScreen = GetVirtualScreen();
	POINT ptScreen =
	{
		rcScreen.left,
		rcScreen.top
	};
	return ptScreen;
}
SIZE GetVirtualScreenSize()
{
	RECT rcScreen = GetVirtualScreen();
	SIZE szScreen =
	{
		rcScreen.right - rcScreen.left,
		rcScreen.bottom - rcScreen.top
	};
	return szScreen;
}
BOOL CALLBACK MonitorEnumProc(HMONITOR hMonitor, HDC hdcMonitor, PRECT prcBounds, LPARAM lParam)
{
	PRECT prcParam = (RECT*)lParam;
	UnionRect(prcParam, prcParam, prcBounds);
	return true;
}

typedef union _RGBQUAD
{
	COLORREF rgb;
	struct
	{
		BYTE b;
		BYTE g;
		BYTE r;
		BYTE unused;
	};
}
*PRGBQUAD;

typedef void(TROJAN_PAYLOAD)(int t, HDC hdcScreen);
typedef void(TROJAN_SHADER)(int t, int w, int h, PRGBQUAD prgbScreen);
typedef void(AUDIO_SEQUENCE)(int nSamplesPerSec, int nSampleCount, PSHORT psSamples), * PAUDIO_SEQUENCE;
typedef struct tagAUDIO_SEQUENCE_PARAMS {
	int nSamplesPerSec;
	int nSampleCount;
	PAUDIO_SEQUENCE pAudioSequence;
}
AUDIO_SEQUENCE_PARAMS, * PAUDIO_SEQUENCE_PARAMS;

extern void ExecuteShader(TROJAN_SHADER shader, int nTime);

extern void Shader1(int t, int w, int h, PRGBQUAD prgbScreen);

extern DWORD Time;
extern void InitTimer(UINT uDelay);
extern void CALLBACK TimerProc(HWND hwndTimer, UINT uMsg, UINT_PTR ulTimerID, DWORD dwTime);