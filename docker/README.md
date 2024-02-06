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
