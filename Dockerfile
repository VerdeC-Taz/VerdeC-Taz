FROM ubuntu:24.04

RUN apt-get update && \
    apt-get install -y g++ ttyd && \
    rm -rf /var/lib/apt/list/*

WORKDIR /app

COPY . .

RUN g++ -std=c++17 *.cpp -o program

CMD ["ttyd", "-w", "./program"]

