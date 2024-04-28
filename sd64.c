#include "libdragon.h"

// Read the contents of the SD card on an Everdrive 64
// Tested on an Everdrive 64 X7
// This code will list all files and directories in the / folder of the SD card
// This code will not work on an emulator, it must be run on real hardware with an Everdrive attached
int main() {
    debug_init(DEBUG_FEATURE_LOG_ISVIEWER | DEBUG_FEATURE_LOG_USB);
    console_init();
    controller_init();
    printf("SD64 - List files and directories on the SD card\n\n");
    printf("This code will list all files and directories in the root folder of the SD card\n");
    printf("This code will not work on an emulator, it must be run on real hardware with an Everdrive attached\n\n");
    printf("Press A to continue\n");
    while(1) {
        controller_scan();
        struct controller_data keys = get_keys_down();
        if (keys.c[0].A) {
            break;
        }
    }
	/* This will initialize the SD filesystem using 'sd:/' to identify it */
	if (!debug_init_sdfs("sd:/", -1)) {
		// debugf not necessary, printf will show the message on the emulator screen and the console.
        // debugf("Error opening SD, you must run this on real hardware with an Everdrive attached.\n \n");
        printf("Error opening SD, you must run this on real hardware with\nan Everdrive attached.\n");
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