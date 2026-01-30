FROM alpine:3.23

COPY aports /aports/
RUN apk add abuild alpine-conf syslinux xorriso squashfs-tools grub mtools

RUN adduser -D builder
USER builder

RUN abuild-keygen -a -n && mkdir -pv ~/tmp
COPY mkimg.pinhal.sh /aports/scripts/mkimg.pinhal.sh

RUN sh  /aports/scripts/mkimage.sh --tag 3.23 \
	--outdir ~/iso \
	--arch x86_64 \
	--repository https://dl-cdn.alpinelinux.org/alpine/edge/main \
	--profile pinhal