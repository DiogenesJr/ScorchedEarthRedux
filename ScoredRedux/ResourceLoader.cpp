#include <Windows.h>
#include "ResourceLoader.h"

unsigned char* LoadPNGResource(int resourceID, int* resourceSize) {
    HRSRC hRes = FindResource(NULL, MAKEINTRESOURCE(resourceID), L"PNG");
    if (hRes == NULL) return NULL;

    HGLOBAL hMem = LoadResource(NULL, hRes);
    if (hMem == NULL) return NULL;

    void* pData = LockResource(hMem);
    if (pData == NULL) return NULL;

    DWORD size = SizeofResource(NULL, hRes);
    *resourceSize = size;

    unsigned char* buffer = new unsigned char[size];
    memcpy(buffer, pData, size);

    return buffer;
}