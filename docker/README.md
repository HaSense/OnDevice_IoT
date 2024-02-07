실습 1일차

- 윈도우 10 이상 도커 설치 방법
    - Windows 기능 켜기/끄기
        - Hyper-V 꼭 (빼기)
        - Linux용 Windows 하위 씨스템 (넣기)
        - 가상 머신 플랫폼 (넣기)

- 컨테이너 만들어서 실습시작
    - docker run -d -p 8080:80 --name cstudy001 httpd
- 컨테이너 확인
    - docker ps -a
- 컨테이너에 접속
    - docker exec -it cstudy001 bash
- vs 도커 확장팩
    - docker
    - Dev Container

실습 2일차

- gcc가 들어있는 공식 이미지를 받기
    - docker hub에서 gcc 이미지를 pull 한다.
    - docker pull gcc
- gcc가 있는 공식 이미지를 이용해 cstudy003을 실행하기
    - docker run —name cstudy003 -p 8082:80 gcc   (이렇게 실행하면 Exit가 되어버린다. 수정해야 한다.)
- Up이 안되고 Exit로 되어 있는 문제 해결하기
    - docker run —name cstudy003 -p 8082:80 -it gcc

- 도커파일 사용 (Dockerfile)
- FROM ubuntu:18.04
  RUN apt-get update                  //리눅스에 기본적인 설치 실행
  RUN apt-get install -y apache2     // -y로 모든 옵션에 Yes로 실행.
- 빌드 방법
  - docker build --tag mylinux[이미지이름] .
  - docker run -d -it -p 8083:80 --name cstudy007 mylinux /bin/bash
  - 
