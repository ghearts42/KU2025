#!/bin/bash

#반복문

#for 변수 in 리스트; do
#   # 반복할 코드
# done

for name in "랍씜집" "키추장" "끙찼쑴"; do
    echo "이름 : $name"
done

echo "0~100 print"
for int in {0..10}; do
    echo -n "$int "
done

# while () sent1; sent2; --> while [ condition ]; do sent1; sent2; done
# until loop --> until [ condition ]; do sent1; sent2; done
# break continue... 비슷함

# 함수!! > argument X () X return X
function hello{
    local testInt=45
    globalInt="rmffhqjf"
    echo "우일석 $1맞죠?"
    return 3
}

hello "도리칸 등장"
echo "반환 값: $?"
echo "$testInt"

# 변수의 선언 > 모든 선언이 전역변수임 local을 선언하여 지역변수로 설정

# crontab cron :시간따라 쉘스크립트 실행함

