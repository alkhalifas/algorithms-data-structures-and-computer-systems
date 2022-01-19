VM - Clipboard access from Host to Guest and vice versa
For folks having trouble copying and pasting content from their Host to Guest machines, try the following!

Manually installing VBoxGuestAdditions.iso on our Guest(Ubuntu here) machine

1. Navigate to Virtual Box Settings -> Storage -> Choose Controller SATA -> Click the bottom ‘+’ to create a new optical drive and leave it empty.
2. Boot your Ubuntu VM, go to Devices on the Navbar -> Insert Guest Additions CD Image
3. A dialog would prompt for installation, reboot the VM and it should work!
