#!/bin/bash
ARC=$(uname -a)
PCPU=$(nproc --all)
VCPU=$(grep "^processor" /proc/cpuinfo | wc -l)
FRAM=$(free -m | awk '$1 == "Mem:" {print $2}')
URAM=$(free -m | awk '$1 == "Mem:" {print $3}')
PRAM=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')
FDISK=$(df -Bg | grep '^/dev/' | grep -v '/boot$' | awk '{ft += $2} END {print ft}')
UDISK=$(df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} END {print ut}')
PDISK=$(df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} {ft+= $2} END {printf("%d"), ut/ft*100}')
CPUL=$(top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%"), $1 + $3}')
LB=$(who -b | awk '$1 == "system" {print $3 " " $4}')
LVMT=$(lsblk | grep "lvm" | wc -l)
LVMU=$(if [ $LVMT -eq 0 ]; then echo no; else echo yes; fi)
CTCP=$(cat /proc/net/sockstat{,6} | awk '$1 == "TCP:" {print $3}')
ULOG=$(users | wc -w)
IP=$(hostname -I)
MAC=$(ip link show | awk '$1 == "link/ether" {print $2}')
CMDS=$(journalctl _COMM=sudo | grep COMMAND | wc -l)
wall "#Architecture: $ARC
	  #CPU physical: $PCPU
	  #vCPU: $VCPU
	  #Memory Usage: $URAM/${FRAM}MB ($PRAM%)
	  #Disk Usage: $UDISK/${FDISK}Gb ($PDISK%)
	  #CPU load: $CPUL
	  #Last boot: $LB
	  #LVM use: $LVMU
	  #Connexions TCP: $CTCP ESTABLISHED
	  #User log: $ULOG
	  #Network: IP $IP ($MAC)
	  #Sudo: $CMDS cmd"