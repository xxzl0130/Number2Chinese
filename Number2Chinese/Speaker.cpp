#include "Speaker.h"
#include <map>
#include <string>
#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;

map<string, string> soundList({
	{"��","./0.wav"},
	{"һ","./1.wav"},
	{"��","./2.wav"},
	{"��","./3.wav"},
	{"��","./4.wav"},
	{"��","./5.wav"},
	{"��","./6.wav"},
	{"��","./7.wav"},
	{"��","./8.wav"},
	{"��","./9.wav"},
	{"ʮ","./10.wav"},
	{"��","./11.wav"},
	{"ǧ","./12.wav"},
	{"��","./13.wav"},
	{"��","./14.wav"},
	{"��","./15.wav"},
	{"��","./16.wav"},
	{"��","./17.wav"},
	});

string numberString;

DWORD WINAPI speak(LPVOID lpThreadParameter)
{
	for (string::const_iterator it = numberString.begin(); it != numberString.end(); ++it, ++it)
	{
		string tmp(it, it + 2);//һ������ռ2��char
		if (soundList.count(tmp) > 0)
		{
			PlaySound(soundList[tmp].c_str(), NULL, SND_SYNC);
		}
	}
	return 0;
}

void speakNumber(const string& number)
{
	static HANDLE handle = nullptr;
	if(handle != nullptr)
	{
		CloseHandle(handle);
	}

	numberString = number;
	handle = CreateThread(NULL, 0, speak, NULL, 0, NULL);
}

void speakNumber(int number)
{
	speakNumber(number2Chinese(number));
}

void speakNumber(long long number)
{
	speakNumber(number2Chinese(number));
}

void speakNumber(double number, int n)
{
	speakNumber(number2Chinese(number, 2));
}