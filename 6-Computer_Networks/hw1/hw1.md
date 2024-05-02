Programming HW 1: C 언어로 GBN 구현하기. –(team HW)
이번 program은 GBN ARQ mechanism을 이용하여 파일을 오류 없이 전송하는 program을 구현하 는 것입니다.
1. 실습에 사용하는 컴퓨터들의 구성은 다음과 같습니다.
- WAN emulator에서는 임의로 패킷을 버리고 (packet loss), 임의의 시간 지연을 부가하는 등의 기능을 수행합니다.
- 따라서 작성한 program을 실행시킬 때는 (만약 server program을 203.252.112.25에서 실 행시키고, client program은 203.252.112.26에서 실행시키고 있다면) client에서는 서버에 data를 보낼 때, 서버의 다른 IP address인 10.1.0.1로 data를 보내야 합니다. 그래야 해당 패킷이 WAN emulator를 통과하게 됩니다.
2. Socket program은 당연히 UDP를 사용하여야 하고, 오류가 발생하였을 때, 이를 복구하기 위 한 GBN ARQ mechanism을 구현하여야 합니다. GBN ARQ mechanism은 교재 그림 3.20과 3.21을 참조하여 구현하면 됩니다. (함수 이름은 그림 21/22에 나타난 것과 동일한 이름을 사 용할 필요는 없습니다.)
3. 파일의 크기는 대략 100 kB 이상이야 하고, client에서 한번에 보내는 데이터의 크기는 대략 500B 정도 단위로 하여야 한다. (즉 200개 이상의 메시지가 전달되어야 함.) (word로 임의의 파일을 만들어서 이를 사용하면 된다.)
4. 파일은 ASCII/binary 형태 모두 전송 가능해야 한다.
5. Server에 파일을 전송할 때, 첫 메시지로 반드시 fila name을 전송하여야 하고, 그 이름으로 server에서는 전송되는 파일을 저장하여야 한다.
6. Client와 server program에서는 GBN의 동작 상태를 debugging 하기 위한 적절한 메시지가 표시되게 하거나 debugging 메시지 없이 동작할 수 있도록 program을 작성하여야 한다.
 1

(program 실행 시에 주어진 argument에 따라 debugging message의 표시 여부를 선택할 수 있어야 한다.)
7. Client program에서는 server의 IP address, server port number, GBN의 SWS, debugging message on/off 여부를 arguments로 받아서 실행되도록 program을 작성하여야 한다. (SWS 는 10 이내로 주어질 수 있도록 하면 된다.)
8. Server program에서는 자신의 port number, debugging message on/off 여부를 arguments로 받아서 실행되도록 program을 작성하여야 한다.
9. File 전송이 끝나면 server에서 수신한 file 이 client file과 동일한 가를 확인하여라. (wc command 를 사용하면 된다.) 여러 번 실행을 하여 문제가 없는지 확인하여야 한다.
10. 작성한 program은 ~/hw1/server, ~/hw1/client 에 위치하도록 하면 된다. client directory에 전 송에 사용한 file에 위치시킴. (203.252.112.25와 26 컴퓨터에 어느 한 쪽에 server, 다른 쪽에 client 위치하도록 하면 됨.)
11. 결과물로는 설계한 protocol에 대한 설명과 함께 결과를 기술하면 됩니다.
- Header의 구조.
- 설계한 protocol 설명.(예를 들면 주고 받는 메시지 타입의 종류 및 구성. 파일 전송이 완 료되었다는 것을 어떻게 server에 알릴 수 있는가? 등등 )
- 사용한 timer와 동작.
- Program 동작 상태 및 결과를 기술하여야 함.