FROM alpine:latest
LABEL maintainer="Gustavo Pereira"
LABEL description="Compiles and tests the Knight's Path example"

RUN apk add --update make
RUN apk add --update gcc
RUN apk add --update libc-dev
RUN apk add --update valgrind

RUN rm -rf /var/cache/apk/*

ARG MYWORKDIR=/app/

COPY Makefile $MYWORKDIR
COPY ./src/ $MYWORKDIR/src

RUN mkdir $MYWORKDIR/bin

WORKDIR $MYWORKDIR

RUN make tests
