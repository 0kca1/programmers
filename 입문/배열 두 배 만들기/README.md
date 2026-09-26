vector 쓸 거니까 라이브러리 불러오고
std:: 생략

정수형 벡터를 반환하는 solution 함수, 매개변수로 정수형 벡터 numbers를 받음
answer라는 정수형 벡터 선언

reserve로 numbers.size()만큼 공간만 미리 확보 (크기는 아직 0, 재할당 방지용)

for문으로 i = 0부터 size - 1까지 돌면서

numbers[i] * 2 값을 answer배열에 차례대로 push_back << 크기가 0이라 0번째 칸이 없음 그래서 answer[](인덱스)로 넣으면 에러
push_back으로 확보된 공간에 차례대로 push
  
answer 리턴
