#!/usr/bin/sh -eu

interactive=0

while getopts i opt; do
    case $opt in
	i) interactive=1 ;;
	*) echo "Option not recognised"; exit 1 ;;
    esac
done

echo "Using kernel dir" ${KERNEL_SRC:=~/kernel/linux}

if [ $interactive -eq 1 ]; then
    qemu-system-x86_64 -enable-kvm -m 4G -smp 8 -display none \
		       -nodefaults \
		       -device virtio-rng-pci \
		       -device virtio-serial \
		       -chardev stdio,id=tty,logfile=tty.log \
		       -device virtconsole,chardev=tty \
		       -chardev socket,server,nowait,id=transport,path=transport,logfile=transport.log \
		       -device virtserialport,chardev=transport \
		       -kernel $KERNEL_SRC/arch/x86/boot/bzImage \
		       -initrd myinitrd \
		       -append "rd.systemd.unit=emergency rd.shell=1 console=hvc0"

    exit 0
fi

qemu-system-x86_64 -enable-kvm -m 4G -smp 8 -display none \
		   -nodefaults \
		   -device virtio-rng-pci \
		   -device virtio-serial \
		   -chardev null,id=tty,logfile=tty.log \
		   -device virtconsole,chardev=tty \
		   -chardev socket,server,id=transport,path=transport,logfile=transport.log \
		   -device virtserialport,chardev=transport \
		   -kernel $KERNEL_SRC/arch/x86/boot/bzImage \
		   -initrd myinitrd \
		   -append "rd.systemd.unit=emergency rd.shell=1 console=hvc0" &

qpid=$!
trap "kill $qpid" 0 1 3 6 9 15

while [ ! -e transport -a -e /proc/$qpid ]; do
    sleep 1
done

if [ ! -e /proc/$qpid ]; then
    echo "QEMU died!"
    exit 123
fi
