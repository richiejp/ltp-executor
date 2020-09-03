#!/usr/bin/sh -eu

interactive=0

while getopts i opt; do
    case $opt in
	i) interactive=1 ;;
	*) echo "Option not recognised"; exit 1 ;;
    esac
done

echo "Using kernel dir" ${KERNEL_SRC:=~/kernel/linux}

rm transport.{in,out} || true
mkfifo transport.in transport.out

if [ $interactive -eq 1 ]; then
    echo 'Starting QEMU interactively'
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

echo 'Starting QEMU in background'
qemu-system-x86_64 -enable-kvm -m 4G -smp 8 -display none \
		   -nodefaults \
		   -daemonize \
		   -pidfile qemu.pid \
		   -device virtio-rng-pci \
		   -device virtio-serial \
		   -chardev null,id=tty,logfile=tty.log \
		   -device virtconsole,chardev=tty \
		   -chardev pipe,id=transport,path=transport,logfile=transport.log \
		   -device virtserialport,chardev=transport \
		   -kernel $KERNEL_SRC/arch/x86/boot/bzImage \
		   -initrd myinitrd \
		   -append "rd.systemd.unit=emergency rd.shell=1 console=hvc0"

trap "kill $(cat qemu.pid)" 0 1 3 6 9 15
