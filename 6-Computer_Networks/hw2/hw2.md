# TCP chat program with select IO-multiplexing

---

> Programming HW 2: C 언어로 chatting program 구현하기. (team HW)
이번 program은 io-multiplexing 기법을 활용하여 chatting program을 구현하는 것입니다.
> 

---

### 조건

1. 실습에 사용하는 컴퓨터는 203.252.112.25/26 을 사용하면 됩니다.
2. Socket program은 TCP를 사용하면 됩니다.
3. Chatting에 참여하고자 하는 사람은 server에 접속한 다음, 자신의 nick-name을 server에 등
록한다. 그러면 server는 현재 chatting에 참여하고 있는 사람들에게 새로운 사람 (nick-name)
의 chatting 참여를 알려주어야 한다. 그리고 새로 참여한 사람에게 현재 참여하고 있는 사람
들의 모든 nick-name을 알려주어야 한다.
4. Chatting에 참여하고 있는 사용자가 빠져나가면, server는 이를 현재 참여하고 있는 나머지
사람들에게 알려주어야 한다.
5. 어떤 사람이 메시지를 입력하면 서버를 이 메시지를 받은 다음, 그 메시지 앞에 보낸 사람의
nick-name을 추가한 다음, 현재 참여하고 있는 나머지 사람들에게 메시지를 전달하여야 한다.
6. 언제든지 chatting에 참여할 수 있고, 또한 빠져 나갈 수 있어야 한다.
7. Server program에서는 자신의 port number를 arguments로 받아서 실행되도록 program을 작
성하여야 한다.
8. Client program은 server의 IP address, server의 port number, 자신의 nick-name을 arguments
로 받아서 실행되도록 program을 작성하여야 한다.
9. 작성한 program은 ~/hw2/server, ~/hw2/client 에 위치하도록 하면 된다. (203.252.112.25와
26 컴퓨터에 어느 한 쪽에 server, 다른 쪽에 client 위치하도록 하면 됨.)
10. 결과물로는 설계한 program의 동작을 설명하고, 여러가지 시나리오에 따른 동작의 결과에
대해서 기술하면 됩니다.

---

### 동작

- **client**
    1. argument가 지정된 것과 다를시 프로그램 종료
    2. socket 만들고 에러 출력
    3. server의 주소 만들고 연결, 에러 출력
    4. select를 위한 FD_SET
    5. 닉네임 전송
    6. 참여하는 모든 닉네임 받기
    7. 계속 실행하며
        1. select 시작
        2. FD_ISSET(0, &temps)로 입력이 있을 경우 입력 받아 보내기
        3. FD_ISSET(sock, &temps)로 들어온 소켓이 있을 경우
            1. read==0이면 연결 끊긴경우 출력
            2. 아니면 메세지이므로 출력
    8. sock 끊기
- **server**
    1. argument가 지정된 것과 다를시 프로그램 종료
    2. server의 주소 만들고 연결, 에러 출력
    3. socket 만들고 에러 출력
    4. select를 위한 FD_SET
    5. 계속 실행하며
        1. select 시작
        2. 여러 fd에 대해 검사하기 (multi-client)
            1. FD_ISSET(0, &temps)로 입력이 있을 경우
                1. fd==serv_sock인 경우 연결 요청
                2. 아니면 read로 메세지 받기
                    1. len이 0인경우 연결 끊김. 나간거 모두에게 알림
                    2. 아니면 메세지인데
                        1. 아직 닉네임 없던 fd면 처음이니 모두에게 알림
                        2. 있던 fd면 메세지로 출력

---

### 결과

### **. 여러 시나리오에서 Program 동작 결과**

1. **두 명의 클라이언트가 메세지를 하나씩 주고받는 경우**

[https://lh4.googleusercontent.com/rhO3hzJePe6yycgpxBDQGBu6s79RsKWaWaySLE7ven9cclDfFti6hgiKOSgmGkdB0ZmxKKMLSMjc3LQVmhq2u0dzI6YrlxyN2sUMu1rbZOeUMVow2dTdzWvFUPxeqdZpCM3a4fLW1uuzJ-v4SbqkuswTcQ8u2SXnoisLSVUnv4xIdA3YbzS5vK90ovEh5g](https://lh4.googleusercontent.com/rhO3hzJePe6yycgpxBDQGBu6s79RsKWaWaySLE7ven9cclDfFti6hgiKOSgmGkdB0ZmxKKMLSMjc3LQVmhq2u0dzI6YrlxyN2sUMu1rbZOeUMVow2dTdzWvFUPxeqdZpCM3a4fLW1uuzJ-v4SbqkuswTcQ8u2SXnoisLSVUnv4xIdA3YbzS5vK90ovEh5g)

[https://lh3.googleusercontent.com/ufivzICaZG3utqAe3fsGJ6zHsV2K9HdZqrnOzMKZi5cHKUwcN5CkwSq6CYh8hFi5ryZxRB5C_CTMzIZ1h8Pk0W__o5djntZN12vbNK1ap4gkPGXWGALT9dGtp1OBlRNRtXsRuEVvRbAcSkYJetjxjHTbuyV1T98RnVlzB7j3Qv1nOFKW6CASujtVF40UMg](https://lh3.googleusercontent.com/ufivzICaZG3utqAe3fsGJ6zHsV2K9HdZqrnOzMKZi5cHKUwcN5CkwSq6CYh8hFi5ryZxRB5C_CTMzIZ1h8Pk0W__o5djntZN12vbNK1ap4gkPGXWGALT9dGtp1OBlRNRtXsRuEVvRbAcSkYJetjxjHTbuyV1T98RnVlzB7j3Qv1nOFKW6CASujtVF40UMg)

[https://lh5.googleusercontent.com/xyxvSoqq1O5tjBigtM7aI2v1Y1iXii8MKeWy0bZtjuPi0lwTHwk0_ZIlv31yO2OnEa7369Izkrhqc-dwr10m2dO_yNs3a3ksWDUUX4pssdvOxx9FmgO5ffydLxN9NWB_2s6xB_MM4wXlYsoN8JhTt4dN7mUNociOZE0dOVdtYaCYmFM6nw43ZnPZPraPJQ](https://lh5.googleusercontent.com/xyxvSoqq1O5tjBigtM7aI2v1Y1iXii8MKeWy0bZtjuPi0lwTHwk0_ZIlv31yO2OnEa7369Izkrhqc-dwr10m2dO_yNs3a3ksWDUUX4pssdvOxx9FmgO5ffydLxN9NWB_2s6xB_MM4wXlYsoN8JhTt4dN7mUNociOZE0dOVdtYaCYmFM6nw43ZnPZPraPJQ)

- 왼쪽부터 순서대로 kim, min, 그리고 서버의 결과화면이다.
1. **두 명의 클라이언트가 연속으로 메세지를 주고받는 경우**

[https://lh4.googleusercontent.com/0_UlS3-Yi-Pk85nI8hFMn1Hld57OzhEOa_df4J8ltC6vWKYJ49KwcOyu_mxT2-UboiaIXOQuexTzpmDUbD4tTsxNx2jsP0buLfVk9aqmyboD8_p8DiI-jBKXq9mJUPSGv-5rFpPj6PAA42-fklWvn9SyuMmLgFX6SlCnrArYJrAAd2d_tUWtjQJGhpu_Ug](https://lh4.googleusercontent.com/0_UlS3-Yi-Pk85nI8hFMn1Hld57OzhEOa_df4J8ltC6vWKYJ49KwcOyu_mxT2-UboiaIXOQuexTzpmDUbD4tTsxNx2jsP0buLfVk9aqmyboD8_p8DiI-jBKXq9mJUPSGv-5rFpPj6PAA42-fklWvn9SyuMmLgFX6SlCnrArYJrAAd2d_tUWtjQJGhpu_Ug)

[https://lh3.googleusercontent.com/oaTzDkMgOt88R9z9F6EPRsfBk781umlF6TIFa43vCLFkUJoGAhwuyn5KJzxPg3UVnVRkEhI1-YES6mgmxpICel4ED79ERSPGa3nZVmjCzLbj0a_xkrbSdhesNNuogUgGdxbVMWRbRU-huCnx7ueWfBoclaJTH4SQ2Gq3lbQi-PtBHVSXhmRCALcgQv_QeQ](https://lh3.googleusercontent.com/oaTzDkMgOt88R9z9F6EPRsfBk781umlF6TIFa43vCLFkUJoGAhwuyn5KJzxPg3UVnVRkEhI1-YES6mgmxpICel4ED79ERSPGa3nZVmjCzLbj0a_xkrbSdhesNNuogUgGdxbVMWRbRU-huCnx7ueWfBoclaJTH4SQ2Gq3lbQi-PtBHVSXhmRCALcgQv_QeQ)

[https://lh4.googleusercontent.com/pV5hLxWj5Qc8sUKgxghzdsj4wNvUIv-wswtxBNkOPapK3JxJpg6XkFQ6sgMOYRhVO77FYCOHFkP9FvIEzy-BvP3MATe3e4Gvk6mytGMO67yUEf6TImCjAm5Xg3AKS5BdfO3E2ct_W5imL3k-xn8Es5hSmCzVCHW_cMX0aOoGLy9ptVhNDQKlim9yIF5kXQ](https://lh4.googleusercontent.com/pV5hLxWj5Qc8sUKgxghzdsj4wNvUIv-wswtxBNkOPapK3JxJpg6XkFQ6sgMOYRhVO77FYCOHFkP9FvIEzy-BvP3MATe3e4Gvk6mytGMO67yUEf6TImCjAm5Xg3AKS5BdfO3E2ct_W5imL3k-xn8Es5hSmCzVCHW_cMX0aOoGLy9ptVhNDQKlim9yIF5kXQ)

- 왼쪽부터 순서대로 kim, min, 그리고 서버의 결과화면이다.
1. **두 명의 클라이언트가 대화하는 도중 서버가 종료된 경우**

[https://lh3.googleusercontent.com/UY_uu4ing62-Q0LlP13pYSgT_peaJS91GC1TsETY67J3hGgfFNnxz6PK9zmmyUn-PsjgFpQTzaojS-zdl6SJ8gaHmbm--Q4bSyemxYsCa_i5lLTGitHZVREeTB99iu1vyq0n3KxCFltYQtN775XyJqOz9ai5zDbuu9UYxAlN7SBVG3ljB0uYbxB64Vm2Sg](https://lh3.googleusercontent.com/UY_uu4ing62-Q0LlP13pYSgT_peaJS91GC1TsETY67J3hGgfFNnxz6PK9zmmyUn-PsjgFpQTzaojS-zdl6SJ8gaHmbm--Q4bSyemxYsCa_i5lLTGitHZVREeTB99iu1vyq0n3KxCFltYQtN775XyJqOz9ai5zDbuu9UYxAlN7SBVG3ljB0uYbxB64Vm2Sg)

[https://lh5.googleusercontent.com/JSznoHFEOwidaGz56cB5qAE98_8eipSWHewvSp0jNdFSKBeBq-9oDsTjZnBs8Jx8ReKfs-w9qr8bi53pT4Wtx53lQN8KrPCEMe79SsGukYGqqQgz7LhaQlwhkrZqM5OZ9Dd3lZwPMy98dBSfN2qnCNkF7ItJ3ZJCDwmhfT8oKn_5Lln8tFS1HCfD7PqeRg](https://lh5.googleusercontent.com/JSznoHFEOwidaGz56cB5qAE98_8eipSWHewvSp0jNdFSKBeBq-9oDsTjZnBs8Jx8ReKfs-w9qr8bi53pT4Wtx53lQN8KrPCEMe79SsGukYGqqQgz7LhaQlwhkrZqM5OZ9Dd3lZwPMy98dBSfN2qnCNkF7ItJ3ZJCDwmhfT8oKn_5Lln8tFS1HCfD7PqeRg)

[https://lh3.googleusercontent.com/17ZzlgEnXFYQzQOQ2thpifgQ2jj949ZLvhfCNFo4Jo_Ox7dsWEsHP5st2pAPv5B0vAHZthzPVIQbU8_OJbzcQ5Fab8ePoP4bLNtWmBI2jZaqO7J1L3wYkLjIn2-eL2WxqxWz34RtGFmg-QNWbtEDYZ1szhD86c16nJg0BJZHoH862M_sCRYzHKve0iTsvg](https://lh3.googleusercontent.com/17ZzlgEnXFYQzQOQ2thpifgQ2jj949ZLvhfCNFo4Jo_Ox7dsWEsHP5st2pAPv5B0vAHZthzPVIQbU8_OJbzcQ5Fab8ePoP4bLNtWmBI2jZaqO7J1L3wYkLjIn2-eL2WxqxWz34RtGFmg-QNWbtEDYZ1szhD86c16nJg0BJZHoH862M_sCRYzHKve0iTsvg)

- 왼쪽부터 순서대로 kim, min, 그리고 서버의 결과화면이다.
1. **세 명의 클라이언트가 대화하다, 한명이 나간 후 나머지가 계속 대화하는 경우**

[https://lh6.googleusercontent.com/L9aQ5RpNsUDD8ClPwB_RxE_RtK90jYQeLgNStR67f0QX_p_eXV_Gmf5H74n1w16j7Q-8qKzrecf5Gi-x71ta5PqBLEesVxgOo6pQnqjZBr3QRyJRySU1ZUFlOhGShYgDEmVQTe1ZAGWdS3804LJ3LujsUDJRqjdqSbA-ZHB-GZH2M2j3jKNeKtO6YTmKBA](https://lh6.googleusercontent.com/L9aQ5RpNsUDD8ClPwB_RxE_RtK90jYQeLgNStR67f0QX_p_eXV_Gmf5H74n1w16j7Q-8qKzrecf5Gi-x71ta5PqBLEesVxgOo6pQnqjZBr3QRyJRySU1ZUFlOhGShYgDEmVQTe1ZAGWdS3804LJ3LujsUDJRqjdqSbA-ZHB-GZH2M2j3jKNeKtO6YTmKBA)

[https://lh5.googleusercontent.com/eBBbRyFRIx51v1hqJlNr7hQWXHPbW5OKN9oLlMSuD3R4AwfrOa2WIAz5C7XJpLIGAVOufanHdxnJlJmUlF9s-TxwrBkpPd59BciV0okSDwxDkAQ0slh3UOxsnabFYEy_Ix8xy-x4x62akfA3XXqBTeNY_goJcD2LgEKWdmy9yL0wzkKYz2BFvVaadijCQA](https://lh5.googleusercontent.com/eBBbRyFRIx51v1hqJlNr7hQWXHPbW5OKN9oLlMSuD3R4AwfrOa2WIAz5C7XJpLIGAVOufanHdxnJlJmUlF9s-TxwrBkpPd59BciV0okSDwxDkAQ0slh3UOxsnabFYEy_Ix8xy-x4x62akfA3XXqBTeNY_goJcD2LgEKWdmy9yL0wzkKYz2BFvVaadijCQA)

[https://lh5.googleusercontent.com/Kt_0ebUCP5H9z5DBJyzOia6Ny6Ele0APGz8-7SJkJTdmgI1KT57dPqrKMYiBF3edZljO1iRTS5MfQgPL9IIS3lzYFufe17Ls8ru4vmrlsJouIourk91g_twi7Mirbw1ILQPQiGJaG5Cpma3FDc2Hy3VOxtxPDK5Ta8nhuGaaGm1U26fOy6BUx07mdNOvxw](https://lh5.googleusercontent.com/Kt_0ebUCP5H9z5DBJyzOia6Ny6Ele0APGz8-7SJkJTdmgI1KT57dPqrKMYiBF3edZljO1iRTS5MfQgPL9IIS3lzYFufe17Ls8ru4vmrlsJouIourk91g_twi7Mirbw1ILQPQiGJaG5Cpma3FDc2Hy3VOxtxPDK5Ta8nhuGaaGm1U26fOy6BUx07mdNOvxw)

[https://lh5.googleusercontent.com/RjTSMz1_cJVtapdcmw_P_8aViX0oe5kd_uTUjWSL73cq7U-6UvvkH_aPrWuE-WfngS7F6t6Q8KliUN53jUMcWG1p3nTwQLHuD-JMHHOH84r3xsm6k3XwxQyd1G8GKQ2MhiVxfHCrsc6DccmK5UIxKd6BatGgRH4DmAMtEdbLNb7H5sh6357LE65he2Y87Q](https://lh5.googleusercontent.com/RjTSMz1_cJVtapdcmw_P_8aViX0oe5kd_uTUjWSL73cq7U-6UvvkH_aPrWuE-WfngS7F6t6Q8KliUN53jUMcWG1p3nTwQLHuD-JMHHOH84r3xsm6k3XwxQyd1G8GKQ2MhiVxfHCrsc6DccmK5UIxKd6BatGgRH4DmAMtEdbLNb7H5sh6357LE65he2Y87Q)

- 순서대로 kim, min, chae, 그리고 서버의 결과화면이다.   