## VENV 사용예제

### 예제 1: 기본 가상 환경 설정 및 활성화
가상 환경 생성

프로젝트 디렉토리를 생성하고, 해당 디렉토리 내에서 가상 환경을 생성합니다.
bash
Copy code
mkdir prj1
cd prj1
python3 -m venv myEnv
가상 환경 활성화

생성된 가상 환경을 활성화합니다. 활성화 후에는 이 환경 내에서 Python 및 pip 명령어가 가상 환경을 가리키게 됩니다.
Windows:
bash
Copy code
.\my_venv\Scripts\activate
macOS/Linux:
bash
Copy code
source myEnv/bin/activate
간단한 패키지 설치 및 실행

가상 환경이 활성화된 상태에서 requests 패키지를 설치해봅니다.
bash
Copy code
pip install requests
Python 스크립트를 생성하여 requests를 사용해 간단한 HTTP 요청을 보내봅니다.
python
Copy code
# save this as test_requests.py
import requests

response = requests.get('https://api.github.com')
print(response.status_code)
스크립트 실행

다음 명령어를 통해 스크립트를 실행합니다.
bash
Copy code
python test_requests.py
가상 환경 비활성화

작업이 끝나면, 다음 명령어로 가상 환경을 비활성화합니다.
bash
Copy code
deactivate


### 예제 2: Flask 웹 애플리케이션
가상 환경 설정 및 활성화

위의 예제 1의 단계를 따라 가상 환경을 생성하고 활성화합니다.
Flask 설치

가상 환경이 활성화된 상태에서 Flask를 설치합니다.
bash
Copy code
pip install Flask
간단한 Flask 애플리케이션 생성

Flask 애플리케이션을 위한 Python 스크립트를 생성합니다.
python
Copy code
# save this as app.py
from flask import Flask
app = Flask(__name__)

@app.route('/')
def hello_world():
    return 'Hello, World!'

if __name__ == '__main__':
    app.run(debug=True)
애플리케이션 실행

다음 명령어로 Flask 애플리케이션을 실행합니다.
bash
Copy code
flask run
브라우저에서 http://127.0.0.1:5000/에 접속하여 결과를 확인합니다.
가상 환경 비활성화

작업이 끝나면, 가상 환경을 비활성화합니다.
이러한 실습 예제들은 Python 가상 환경의 기본적인 사용 방법을 익히는 데 도움이 됩니다. 가상 환경을 사용함으로써 프로젝트별로 필요한 패키지와 그 버전을 관리할 수 있어, 프로젝트의 독립성과 재현성을 보장할 수 있습니다.

pip로 request 모듈을 지우려면 remove 인가? 깨끗하게 지우는건 옵션이 따로 있나?
ChatGPT
Python의 패키지 관리자인 pip를 사용하여 설치된 패키지를 제거할 때는 uninstall 명령어를 사용합니다. requests 모듈을 제거하려면 다음과 같은 명령어를 사용하면 됩니다:

bash
Copy code
pip uninstall requests
이 명령어를 실행하면 pip는 requests 패키지와 그 의존성을 제거하려고 시도합니다. 하지만, requests 패키지가 다른 패키지에 의해 사용되고 있을 경우, 그 의존성은 자동으로 제거되지 않을 수 있습니다. pip는 설치된 패키지 간의 의존성을 관리하지만, 패키지를 제거할 때 모든 관련 의존성을 완벽하게 제거하는 기능은 제한적입니다.

깨끗하게 패키지 제거하기
패키지를 깨끗하게 제거하려면, 다음과 같은 접근 방법을 고려할 수 있습니다:

가상 환경 사용: 가상 환경을 사용하면, 필요하지 않게 된 의존성을 포함한 전체 환경을 간단히 제거할 수 있습니다. 가상 환경을 삭제함으로써 해당 환경에 설치된 모든 패키지와 설정을 깨끗하게 제거할 수 있습니다.

pip-autoremove 사용: pip-autoremove는 선택한 패키지와 그 불필요한 의존성을 제거할 수 있는 도구입니다. 이 도구는 기본적으로 pip에 포함되어 있지 않으므로, 별도로 설치해야 합니다.

bash
Copy code
pip install pip-autoremove
pip-autoremove requests -y
이 명령은 requests와 그 의존성을 제거합니다. -y 옵션은 모든 질문에 'yes'로 자동 응답하여 과정을 자동화합니다.

수동으로 의존성 확인 및 제거: 때로는 패키지의 의존성을 수동으로 확인하고 제거해야 할 필요가 있습니다. pip list 명령어를 사용하여 현재 설치된 패키지 목록을 확인하고, 더 이상 필요하지 않은 패키지를 pip uninstall 명령어로 개별적으로 제거할 수 있습니다.

패키지를 제거할 때는 해당 패키지가 시스템이나 다른 프로젝트에서 사용되지 않는지 주의 깊게 확인하는 것이 중요합니다. 가상 환경을 사용하는 것이 여러 프로젝트 간의 의존성 충돌을 방지하고, 시스템을 깨끗하게 유지하는 가장 좋은 방법 중 하나입니다.

리눅스에서 예를 들어 python.exe가 어디 있는지 찾는 명령어 which 맞나?
ChatGPT
네, 맞습니다. 리눅스 시스템에서 특정 실행 파일의 위치를 찾기 위해 which 명령어를 사용할 수 있습니다. 예를 들어, Python 인터프리터의 위치를 찾으려면 다음과 같이 명령어를 사용합니다:

bash
Copy code
which python
또는 Python 3.x 버전을 사용하고 있다면, 다음과 같이 입력할 수 있습니다:

bash
Copy code
which python3
이 명령어는 시스템의 $PATH 환경 변수에 지정된 디렉토리들을 검색하여, 주어진 실행 파일 이름(예: python 또는 python3)과 일치하는 첫 번째 경로를 출력합니다.

리눅스에서는 일반적으로 python.exe와 같은 .exe 확장자를 사용하지 않습니다. .exe 확장자는 주로 Windows 환경에서 실행 파일을 나타내는 데 사용됩니다. 리눅스와 같은 유닉스 기반 시스템에서는 실행 가능한 파일에 대해 특별한 확장자를 요구하지 않으며, 실행 권한이 중요합니다.

추가적으로, whereis 명령어를 사용하여 프로그램의 바이너리, 소스, 그리고 매뉴얼 페이지의 위치를 찾을 수도 있습니다. 예를 들어:

bash
Copy code
whereis python
이 명령어는 python과 관련된 여러 파일의 위치를 제공할 수 있으며, 이는 시스템 설정과 설치된 패키지에 따라 달라질 수 있습니다.
