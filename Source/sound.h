#include "main.h"

VOID WINAPI sound1()
{
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0, };
	waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

	char buffer[8000 * 20];

	for (DWORD t = 0; t < sizeof(buffer); t++)
		buffer[t] = static_cast<char>((t << 1 >> 8) * (t << 1 | 4));

	WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutClose(hwo);
}

VOID WINAPI sound2()
{
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0, };
	waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

	char buffer[8000 * 20];

	for (DWORD t = 0; t < sizeof(buffer); t++)
		buffer[t] = static_cast<char>(t >> 3 | (t >> 2) * (t >> 5));

	WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutClose(hwo);
}

VOID WINAPI sound3()
{
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0, };
	waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

	char buffer[8000 * 20];

	for (DWORD t = 0; t < sizeof(buffer); t++)
		buffer[t] = static_cast<char>((t >> 4) * (t >> 6 | 11));

	WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutClose(hwo);
}

VOID WINAPI sound4()
{
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0, };
	waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

	char buffer[8000 * 20];

	for (DWORD t = 0; t < sizeof(buffer); t++)
		buffer[t] = static_cast<char>(t * (0xCA68 >> (t >> 9 & 14) & 15) | t >> 6);

	WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutClose(hwo);
}

VOID WINAPI sound5()
{
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0, };
	waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

	char buffer[8000 * 20];

	for (DWORD t = 0; t < sizeof(buffer); t++)
		buffer[t] = static_cast<char>(t * (t / 6666) - t * (t / 66666) + t * (t >> 5 | t >> 6 | t << 2 & t >> 1));

	WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutClose(hwo);
}

VOID WINAPI sound6()
{
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0, };
	waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

	char buffer[8000 * 20];

	for (DWORD t = 0; t < sizeof(buffer); t++)
		buffer[t] = static_cast<char>(t * ((3 + (1 ^ t >> 10 & 3)) * (4 + (2 & t >> 5)))) >> (t >> 5 & 4);

	WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutClose(hwo);
}

VOID WINAPI sound7()
{
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0, };
	waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

	char buffer[8000 * 20];

	for (DWORD t = 0; t < sizeof(buffer); t++)
		buffer[t] = static_cast<char>(t * (t >> ((t & 50) ? ((t * t) / 666) : (t / 666))) | (t << (t / 666)) | (t >> 2));

	WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutClose(hwo);
}

VOID WINAPI sound8()
{
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0, };
	waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

	char buffer[8000 * 20];

	for (DWORD t = 0; t < sizeof(buffer); t++)
		buffer[t] = static_cast<char>((t & 6666) ? ((t * (t ^ t % 666) | (t >> 1)) >> 1) : (t >> 3) | ((t & 8192) ? t << 2 : t));

	WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutClose(hwo);
}

VOID WINAPI sound9()
{
	HWAVEOUT hwo = 0;
	WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 8000, 8000, 1, 8, 0, };
	waveOutOpen(&hwo, WAVE_MAPPER, &wfx, 0, 0, CALLBACK_NULL);

	char buffer[8000 * 20];

	for (DWORD t = 0; t < sizeof(buffer); t++)
		buffer[t] = static_cast<char>(t >> 16 | ((t >> 4) % 16) | ((t >> 4) % 192) | (t * t % 64) | (t * t % 96) | (t >> 16) * (t | t >> 5));

	WAVEHDR hdr = { buffer, sizeof(buffer), 0, 0, 0, 0, 0, 0 };
	waveOutPrepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutWrite(hwo, &hdr, sizeof(WAVEHDR));
	waveOutUnprepareHeader(hwo, &hdr, sizeof(WAVEHDR));
	waveOutClose(hwo);
}