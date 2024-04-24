#include "libdragon.h"

// Read the contents of the SD card on an Everdrive 64
// Tested on an Everdrive 64 X7
// This code will list all files and directories in the /filesystem folder of the SD card
// Create a folder named "filesystem" on the root of the SD card and put some files in it.
int main() {
    debug_init(DEBUG_FEATURE_LOG_ISVIEWER);
    console_init();
	/* This will initialize the SD filesystem using 'sd:/' to identify it */
	if (!debug_init_sdfs("sd:/", -1)) {
		debugf("Error opening SD\n");
        printf("Error opening SD\n");
        exit(1);
	}
    dir_t dir;
    int err = dir_findfirst("sd:/",&dir);
    int count = 0;
    while( err == 0 ) {
        if (dir.d_type == DT_DIR) {
            printf("[%s]\n", dir.d_name);
        } else {
            printf("%s\n", dir.d_name);
        }
        err = dir_findnext("sd:/", &dir); 
        count++;  
    }
    if (count == 0) {
        printf("No files in this dir...\n");
    }   
}