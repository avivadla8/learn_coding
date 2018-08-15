# Basic Algo's and DS

Learn basic algorithms


## Some initializations:

* int vals[100] = {0}; 
* std::vector<int> myInts(100, 0);  // creates a vector of 100 ints, all set to zero

* int* p = new int[10];std::memset(p, 0, 10);
* int* p = new int[10];std::fill_n(p, 10, 0);
* std::vector<int> v(10); // elements zero'ed


## Other Issues regarding OS ( ubuntu )

#### If the wifi-signal is weak in ubuntu, we can make it better by checking installed driver with different antenna selections. In most cases re-enabling the kernel module with correct antenna selection will help. Let me share my finding.

* To fix this you have to remove the current kernel modules and then insert it again with the new antenna selection.. In my case, In Ubuntu the antenna was 2 and in centOS7 it is 1.

* So here are the steps (which I did).

* In UBUNTU (16.10, 17.04)
```
sudo modprobe -rv rtl8723be
sudo modprobe -v rtl8723be ant_sel=2
echo "options rtl8723be ant_sel=2" | sudo tee /etc/modprobe.d/50-rtl8723be.conf (this step will help you to keep the same changes even after the reboot)
```
* In CENTOS7
```
sudo modprobe -rv rtl8723be
sudo modprobe -v rtl8723be ant_sel=1
echo "options rtl8723be ant_sel=1" | sudo tee /etc/modprobe.d/50-rtl8723be.conf (this step will help you to keep the same changes even after the reboot)
```
Try this first. If your first antenna selection is not working then go with the other one. If this step is not helping then try download and compile it.

#### Synaptics touchpad tap-to-click is not working in Ubuntu 16.04 LTS (Gnome)
*  upgraded my ubuntu gnome installation to 16.04.3 LTS (GNOME) and everything is kinda good except for the touchpad single-tap functionality. Single-tap-to-click is not working.
* Permanent Solution :- gsettings set org.gnome.desktop.peripherals.touchpad tap-to-click true  
