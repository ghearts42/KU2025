#!/bin/bash

# 이 스크립트는 Hello, world!를 출력합니다
name="띕뮴낟"
export age=6974

echo "Hello, world! $name!"
echo "date : " `date` # 이 라인은 date 유틸리티를 실행합니다.

text="hello, world"
echo ${text:0:5}
echo ${text:7}

text="I like cats"
echo ${text/cats/dogs} # I like dogs

text="I like cats, I really love cats"
echo ${text//cats/dogs} # I like dogs, I really love dogs
echo ${#text}

# 중요함 unset env 환경 변수 초기화
# unset 환경변수

# read
echo "이름입력:"
read name
read -s -p "비번입력:" password
echo "입력이름 : $name"
echo "입력비번: $password"
export name=$name
./envTest

# 화면출력 echo, printf
echo -n "이어지는 " # 개행없음
echo "문장"
echo -e "엔터가 들어가는 \n 문장" # escape 작동 옵션
printf "이름 :%s, 나이: %d\n" "진떡팔" 87

# argument 받기 $1 $2 $# $@(중요)
echo "첫 인자 : $1"
echo "둘 인자 : $2"
echo "인자 수 : $#"
echo "총 인자 : $@"

#제어문 if then fi(endif)
read -p "나이:" age
if [ $age -lt 18 ]; then
    echo "안틀딱입니다"
elif [ $age -gt 70 ]; then
    echo "개틀딱입니다"
else
    echo "틀딱입니다"
fi

# 연산자 eq(==) ne(!=) gt(>) lt(<) ge(>=) le(<=)

# 문자 연산자 ==(같) !=(안같) z(길이가 0) n(길이가 0이 아님)

read -p "입력값 :" input
if [ -z "$input" ]; then
    echo "입력값 없음"
else
    echo "$input"
fi

# 논리연산 && || !

# switch case > case
read -p "과일 입력 :" fruit
case $fruit in
    "사과"|"딸기") echo "빨갱이";;
    "바나나"|"망고") echo "shfoddl";;
    *) echo "몰름";;
esac