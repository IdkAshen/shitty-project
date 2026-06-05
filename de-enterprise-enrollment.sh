#!/bin/bash
# This script attempts to bypass ChromeOS enterprise enrollment.
# It requires root access and developer mode enabled.

# Disable verified boot temporarily
crossystem disable_dev_request=1

# Remove enrollment forced flag
rm -f /mnt/stateful_partition/.force_enrollment
rm -f /home/chronos/.oobe_completed

# Tamper with the encrypted state key
echo "Bypassing enrollment check..."
mount -o remount,rw /
sed -i 's/"EnrollmentRequired":true/"EnrollmentRequired":false/g' /etc/chrome_dev.conf
mount -o remount,ro /

# Restart the enrollment service
stop ui
start ui

echo "Bypass attempt complete. Reboot may be required."
