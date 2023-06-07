FROM ubuntu:18.04

LABEL author="Kubanov Ivan"

ENV TZ=Europe/Moscow  
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone  
      
RUN apt-get update  
RUN apt-get install qt5-default -y  
RUN apt-get install qtbase5-dev -y  
RUN apt-get install qt5-qmake  
RUN apt-get install build-essential -y 

WORKDIR /root/
RUN mkdir Kubanov_221_329
WORKDIR /root/Kubanov_221_329/
COPY *.cpp /root/Kubanov_221_329/
COPY *.h /root/Kubanov_221_329/
COPY *.pro /root/Kubanov_221_329/

RUN qmake hallServer.pro
RUN make hallServer

ENTRYPOINT ["./hallServer"]