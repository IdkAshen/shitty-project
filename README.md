# shitty-project
a shitty c, project

Instructions for Using the Shell Enrollment Bypass
Enable Developer Mode:
Turn off the Chromebook.
Press and hold Esc + Refresh (F3) and then press Power.
When the recovery screen appears, press Ctrl + D to enable Developer Mode.
Confirm and wait for the system to reset (this erases all local data).
Access Root Shell:
After booting into Developer Mode, open the terminal by pressing Ctrl + Alt + T.
Type shell to enter the Linux shell.
Run the Bypass Script:
Save the provided shell script (enrollment_bypass.sh) to a file on the Chromebook.
Make it executable:
bash

Copy
chmod +x enrollment_bypass.sh
Execute with root privileges:
bash

Copy
sudo ./enrollment_bypass.sh
Reboot the Device:
After running the script, reboot the Chromebook:
bash

Copy
sudo reboot
Check if the enrollment screen is bypassed on startup.
Instructions for Using the C Spoof Lock Program
Compile the C Code:
Save the C code (spoof_lock.c) and the Makefile to a directory.
In the terminal, run:
bash

Copy
make
This will compile the program into spoof_lock.
Run the Compiled Program:
Execute the compiled program with root privileges:
bash

Copy
sudo ./spoof_lock
The program will attempt to modify system files to spoof the enrollment lock status.
Verify Changes:
After execution, restart the UI service manually if needed:
bash

Copy
sudo stop ui && sudo start ui
Check the enrollment status in ChromeOS settings or via the terminal.
General Precautions and Notes
Hardware Write Protection (WP): Many Chromebooks have a hardware switch that prevents modifications to system files. You may need to disable WP by removing a screw or using a hardware method specific to your device model.
ChromeOS Version: These methods may not work on newer versions (e.g., ChromeOS 106+), as Google patches exploits like FogNetwork/Ingot.
Backup Data: Developer Mode erases local data. Ensure you backup any important files before proceeding.
Legal and Policy Risks: Using these methods on school or enterprise devices may violate policies and result in disciplinary action.
🎭
