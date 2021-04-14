#include<iostream>
#include<utility>
#include<sstream>
#include<vector>
#include<deque>
#include<algorithm>
#include<cstdlib>
#include<map>
#include <iterator>
#include <fstream>

#define CELLCNT 20
using namespace std;


void FileProc(char* FilePath)
{
	ifstream ifs;
	ifs.open(FilePath,ios::binary);
	if (ifs.is_open())
	{
		ifs.seekg(0, ios::end);
		int FileSize = ifs.tellg();
		int point = 0;
		string temp;
		ifs.seekg(0, ios::beg);
		while (!ifs.eof())
		{
			if (point+ CELLCNT < FileSize)
			{
				unsigned char* temp = new unsigned char[CELLCNT];
				memset(temp, 0, CELLCNT);
				ifs.read((char*)temp, CELLCNT);
				for (int i = 0;i < CELLCNT;i++)
				{
					printf("0x%02x ", (unsigned char)temp[i]);
				}
				point += CELLCNT;
				delete [] temp;
				printf("\n");
			}
			else
			{
				int delta = FileSize - point;
				unsigned char* temp = new unsigned char[delta];
				memset(temp, 0, delta);
				ifs.read((char*)temp, delta+1);
				for (int i = 0;i < delta;i++)
				{
					printf("0x%02x ", (unsigned char)temp[i]);
				}
				point += delta;
				delete[] temp;
				printf("\n");
			}

		}
	}
	else
	{
		return;
	}

}
int main()
{
	char FilePath[] = "E:\\2.png";
	FileProc(FilePath);
}