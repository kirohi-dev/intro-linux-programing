FROM ubuntu:20.04
WORKDIR /workspase
RUN apt-get update \
  && apt-get -y install build-essential git
  && unminimize
