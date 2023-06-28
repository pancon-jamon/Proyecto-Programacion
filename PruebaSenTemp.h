/**
 * Funcion imprimir poner creditos
*/

#include <iostream>
#include <windows.h>

using namespace std;

int ImprimirEstado() {
    HANDLE hSerial;
    DCB dcbSerialParams = {0};
    COMMTIMEOUTS timeouts = {0};
    DWORD dwBytesRead = 0;
    char data[256] = {0};

    hSerial = CreateFile("\\\\.\\COM3", GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (hSerial == INVALID_HANDLE_VALUE) {
        if (GetLastError() == ERROR_FILE_NOT_FOUND) {
            cout << "\tPuerto serie no disponible\n";
        }
        cout << "\tError al abrir el puerto serie\n";
        return 1;
    }

    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

    if (!GetCommState(hSerial, &dcbSerialParams)) {
        cout << "\tError al obtener el estado del puerto serie\n";
        CloseHandle(hSerial);
        return 1;
    }

    dcbSerialParams.BaudRate = CBR_9600;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;

    if (!SetCommState(hSerial, &dcbSerialParams)) {
        cout << "\tError al establecer el estado del puerto serie\n";
        CloseHandle(hSerial);
        return 1;
    }

    timeouts.ReadIntervalTimeout = 50;
    timeouts.ReadTotalTimeoutConstant = 50;
    timeouts.ReadTotalTimeoutMultiplier = 10;

    if (!SetCommTimeouts(hSerial, &timeouts)) {
        cout << "\tError al establecer los tiempos de espera del puerto serie\n";
        CloseHandle(hSerial);
        return 1;
    }

    while (true) {
        if (!ReadFile(hSerial, data, sizeof(data), &dwBytesRead, NULL)) {
            cout << "\tError al leer los datos del puerto serie\n";
            CloseHandle(hSerial);
            return 1;
        }

        if (dwBytesRead > 0) {
            //cout << "\t";
            cout << "\t" << data << endl;
            //el tab se va acumulando
            memset(data, 0x00, sizeof(data));
            dwBytesRead = 0;
        }
    }

    CloseHandle(hSerial);

    return 0;
}
