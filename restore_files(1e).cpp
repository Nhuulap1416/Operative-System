#include<iostream>
#include<windows.h>
#include <dos.h>
#include <memory.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;
int main(){
	//cout << sizeof(BootEntry) << endl;
	BYTE sector[512];
	//\\\\.\\I:
    DWORD bytesRead;
	HANDLE device = CreateFile(
        "\\\\.\\I:",
        GENERIC_READ | GENERIC_WRITE,
        FILE_SHARE_READ | FILE_SHARE_WRITE,
        NULL,
        OPEN_EXISTING,
        FILE_FLAG_WRITE_THROUGH,
        NULL);
	SetFilePointer (device, 512*32769, NULL, FILE_BEGIN) ;
	
    if (!ReadFile(device, sector, 512, &bytesRead, NULL))
    {
        printf("ReadFile: %u\n", GetLastError());
    }
    else
    {
        printf("Success!\n");
    }
    SetFilePointer (device, 512*32769, NULL, FILE_BEGIN) ;
    //char str[2];
    unsigned char *str = (unsigned char *)malloc(2);
    str[0] = 0x46;
    str[1] = 0x31;
   
    DWORD bytesWritten;
    sector[0] = 0x46;
    
    if(!WriteFile(device, sector, 512, &bytesWritten, NULL));
    	cout << GetLastError() << endl;
    cout << bytesWritten << endl;
    for(int i = 0; i < 512; i++){
    	cout << (char)sector[i];
    	if(i % 15 == 0 && i > 0)
			cout << endl;
	}
	// Y tuong cua nhom em la se den vi tri sau bang Fat(bat dau bang RDET), sau do lan luot tim cac vi tri ma du lieu dang la E5,
	// sua cac vi tri do thanh 0x46(F), tiep den tu bang RDET suy ra cac vi tri cluster bat dau, do file chiem kich thuoc 2 cluster
	// nen tu vi tri do ta co the sua cac vi tri cluster tuong ung voi vi tri bang Fat quan li
	// Tuy nhien, khi trien khai nhom em gap kho khan ve van de phan quyen, cu the windows khong cho phep nhom em thuc hien cac thao 
	// tac ghi tren dia USB.
   	free(str);
   	system("pause");
	return 0;
}
