## VENV 사용예제

### 예제 1: 기본 가상 환경 설정 및 활성화

가상 환경 생성<br/>

프로젝트 디렉토리를 생성하고, 해당 디렉토리 내에서 가상 환경을 생성합니다.<br/>
mkdir prj1<br/>
cd prj1<br/>
python3 -m venv myEnv<br/>
가상 환경 활성화<br/>

생성된 가상 환경을 활성화합니다. 활성화 후에는 이 환경 내에서 Python 및 pip 명령어가 가상 환경을 가리키게 됩니다.<br/>
macOS/Linux:<br/>
source myEnv/bin/activate<br/>
간단한 패키지 설치 및 실행<br/>
<br/>

가상 환경이 활성화된 상태에서 requests 패키지를 설치해봅니다.<br/>
bash<br/>
Copy code<br/>
pip install requests<br/>
Python 스크립트를 생성하여 requests를 사용해 간단한 HTTP 요청을 보내봅니다.<br/>
python<br/>
Copy code<br/>

### save this as test_requests.py
import requests<br/>

response = requests.get('https://api.github.com')<br/>
print(response.status_code)<br/>

<br/>스크립트 실행<br/>

다음 명령어를 통해 스크립트를 실행합니다.<br/>
python test_requests.py<br/>
가상 환경 비활성화<br/>

작업이 끝나면, 다음 명령어로 가상 환경을 비활성화합니다.<br/>
deactivate<br/>

-------------------------------------
### pip 설치법
sudo apt-get install python3-pip
### pip 업그레이드 방법
python -m pip install --upgrade pip
### pip 버전 확인 방법
pip --version

### virtualenv 설치법
python3 -m pip install --user -U virtualenv
### virtualenv 가상환경 만드는 방법
virtualenv env
### virtualenv 가상화 동작
source env/bin/activate
### virtualenv 가상화 멈춤
deactivate
