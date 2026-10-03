FROM ubuntu:24.04

RUN apt-get update && \
    apt-get install -y g++ ttyd && \
    rm -rf /var/lib/apt/list/*

WORKDIR /app

COPY . .

RUN g++ -std=c++17 classes.cpp main.cpp -o program

EXPOSE 10000

CMD ["sh", "-c", "ttyd -p ${PORT:-10000} -w ./program"]


