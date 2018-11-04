#include "Speaker.h"
#include <map>
#include <string>
#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;

map<string, string> soundList({
	{"零","./0.wav"},
	{"一","./1.wav"},
	{"二","./2.wav"},
	{"三","./3.wav"},
	{"四","./4.wav"},
	{"五","./5.wav"},
	{"六","./6.wav"},
	{"七","./7.wav"},
	{"八","./8.wav"},
	{"九","./9.wav"},
	{"十","./10.wav"},
	{"百","./11.wav"},
	{"千","./12.wav"},
	{"万","./13.wav"},
	{"亿","./14.wav"},
	{"兆","./15.wav"},
	{"点","./16.wav"},
	{"负","./17.wav"},
	});

string numberString;

DWORD WINAPI speak(LPVOID lpThreadParameter)
{
	for (string::const_iterator it = numberString.begin(); it != numberString.end(); ++it, ++it)
	{
		string tmp(it, it + 2);//一个汉字占2个char
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