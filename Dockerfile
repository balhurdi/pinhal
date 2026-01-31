FROM alpine:3.23

COPY aports /aports/
COPY genapkovl-mkimgoverlay.sh /aports/scripts/genapkovl-mkimgoverlay.sh

RUN apk add abuild alpine-conf syslinux xorriso squashfs-tools grub mtools

RUN adduser -D builder
RUN chown -R builder:builder /aports
USER builder

RUN abuild-keygen -a -n && mkdir -pv ~/tmp
COPY mkimg.pinhal.sh /aports/scripts/mkimg.pinhal.sh

RUN sh  /aports/scripts/mkimage.sh --tag 3.23 \
	--outdir ~/iso \
	--arch x86_64 \
	--repository https://dl-cdn.alpinelinux.org/alpine/v3.23/main \
    --repository https://dl-cdn.alpinelinux.org/alpine/v3.23/community \
	--profile pinhal