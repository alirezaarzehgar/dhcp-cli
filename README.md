# dhcpcli

dhcpcli is a command line interface for interacting with lease/config files files.

In this program you can :
 - see leases
 - see configs
 - add config
 - static dhcp
 - remove a lease
 - change ip address of a specific mac address
 
# build & run

```
mkdir build
cd build
cmake ..
cmake --build .
./dhcpcli
```

### debug mode

```
mkdir build
cd build
cmake .. -DDEBUG=on
cmake --build .
./dhcpcli
```