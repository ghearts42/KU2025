# KU2025

KU Sejong C class

---

## 2025-03-04

---

- 첫 번째 변경 커밋입니다.

- 20250304

  - Vmware 설치
  - Ubuntu 22.04 설치
  - Github 계정 생성
  - Github 저장소 생성
  - Github 저장소 Clone

  - 프로그램 작성 nano (infinit.c)
  - nano 임의의코드파일명

  - C 언어 설명
  - 자료형
  - 숫자형 - 정수형, 실수형

  - 온도 예제 작성 celcius2fahr.c

  - makefile 작성
  - make 실행
  - char 설명 및 예제 작성 charNumber.c

---

## 2025-03-05

---

- 20250305

  - 연산자
  - 폰 노이만 머신
  - 메모리 연산

  - 연산자
    - 산술연산자 (+, -, \*, /, %)
    - 증감연산자 (++a, --a, a++, a--)
    - 대입연산자 (=)
    - 복합대입연산자 (+=, -=, \*=, /=, %=)
  - 리터럴 상수

    - 관계연산자 (<, <=, ==, !=, =>, >) : 출력 시 0 or 1만 출력 가능함
    - 논리연산자 (&&, ||, !)
    - 형변환연산자 ((type))
    - sizeof(값) : 넣은 값에 대한 자료형 크기를 출력함

  - 비트 연산자
    - &(AND)
    - |(OR)
    - ^ (XOR) : 명제가 하나만 참인 경우에만 1을 반환
    - <<(Left Shift)
    - > > (Right Shift)
    - ~(NOT)
  - 상수 : 일반적인 변수와 다르게 선언과 동시에 초기화해야 하며 데이터를 변경할 수 없는 변수
  - char상수 : 문자열 규칙 L"Hello, World!"
  - 지수 : 1.23e2 = 1.23 _ 10 ^ 2 , 1.23e-2 = 1.23 _ 10 ^ -2

  ## 2025-03-06

  - 흐름제어문 : 흐름(반복, 체크, 분기)을 제어하는 함수
    if문
    for문

  ## 2025-03-07

  - rand
  - 함수(function) : 반복적인 코드를 묶어 실행함

    - 전역변수 : 함수 밖에서 선언 (#define, #include)
    - 지역변수 : 함수 내부에서 선언하여 그 안에서만 사용 가능한 변수 (int a = 3 ... ) -정적지역변수 : 함수 내부에서 선언하지만 전역변수처럼 사용 가능

  - 배열(Array) 연속된 같은 Type의 자료
