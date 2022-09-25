#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <psapi.h>

#include "process_proc.h"

int main( void )
{

    DWORD aProcesses[10240]; 
    DWORD cbNeeded; 
    DWORD cProcesses;
    unsigned int i;

    printf("Starting ABVIR_V1\n");

    // Get the list of process identifiers.

    if ( !EnumProcesses( aProcesses, sizeof(aProcesses), &cbNeeded ) )
        return 1;

    // Calculate how many process identifiers were returned.

    cProcesses = cbNeeded / sizeof(DWORD);

    printf( "%d processes found\n", cProcesses );

    // Print the names of the modules for each process.

    for ( i = 0; i < cProcesses; i++ )
    {
        if ( aProcesses[i] == 0 ) 
            continue;

        PrintProcessNameAndID( aProcesses[i] );
        //PrintModules( aProcesses[i] );
    }

    getch();

    return 0;
}